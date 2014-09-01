//
//  DungeonSceneState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/09/01.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "DungeonSceneState.h"
#include "SaKumas_includes.h"
#include "SKSelectWindow.h"
#include "SKDungeonScene.h"
#include "JASpeakWindow.h"
#include "SKDrawFont.h"

namespace dungeonscenestate{
    
#pragma mark ---状態管理---
    DungeonSceneState::DungeonSceneState(SKDungeonScene* user):
    m_child(0){
        m_child = new DungeonSceneFloorShowingDungeonName(user);
    }
    DungeonSceneState::~DungeonSceneState(){
        delete m_child;
        m_child = 0;
    }
    void DungeonSceneState::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void DungeonSceneState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    void DungeonSceneState::nextFloor(){
        m_child->nextFloor();
    }
    
#pragma mark ---スーパー---
    DungeonSceneStateChild::DungeonSceneStateChild(SKDungeonScene*user):
    m_user(user){
    }
    DungeonSceneStateChild::~DungeonSceneStateChild(){
    }
    SKDungeonScene* DungeonSceneStateChild::getScene(){
        return m_user;
    }
    void DungeonSceneStateChild::nextFloor(){
        // Do nothing
        // 一応エラー処理
        throw GMException("error: goNextFloor while CurrentScene is not freeMove");
    }
    
#pragma mark ---状態1---
    DungeonSceneFloorInter::DungeonSceneFloorInter(SKDungeonScene* user):
    DungeonSceneStateChild(user),
    m_time(0){
    }
    DungeonSceneFloorInter::~DungeonSceneFloorInter(){
    }
    DungeonSceneStateChild* DungeonSceneFloorInter::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = new DungeonSceneFreeMove(m_user);
        }
        return next;
    }
    void DungeonSceneFloorInter::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        GMColor black = GMColor::Black;
        black.a = blue.a;
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        SKDrawFont::drawString(m_user->Name(), 60, GMVector2D(100, SCREEN_SIZE.y/2-30), 0, s, black);
    };
    
#pragma mark ---メインのプレイ状態---
    DungeonSceneFreeMove::DungeonSceneFreeMove(SKDungeonScene* user):
    DungeonSceneStateChild(user),
    m_isGoNextFloorReady(false){
    }
    DungeonSceneFreeMove::~DungeonSceneFreeMove(){
    }
    DungeonSceneStateChild* DungeonSceneFreeMove::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        
        m_user->getMassMan()->update();
        
        m_user->getPlayer()->objectUpdate(input, deltaTime);
        
        // そもそもプレイヤー以外は毎フレーム見る必要はない
        m_user->getEnemMan()->update_allEnemy(input, deltaTime);
        m_user->getItemMan()->update_allItem(input, deltaTime);
        m_user->getBlockMan()->update_allBlock(input, deltaTime);
        
        m_user->getUI()->updateUI(input, deltaTime);
        
        if(m_isGoNextFloorReady){
            next = new DungeonSceneIsGoNextFloor(m_user);
        }
        return next;
    }
    void DungeonSceneFreeMove::draw(GMSpriteBatch* s){
    };
    void DungeonSceneFreeMove::nextFloor(){
        m_isGoNextFloorReady = true;
    }
    
#pragma mark ---次の階層へ行く時のブラインド---
    DungeonSceneFloorOuter::DungeonSceneFloorOuter(SKDungeonScene* user):
    DungeonSceneStateChild(user),
    m_time(0){
    }
    DungeonSceneFloorOuter::~DungeonSceneFloorOuter(){
        m_user->getMassMan()->nextFloor();
    }
    DungeonSceneStateChild* DungeonSceneFloorOuter::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = new DungeonSceneFloorShowingDungeonName(m_user);
        }
        return next;
    }
    void DungeonSceneFloorOuter::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = m_time;
        GMColor black = GMColor::Black;
        black.a = blue.a;
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        SKDrawFont::drawString(m_user->Name(), 60, GMVector2D(100, SCREEN_SIZE.y/2-30), 0, s, black);
    };
    
