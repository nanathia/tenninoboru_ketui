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
    
    WindowStateChild::WindowStateChild(Window*user):
    m_user(user){
    }
    WindowStateChild::~WindowStateChild(){
    }
    
    WindowInter::WindowInter(Window* user):
    WindowStateChild(user),
    m_time(0){
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
        m_user->setString(m_user->getChargeStrs().front());
        m_user->getChargeStrs().pop_front();
    }
    WindowVisible::~WindowVisible(){
    }
    WindowStateChild* WindowVisible::update(GMInput* input, double deltaTime){
        WindowStateChild* next = this;
        if(this->isAllCharacterStilled() && input->isKeyDownTriggered(GMKeyMaskReturn | GMKeyMaskZ | GMKeyMaskSpace)){
            if(m_user->getChargeStrs().empty()){
                next = new WindowOuter(m_user);
                m_user->allCharacterGoUnderLava();
            }else{
                m_user->allCharacterGoUnderLava();
            }
        }
        if(input->isKeyDownTriggered(GMKeyMaskS)){
            m_user->setString(m_user->getChargeStrs().back());
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
        return next;
    }
    void WindowOuter::draw(GMSpriteBatch* s){
        GMColor c = m_user->getColor();
        c.a = GMMath::Lerp(m_user->getColor().a, 0, m_time);
        s->draw(0, m_user->getRect(), c);
    };
    
    
}
