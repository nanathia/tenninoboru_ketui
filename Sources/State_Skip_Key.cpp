//
//  State_Skip_Key.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "State_Skip_Key.h"
#include "State_Nomal_Key.h"


State_Skip_Key::State_Skip_Key(){
    
}

State_Skip_Key::~State_Skip_Key(){
    
}

State_Key* State_Skip_Key::update_key(GMInput* input, double deltaTime){
    State_Key* next = this;
    if(!input->isKeyDown(GMKeyMaskX)){
        next = new State_Nomal_Key();
    }
    
    // TODO: スキップキーの実装
    return next;
}