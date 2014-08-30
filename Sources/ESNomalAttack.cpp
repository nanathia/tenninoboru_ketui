//
//  ESNomalAttack.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ESNomalAttack.h"
#include "SKDungeonScene.h"

ESNomalAttack::ESNomalAttack():
EAStrategy()
{
    
}

ESNomalAttack::~ESNomalAttack(){
    
}

const char* ESNomalAttack::resetAction(SKEnemy *parent){
    const char* next = 0;
    
    if(!parent->isMeetingPlayer()){
        next = "seeing_player";
    }
    
    return next;
}

void ESNomalAttack::action(SKEnemy* parent){
    
//    parent->setSKObjectAngle(m_scene->getPlayer()->getMass());
    
}