//
//  BaseAreaPlayerAngleState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/23.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaPlayerAngleState.h"
#include "SKTextureManager.h"
#include "SKMusicManager.h"
#include "SKSoundManager.h"
#include "BaseAreaSouces.h"

namespace baseArea{
    
    PlayerAngleState::PlayerAngleState(Player* user):
    m_child(0){
        m_child = new PlayerBottomAngle(user);
    }
    PlayerAngleState::~PlayerAngleState(){
        delete m_child;
        m_child = 0;
    }
    void PlayerAngleState::update(GMInput* input, double deltaTime){
        PlayerAngleStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void PlayerAngleState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    
    PlayerAngleStateChild::PlayerAngleStateChild(Player*user, double time):
    m_user(user),
    m_time(time){
    }
    PlayerAngleStateChild::~PlayerAngleStateChild(){
    }
    
    PlayerLeftAngle::PlayerLeftAngle(Player* user):
    PlayerAngleStateChild(user){
    }
    PlayerLeftAngle::~PlayerLeftAngle(){
    }
    PlayerAngleStateChild* PlayerLeftAngle::update(GMInput* input, double deltaTime){
        PlayerAngleStateChild* next = this;
        if(!input->isKeyDown(GMKeyMaskLeft)){
            if(input->isKeyDown(GMKeyMaskDown)){
                next = new PlayerBottomAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskRight)){
                next = new PlayerRightAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskUp)){
                next = new PlayerTopAngle(m_user);
            }
        }
        m_time += deltaTime;
        if(m_time >= 1){
            m_time = 0;
        }
        return next;
    }
    void PlayerLeftAngle::draw(GMSpriteBatch* s){
        PlayerDraw::draw(s, m_user, m_time>=0.5?PlayerDraw::chipName_left1:PlayerDraw::chipName_left2);
    };
    
    PlayerRightAngle::PlayerRightAngle(Player* user):
    PlayerAngleStateChild(user){
    }
    PlayerRightAngle::~PlayerRightAngle(){
    }
    PlayerAngleStateChild* PlayerRightAngle::update(GMInput* input, double deltaTime){
        PlayerAngleStateChild* next = this;
        if(!input->isKeyDown(GMKeyMaskRight)){
            if(input->isKeyDown(GMKeyMaskLeft)){
                next = new PlayerLeftAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskDown)){
                next = new PlayerBottomAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskUp)){
                next = new PlayerTopAngle(m_user);
            }
        }
        m_time += deltaTime;
        if(m_time >= 1){
            m_time = 0;
        }
        return next;
    }
    void PlayerRightAngle::draw(GMSpriteBatch* s){
        PlayerDraw::draw(s, m_user, m_time>=0.5?PlayerDraw::chipName_right1:PlayerDraw::chipName_right2);
    };
    
    PlayerTopAngle::PlayerTopAngle(Player* user):
    PlayerAngleStateChild(user){
    }
    PlayerTopAngle::~PlayerTopAngle(){
    }
    PlayerAngleStateChild* PlayerTopAngle::update(GMInput* input, double deltaTime){
        PlayerAngleStateChild* next = this;
        if(!input->isKeyDown(GMKeyMaskUp)){
            if(input->isKeyDown(GMKeyMaskLeft)){
                next = new PlayerLeftAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskRight)){
                next = new PlayerRightAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskDown)){
                next = new PlayerBottomAngle(m_user);
            }
        }
        m_time += deltaTime;
        if(m_time >= 1){
            m_time = 0;
        }
        return next;
    }
    void PlayerTopAngle::draw(GMSpriteBatch* s){
        PlayerDraw::draw(s, m_user, m_time>=0.5?PlayerDraw::chipName_up1:PlayerDraw::chipName_up2);
    };
    
    PlayerBottomAngle::PlayerBottomAngle(Player* user):
    PlayerAngleStateChild(user){
    }
    PlayerBottomAngle::~PlayerBottomAngle(){
    }
    PlayerAngleStateChild* PlayerBottomAngle::update(GMInput* input, double deltaTime){
        PlayerAngleStateChild* next = this;
        if(!input->isKeyDown(GMKeyMaskDown)){
            if(input->isKeyDown(GMKeyMaskLeft)){
                next = new PlayerLeftAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskRight)){
                next = new PlayerRightAngle(m_user);
            }else if(input->isKeyDown(GMKeyMaskUp)){
                next = new PlayerTopAngle(m_user);
            }
        }
        m_time += deltaTime;
        if(m_time >= 1){
            m_time = 0;
        }
        return next;
    }
    void PlayerBottomAngle::draw(GMSpriteBatch* s){
        PlayerDraw::draw(s, m_user, m_time>=0.5?PlayerDraw::chipName_down1:PlayerDraw::chipName_down2);
    };
    
}
