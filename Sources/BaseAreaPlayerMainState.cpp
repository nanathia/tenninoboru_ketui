//
//  BaseAreaPlayerMainState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaPlayerMainState.h"
#include "SpeakStrManager.h"
#include "SKSpeakWindow.h"
#include "BaseAreaSouces.h"

namespace baseArea{
    
    PlayerMainState::PlayerMainState(Player* user):
    m_child(0),
    m_user(user){
        m_child = new PlayerStateFreeMove(user);
    }
    PlayerMainState::~PlayerMainState(){
        delete m_child;
        m_child = 0;
    }
    void PlayerMainState::update(GMInput* input, double deltaTime){
        PlayerMainStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void PlayerMainState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    bool PlayerMainState::isSpeak() const{
        return m_child->isSpeak();
    }
    void PlayerMainState::speak(baseArea::Murabito *mura){
        delete m_child;
        m_child = new PlayerStateSpeakHuman(mura, m_user);
    }
    
    PlayerMainStateChild::PlayerMainStateChild(Player*user):
    m_user(user){
    }
    PlayerMainStateChild::~PlayerMainStateChild(){
    }
    bool PlayerMainStateChild::isSpeak() const{
        return false;
    }
    
    PlayerStateFreeMove::PlayerStateFreeMove(Player* user):
    PlayerMainStateChild(user){
    }
    PlayerStateFreeMove::~PlayerStateFreeMove(){
    }
    PlayerMainStateChild* PlayerStateFreeMove::update(GMInput* input, double deltaTime){
        PlayerMainStateChild* next = this;
        // 一秒間で、何マス動くかをここで指定
        double speed = deltaTime*4;
        GMRect2D tempRect(m_user->Rect());
        if(input->isKeyDown(GMKeyMaskUp)){
            tempRect.y += speed;
        }
        if(input->isKeyDown(GMKeyMaskDown)){
            tempRect.y -= speed;
        }
        if(input->isKeyDown(GMKeyMaskDown)^input->isKeyDown(GMKeyMaskUp)){
            if(m_user->getBaseAreaScene()->getMap()->getTileLayerMan()->isCollision(tempRect) || m_user->getBaseAreaScene()->getMap()->getMurabitoMan()->isCollision(tempRect)){
                tempRect.y = m_user->Rect().y;
            }
        }
        if(input->isKeyDown(GMKeyMaskRight)){
            tempRect.x += speed;
        }
        if(input->isKeyDown(GMKeyMaskLeft)){
            tempRect.x -= speed;
        }
        if(input->isKeyDown(GMKeyMaskLeft)^input->isKeyDown(GMKeyMaskRight)){
            if(m_user->getBaseAreaScene()->getMap()->getTileLayerMan()->isCollision(tempRect) || m_user->getBaseAreaScene()->getMap()->getMurabitoMan()->isCollision(tempRect)){
                tempRect.x = m_user->Rect().x;
            }
        }
        m_user->setRect(tempRect);
        return next;
    }
    void PlayerStateFreeMove::draw(GMSpriteBatch* s){
    };
    
    PlayerStateSpeakHuman::PlayerStateSpeakHuman(Murabito* mura, Player* user):
    PlayerMainStateChild(user),
    m_speakPerson(mura){
        SKSpeakWindow::Window* win = m_user->getBaseAreaScene()->getNomalSpeakWin();
        while(!mura->getSpeak()->isEnd()){
            win->addString(mura->getSpeak()->getSpeak());
            mura->getSpeak()->goNext();
        }
        mura->getSpeak()->reset();
    }
    PlayerStateSpeakHuman::~PlayerStateSpeakHuman(){
    }
    PlayerMainStateChild* PlayerStateSpeakHuman::update(GMInput* input, double deltaTime){
        PlayerMainStateChild* next = this;
        if(m_user->getBaseAreaScene()->getNomalSpeakWin()->isAllEnd()){
            next = new PlayerStateFreeMove(m_user);
        }
        return next;
    }
    void PlayerStateSpeakHuman::draw(GMSpriteBatch* s){
    }
    bool PlayerStateSpeakHuman::isSpeak() const{
        return true;
    }
    
    PlayerStateSirabaruAny::PlayerStateSirabaruAny(Player* user):
    PlayerMainStateChild(user){
    }
    PlayerStateSirabaruAny::~PlayerStateSirabaruAny(){
    }
    PlayerMainStateChild* PlayerStateSirabaruAny::update(GMInput* input, double deltaTime){
        PlayerMainStateChild* next = this;
        return next;
    }
    void PlayerStateSirabaruAny::draw(GMSpriteBatch* s){
    };
    
    
}

