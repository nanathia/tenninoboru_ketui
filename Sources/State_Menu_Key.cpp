//
//  State_Menu_Key.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "State_Nomal_Key.h"
#include "State_W_Key.h"
#include "State_Skip_Key.h"
#include "State_Key_Not.h"
#include "State_Menu_Key.h"
#include "SaKumas_includes.h"


State_Menu_Key::State_Menu_Key(){
    
}

State_Menu_Key::~State_Menu_Key(){
    
}

State_Key* State_Menu_Key::update_key(GMInput* input, double deltaTime){
    State_Key* next = this;
    
    if(!gPlayScene->getUI()->isMenuOpen()){
        next = new State_Nomal_Key();
    }
    
    if(input->isKeyDown(GMKeyMaskUp)){
        SKKeyHandle::set(SKKeyHandle::key_up);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_up ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_up_once);
        }
    }
    if(input->isKeyDown(GMKeyMaskDown)){
        SKKeyHandle::set(SKKeyHandle::key_down);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_down ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_down_once);
        }
    }
    
    if(input->isKeyDown(GMKeyMaskRight)){
        SKKeyHandle::set(SKKeyHandle::key_right);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_right ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_right_once);
        }
    }
    
    if(input->isKeyDown(GMKeyMaskLeft)){
        SKKeyHandle::set(SKKeyHandle::key_left);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_left ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_left_once);
        }
    }
    
    if(input->isKeyDown(GMKeyMaskZ)){
        SKKeyHandle::set(SKKeyHandle::key_return);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_return ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_return_once);
        }
    }
    
    if(input->isKeyDown(GMKeyMaskX)){
        SKKeyHandle::set(SKKeyHandle::key_chancel);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_chancel ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_chancel_once);
        }
    }
    
    if(input->isKeyDown(GMKeyMaskM)){
        SKKeyHandle::set(SKKeyHandle::key_menu);
        if(SKKeyHandle::m_preFlags&SKKeyHandle::key_menu ? false : true){
            SKKeyHandle::set(SKKeyHandle::key_menu_once);
        }
    }
    
    return next;
}