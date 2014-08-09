//
//  State_W_Key.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "State_W_Key.h"
#include "State_Nomal_Key.h"
#include "SKKeyHandler.h"


State_W_Key::State_W_Key(){
}

State_W_Key::~State_W_Key(){
    
}

State_Key* State_W_Key::update_key(GMInput* input, double deltaTime){
    State_Key* next = this;
    
    bool up = input->isKeyDown(GMKeyMaskUp);
    bool down = input->isKeyDown(GMKeyMaskDown);
    bool right = input->isKeyDown(GMKeyMaskRight);
    bool left = input->isKeyDown(GMKeyMaskLeft);
    
    
    if(up && right){
        if(!(SKKeyHandle::m_preFlags&SKKeyHandle::key_right_up)){
            SKKeyHandle::m_flags |= (SKKeyHandle::key_up_once | SKKeyHandle::key_right_once);
        }
        SKKeyHandle::m_flags |= SKKeyHandle::key_right_up;
    }else if(down && right){
        if(!(SKKeyHandle::m_preFlags&SKKeyHandle::key_right_down)){
            SKKeyHandle::m_flags |= (SKKeyHandle::key_down_once | SKKeyHandle::key_right_once);
        }
        SKKeyHandle::m_flags |= SKKeyHandle::key_right_down;
    }else if(up && left){
        if(!(SKKeyHandle::m_preFlags&SKKeyHandle::key_left_up)){
            SKKeyHandle::m_flags |= (SKKeyHandle::key_up_once | SKKeyHandle::key_left_once);
        }
        SKKeyHandle::m_flags |= SKKeyHandle::key_left_up;
    }else if(down && left){
        if(!(SKKeyHandle::m_preFlags&SKKeyHandle::key_left_down)){
            SKKeyHandle::m_flags |= (SKKeyHandle::key_down_once | SKKeyHandle::key_left_once);
        }
        SKKeyHandle::m_flags |= SKKeyHandle::key_left_down;
    }
    
    if(!input->isKeyDown(GMKeyMaskW)){
        next = new State_Nomal_Key();
    }
    return next;
}