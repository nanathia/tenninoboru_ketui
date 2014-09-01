//
//  SKMapSelectSceneState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/30.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSceneState.h"
#include "MapSelectSources.h"
#include "JASpeakWindow.h"
#include "SKSelectWindow.h"
#include "ResourceManagerSources.h"
#include "SKPlayScene.h"
#include "SKBaseAreaScene.h"
#include <sstream>

namespace mapSelect{
    
    SceneState::SceneState(SKMapSelectScene* user):
    m_child(0){
        m_child = new CarsorMove(user);
    }
    SceneState::~SceneState(){
        delete m_child;
        m_child = 0;
    }
    void SceneState::update(GMInput* input, double deltaTime){
        SceneStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void SceneState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    void SceneState::changeSelect(){
        m_child->changeSelect();
    }
    void SceneState::changeBaseAreaReady(){
        m_child->changeBaseAreaReady();
    }
    bool SceneState::isChangeAreaReady() const{
        return m_child->isChangeAreaReady();
    }
    
    SceneStateChild::SceneStateChild(SKMapSelectScene*user):
    m_user(user){
    }
    SceneStateChild::~SceneStateChild(){
    }
    bool SceneStateChild::isChangeAreaReady() const{
        return false;
    }
    
    CarsorMove::CarsorMove(SKMapSelectScene* user):
    SceneStateChild(user),
    m_is2BaseAreaReady(false){
    }
    CarsorMove::~CarsorMove(){
    }
    SceneStateChild* CarsorMove::update(GMInput* input, double deltaTime){
        SceneStateChild* next = this;
        if(m_is2BaseAreaReady){
            next = new MapInterYesOrNo(m_user);
        }
        return next;
    }
    void CarsorMove::draw(GMSpriteBatch* s){
    }
    void CarsorMove::changeBaseAreaReady(){
        m_is2BaseAreaReady = true;
    }
    void CarsorMove::changeSelect(){
        // Do notting
    }
    
    MapInterYesOrNo::MapInterYesOrNo(SKMapSelectScene* user):
    m_time(0),
    SceneStateChild(user),
    m_is2Select(false),
    m_questionWin(0){
        std::ostringstream oss;
        oss << m_user->getCarsor()->getCurrentObj()->Name() << "漸へ移動するわよ。いい？";
        m_user->getJaSpkWin()->addString(oss.str().c_str(), 99);
    }
    MapInterYesOrNo::~MapInterYesOrNo(){
        delete m_questionWin;
        m_questionWin = 0;
    }
    SceneStateChild* MapInterYesOrNo::update(GMInput* input, double deltaTime){
        SceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            m_time = 1;
        }
        if(m_questionWin){
            if(selectWindow::Element* select = m_questionWin->update(input, deltaTime)){
                if(select->getLabel() == "いいよ"){
                    m_user->getJaSpkWin()->addString("じゃあ、移動するわ。", select_ChangeArea);
                }else if(select->getLabel() == "やめとく"){
                    m_user->getJaSpkWin()->addString("そう。", select_backAreaSelect);
                }else if(select->getLabel() == "ねえ、そこってどんな場所？"){
                    m_user->getJaSpkWin()->addString("未実装よー", select_BackCarsorSelect);
                }
                m_user->getJaSpkWin()->setKey(-1);
                delete m_questionWin;
                m_questionWin = 0;
            }
        }else{
            if(m_user->getJaSpkWin()->getKey() == select_BackCarsorSelect && input->isKeyDownTriggered(GMKeyMaskZ|GMKeyMaskReturn)){
                m_user->getJaSpkWin()->setKey(99);
            }else if(m_user->getJaSpkWin()->getKey() == select_backAreaSelect && input->isKeyDownTriggered(GMKeyMaskZ|GMKeyMaskReturn)){
                m_user->getJaSpkWin()->setKey(-1);
                next = new CarsorMove(m_user);
            }else if(m_user->getJaSpkWin()->getKey() == select_ChangeArea && input->isKeyDownTriggered(GMKeyMaskZ|GMKeyMaskReturn)){
                m_user->getJaSpkWin()->setKey(-1);
                gPlayScene->changeScene(new baseArea::SKBaseAreaScene(m_user->getCarsor()->getCurrentObj()->Name()));
            }else if(m_user->getJaSpkWin()->getKey() == 99){
                m_questionWin = new selectWindow::Window;
                selectWindow::Element* elems[] = {
                    new selectWindow::Element(m_questionWin),
                    new selectWindow::Element(m_questionWin),
                    new selectWindow::Element(m_questionWin),
                };
                elems[0]->setLabel("いいよ");
                elems[1]->setLabel("やめとく");
                elems[2]->setLabel("ねえ、そこってどんな場所？");
                selectWindow::Carsor* carsor = new selectWindow::Carsor(m_questionWin);
                m_questionWin->setCarsor(carsor);
                elems[0]->setCarsor(carsor);
                for(int i = 0; i < 3; i++){
                    elems[i]->setRect(GMRect2D(SCREEN_SIZE.x/2-200, SCREEN_SIZE.y-50-i*50, 650, 50));
                    m_questionWin->addElement(elems[i]);
                }
                m_user->getJaSpkWin()->setKey(-1);
            }else if(m_is2Select){
                next = new CarsorMove(m_user);
            }
        }
        return next;
    }
    void MapInterYesOrNo::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = m_time/3;
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        if(m_questionWin) m_questionWin->draw(s);
    };
    void MapInterYesOrNo::changeBaseAreaReady(){
        // Do notting
    }
    void MapInterYesOrNo::changeSelect(){
        m_is2Select = true;
    }
    bool MapInterYesOrNo::isChangeAreaReady() const{
        return true;
    }
    
}
