//
//  SKKeyHandler.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKKeyHandler.h"
#include "State_W_Key.h"
#include "State_Key.h"
#include "State_Nomal_Key.h"

State_Key* SKKeyHandle::m_state = 0;
SKKeyHandle* SKKeyHandle::m_instance = 0;

unsigned SKKeyHandle::m_flags = 0;
unsigned SKKeyHandle::m_preFlags = 0;

bool SKKeyHandle::isUpdate(){
    return m_flags&key_playerAction ? true: false;
}

bool SKKeyHandle::isMenu(){
    bool returnFlag = m_flags & key_menu_once ? true : false;
    if(returnFlag){
        down(key_menu_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isReturn(){
    bool returnFlag = m_flags & key_return_once ? true : false;
    if(returnFlag){
        down(key_return_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isChancel(){
    bool returnFlag = m_flags & key_chancel_once ? true : false;
    if(returnFlag){
        down(key_chancel_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isRight(){
    bool returnFlag = m_flags & key_right_once ? true : false;
    if(returnFlag){
        down(key_right_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isLeft(){
    bool returnFlag = m_flags & key_left_once ? true : false;
    if(returnFlag){
        down(key_left_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isUp(){
    bool returnFlag = m_flags & key_up_once ? true : false;
    if(returnFlag){
        down(key_up_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isDown(){
    bool returnFlag = m_flags & key_down_once ? true : false;
    if(returnFlag){
        down(key_down_once);
    }
    return returnFlag;
}

bool SKKeyHandle::isMoveEnd(){
    return m_flags & key_moveEnd ? true: false;
}

void SKKeyHandle::down(unsigned keyFlag){
    m_flags &= ~keyFlag;
}

void SKKeyHandle::KeyFlag_update(GMInput* input, double deltaTime){
    m_preFlags = m_flags;
    m_flags = 0;
}

void SKKeyHandle::set(unsigned keyFlag){
    m_flags |= keyFlag;
};


void SKKeyHandle::create(){
    if(m_instance){
        throw "キークラスの二重初期化";
    }
    m_instance = new SKKeyHandle();
}

void SKKeyHandle::destroy(){
    delete m_instance;
    m_instance = 0;
}

SKKeyHandle::SKKeyHandle(){
    m_state = new State_Nomal_Key();
}

SKKeyHandle::~SKKeyHandle(){
    delete m_state;
    m_state = 0;
}