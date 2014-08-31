//
//  MapSelectSceneCarsorState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSceneCarsorState.h"
#include "MapSelectSources.h"
#include "ResourceManagerSources.h"


namespace mapSelect{
    // 共通定義
    namespace{
        const GMVector2D carsorSize(50);
    }
    
#pragma mark ---管理---
    SelectCarsorState::SelectCarsorState(SelectObj* firstObj, SelectCarsor* user):
    m_child(0){
        m_child = new SelectCarsorBehind(firstObj, user);
    }
    SelectCarsorState::~SelectCarsorState(){
        delete m_child;
        m_child = 0;
    }
    void SelectCarsorState::update(GMInput* input, double deltaTime){
        SelectCarsorStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void SelectCarsorState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    }
    SelectObj* SelectCarsorState::getCurrentObj(){
        return m_child->getSelectObj();
    }
    
#pragma mark ---スーパー---
    SelectCarsorStateChild::SelectCarsorStateChild(SelectCarsor*user):
    m_user(user){
    }
    SelectCarsorStateChild::~SelectCarsorStateChild(){
    }
    SelectCarsor* SelectCarsorStateChild::getCarsor(){
        return m_user;
    }
    
#pragma mark ---カーソル停滞中---
    namespace selectcarsorbehind{
        SelectCarsorBehindState::SelectCarsorBehindState(SelectCarsorBehind* user):
        m_child(0){
            m_child = new SelectCarsorBehindEnableInput(user);
        }
        SelectCarsorBehindState::~SelectCarsorBehindState(){
            delete m_child;
            m_child = 0;
        }
        void SelectCarsorBehindState::update(GMInput* input, double deltaTime){
            SelectCarsorBehindStateChild* nextChild = m_child->update(input, deltaTime);
            if(nextChild != m_child){
                delete m_child;
                m_child = nextChild;
            }
        }
        void SelectCarsorBehindState::draw(GMSpriteBatch* s){
            m_child->draw(s);
        };
        
        SelectCarsorBehindStateChild::SelectCarsorBehindStateChild(SelectCarsorBehind*user):
        m_user(user){
        }
        SelectCarsorBehindStateChild::~SelectCarsorBehindStateChild(){
        }
        // 入力可
        SelectCarsorBehindEnableInput::SelectCarsorBehindEnableInput(SelectCarsorBehind* user):
        SelectCarsorBehindStateChild(user){
        }
        SelectCarsorBehindEnableInput::~SelectCarsorBehindEnableInput(){
        }
        SelectCarsorBehindStateChild* SelectCarsorBehindEnableInput::update(GMInput* input, double deltaTime){
            SelectCarsorBehindStateChild* next = this;
            if(input->isKeyDown(GMKeyMaskDown|GMKeyMaskRight)){
                m_user->changeState(new SelectCarsorMove(m_user->getObj(), m_user->getObj()->getNext(), m_user->getCarsor()));
            }else if(input->isKeyDown(GMKeyMaskLeft|GMKeyMaskUp)){
                m_user->changeState(new SelectCarsorMove(m_user->getObj(), m_user->getObj()->getPrev(), m_user->getCarsor()));
            }else if(input->isKeyDownTriggered(GMKeyMaskZ|GMKeyMaskReturn)){
                m_user->getCarsor()->getScene()->ChangeBaseAreaReady();
                next = new SelectCarsorBehindDisableInput(m_user);
            }
            return next;
        }
        void SelectCarsorBehindEnableInput::draw(GMSpriteBatch* s){
        };
        // 入力不可
        SelectCarsorBehindDisableInput::SelectCarsorBehindDisableInput(SelectCarsorBehind* user):
        SelectCarsorBehindStateChild(user){
        }
        SelectCarsorBehindDisableInput::~SelectCarsorBehindDisableInput(){
        }
        SelectCarsorBehindStateChild* SelectCarsorBehindDisableInput::update(GMInput* input, double deltaTime){
            SelectCarsorBehindStateChild* next = this;
            if(!m_user->getCarsor()->getScene()->isChangeAreaReady()) next = new SelectCarsorBehindEnableInput(m_user);
            return next;
        }
        void SelectCarsorBehindDisableInput::draw(GMSpriteBatch* s){
        };
    }
    SelectCarsorBehind::SelectCarsorBehind(SelectObj* obj, SelectCarsor* user):
    SelectCarsorStateChild(user),
    m_obj(obj),
    m_state(0),
    m_nextState(0){
        obj->setCarsor(m_user);
        m_state = new selectcarsorbehind::SelectCarsorBehindState(this);
    }
    SelectCarsorBehind::~SelectCarsorBehind(){
        delete m_state;
        m_state = 0;
    }
    SelectCarsorStateChild* SelectCarsorBehind::update(GMInput* input, double deltaTime){
        SelectCarsorStateChild* next = this;
        m_state->update(input, deltaTime);
        if(m_nextState) next = m_nextState;
        return next;
    }
    void SelectCarsorBehind::draw(GMSpriteBatch* s){
        GMTexture2D* tex = m_user->getScene()->getTexMan()->get(SKMapSelectScene::texName_Carsor);
        s->draw(tex, GMRect2D(m_obj->Rect().x, m_obj->Rect().y, carsorSize.x, carsorSize.y), GMRect2D(0, tex->getSize()), GMColor::White, 0, 0, GMSpriteFlipHorizontally);
    }
    SelectObj* SelectCarsorBehind::getObj(){
        return m_obj;
    }
    void SelectCarsorBehind::changeState(SelectCarsorStateChild* next){
        m_nextState = next;
    }
    SelectObj* SelectCarsorBehind::getSelectObj(){
        return m_obj;
    }
    
#pragma mark ---カーソル移動中---
    SelectCarsorMove::SelectCarsorMove(SelectObj* prev, SelectObj* next, SelectCarsor* user):
    m_time(0),
    m_prevObj(prev),
    m_nextObj(next),
    SelectCarsorStateChild(user){
        m_prevObj->setCarsor(0);
    }
    SelectCarsorMove::~SelectCarsorMove(){
        m_nextObj->setCarsor(m_user);
    }
    SelectCarsorStateChild* SelectCarsorMove::update(GMInput* input, double deltaTime){
        SelectCarsorStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = new SelectCarsorBehind(m_nextObj, m_user);
        }
        return next;
    }
    void SelectCarsorMove::draw(GMSpriteBatch* s){
        GMTexture2D* tex = m_user->getScene()->getTexMan()->get(SKMapSelectScene::texName_Carsor);
        GMVector2D pre(m_prevObj->Rect().x, m_prevObj->Rect().y);
        GMVector2D nex(m_nextObj->Rect().x, m_nextObj->Rect().y);
        GMRect2D dest(GMVector2D::EaseInOut(pre, nex, m_time), carsorSize);
        s->draw(tex, dest, GMRect2D(0, tex->getSize()), GMColor::White, 0, 0, GMSpriteFlipHorizontally);
    }
    SelectObj* SelectCarsorMove::getSelectObj(){
        return 0;
    }
    
}

