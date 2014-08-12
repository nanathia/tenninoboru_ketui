//
//  JASpeakWindowState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "JASpeakWindowState.h"
#include "JASpeakWindow.h"
#include "JASpeakCharacter.h"

namespace JASpeakWindow{
    
    WindowState::WindowState(Window* user):
    m_child(0){
        m_child = new WindowInter(user);
    }
    WindowState::~WindowState(){
        delete m_child;
        m_child = 0;
    }
    void WindowState::update(GMInput* input, double deltaTime){
        WindowStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void WindowState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    bool WindowState::isAllCharacterStilled(){
        return m_child->isAllCharacterStilled();
    }
    
    WindowStateChild::WindowStateChild(Window*user):
    m_user(user){
    }
    WindowStateChild::~WindowStateChild(){
    }
    bool WindowStateChild::isAllCharacterStilled(){
        return false;
    }
    
    WindowInter::WindowInter(Window* user):
    WindowStateChild(user),
    m_time(0){
    }
    WindowInter::WindowInter(Window* user, double time):
    WindowStateChild(user),
    m_time(time){
    }
    WindowInter::~WindowInter(){
    }
    WindowStateChild* WindowInter::update(GMInput* input, double deltaTime){
        WindowStateChild* next = this;
        m_time += deltaTime/3;
        if(m_time >= 1){
            next = new WindowVisible(m_user);
        }
        return next;
    }
    void WindowInter::draw(GMSpriteBatch* s){
        GMColor c = m_user->getColor();
        c.a = GMMath::Lerp(0, m_user->getColor().a, m_time);
        s->draw(0, m_user->getRect(), c);
    };
    
    WindowVisible::WindowVisible(Window* user):
    WindowStateChild(user){
        if(!m_user->getChargeStrs().empty()){
            m_user->setString(m_user->getChargeStrs().front().getStr());
            m_user->setNextReturnKey(m_user->getChargeStrs().front().getQuota());
            m_user->getChargeStrs().pop_front();
        }
    }
    WindowVisible::~WindowVisible(){
    }
    WindowStateChild* WindowVisible::update(GMInput* input, double deltaTime){
        WindowStateChild* next = this;
        if(this->isAllCharacterStilled()){
            m_user->setReturnKey();
            if(input->isKeyDownTriggered(GMKeyMaskReturn | GMKeyMaskZ | GMKeyMaskSpace)){
                if(m_user->getChargeStrs().empty()){
                    next = new WindowOuter(m_user);
                    m_user->setReturnKey();
                    m_user->allCharacterGoUnderLava();
                }else{
                    m_user->setReturnKey();
                    m_user->allCharacterGoUnderLava();
                }
            }
        }
        return next;
    }
    void WindowVisible::draw(GMSpriteBatch* s){
        s->draw(0, m_user->getRect(), m_user->getColor());
    };
    bool WindowVisible::isAllCharacterStilled(){
        int size = (int)m_user->getCharacters().size();
        for(int i = 0; i < size; i++){
            if(!m_user->getCharacters()[i]->isStill()){
                return false;
            }
        }
        return true;
    }
    
    WindowOuter::WindowOuter(Window* user):
    WindowStateChild(user),
    m_time(0){
    }
    WindowOuter::~WindowOuter(){
    }
    WindowStateChild* WindowOuter::update(GMInput* input, double deltaTime){
        WindowStateChild* next = this;
        m_time += deltaTime/3;
        if(m_time >= 1){
            m_time = 1;
        }
        if(!m_user->getChargeStrs().empty()){
            next = new WindowInter(m_user, 1-m_time);
        }
        return next;
    }
    void WindowOuter::draw(GMSpriteBatch* s){
        GMColor c = m_user->getColor();
        c.a = GMMath::Lerp(m_user->getColor().a, 0, m_time);
        s->draw(0, m_user->getRect(), c);
    };
    
}