#pragma mark ---リザルト画面---
    DungeonSceneResult::DungeonSceneResult(SKDungeonScene* user):
    DungeonSceneStateChild(user){
    }
    DungeonSceneResult::~DungeonSceneResult(){
    }
    DungeonSceneStateChild* DungeonSceneResult::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        return next;
    }
    void DungeonSceneResult::draw(GMSpriteBatch* s){
    };
    
#pragma mark ---ダンジョンでの立ち絵会話シーン---
    DungeonSceneEvent::DungeonSceneEvent(SKDungeonScene* user):
    DungeonSceneStateChild(user){
    }
    DungeonSceneEvent::~DungeonSceneEvent(){
    }
    DungeonSceneStateChild* DungeonSceneEvent::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        return next;
    }
    void DungeonSceneEvent::draw(GMSpriteBatch* s){
    };
    
#pragma mark ---次の階層へ行くかどうかを聞く---
    DungeonSceneIsGoNextFloor::DungeonSceneIsGoNextFloor(SKDungeonScene* user):
    DungeonSceneStateChild(user),
    m_questionWin(0),
    m_JaSpkWin(0){
        m_JaSpkWin = new JASpeakWindow::Window;
        m_JaSpkWin->addString("階段ね。漸次の階層へ進んでいいかしら？", question_isEnable);
    }
    DungeonSceneIsGoNextFloor::~DungeonSceneIsGoNextFloor(){
        delete m_JaSpkWin;
        m_JaSpkWin = 0;
        if(m_questionWin) delete m_questionWin;
        m_questionWin = 0;
    }
    DungeonSceneStateChild* DungeonSceneIsGoNextFloor::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        m_JaSpkWin->update(input, deltaTime);
        if(m_questionWin){
            if(selectWindow::Element* sel = m_questionWin->update(input, deltaTime)){
                if(sel->getLabel() == "いいよ"){
                    next = new DungeonSceneFloorOuter(m_user);
                }else if(sel->getLabel() == "まだ"){
                    next = new DungeonSceneFreeMove(m_user);
                }else if(sel->getLabel() == "今何階？"){
                    
                }
                delete m_questionWin;
                m_questionWin = 0;
                m_JaSpkWin->setKey(-1);
            }
        }else{
            if(m_JaSpkWin->getKey() == question_isEnable && input->isKeyDownTriggered(GMKeyMaskZ|GMKeyMaskReturn)){
                m_questionWin = new selectWindow::Window;
                selectWindow::Element* elems[] = {
                    new selectWindow::Element(m_questionWin),
                    new selectWindow::Element(m_questionWin),
                    new selectWindow::Element(m_questionWin),
                };
                elems[0]->setLabel("いいよ");
                elems[1]->setLabel("まだ");
                elems[2]->setLabel("今何階？");
                selectWindow::Carsor* carsor = new selectWindow::Carsor(m_questionWin);
                elems[0]->setCarsor(carsor);
                m_questionWin->setCarsor(carsor);
                for(int i = 0; i < 3; i++){
                    elems[0]->setRect(GMRect2D(SCREEN_SIZE.x/2-100, 500-50*i, 50, 50));
                    m_questionWin->addElement(elems[i]);
                }
            }
        }
        return next;
    }
    void DungeonSceneIsGoNextFloor::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = 0.5;
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        if(m_questionWin) m_questionWin->draw(s);
        m_JaSpkWin->draw(s);
    };
    
#pragma mark ---ダンジョン名と階層を表示---
    DungeonSceneFloorShowingDungeonName::DungeonSceneFloorShowingDungeonName(SKDungeonScene* user):
    DungeonSceneStateChild(user),
    m_time(0){
    }
    DungeonSceneFloorShowingDungeonName::~DungeonSceneFloorShowingDungeonName(){
    }
    DungeonSceneStateChild* DungeonSceneFloorShowingDungeonName::update(GMInput* input, double deltaTime){
        DungeonSceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 3){
            next = new DungeonSceneFloorInter(m_user);
        }
        return next;
    }
    void DungeonSceneFloorShowingDungeonName::draw(GMSpriteBatch* s){
        s->fill(GMRect2D(0, SCREEN_SIZE), GMColor::Blue);
        SKDrawFont::drawString(m_user->Name(), 60, GMVector2D(100, SCREEN_SIZE.y/2-30), 0, s, GMColor::Black);
    };
    
}
