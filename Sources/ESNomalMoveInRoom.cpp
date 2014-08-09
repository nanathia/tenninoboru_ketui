//
//  ESNomalMoveInRoom.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ESNomalMoveInRoom.h"
#include "SaKumas_includes.h"

ESNomalMoveInRoom::ESNomalMoveInRoom():
ESMove()
{
    
}

ESNomalMoveInRoom::~ESNomalMoveInRoom(){
    
}

const char* ESNomalMoveInRoom::resetAction(SKEnemy *parent){
    const char* next = 0;
    
    if(parent->isMeetingPlayer()){
        next = "meeting_player";
    }else if(parent->isSeeingPlayer()){
        next = "seeing_player";
    }else if(!parent->getMass()->getRoom()){
        next = "passage";
    }
    
    return next;
}

void ESNomalMoveInRoom::action(SKEnemy* parent){
    
    if(parent->getExit() == parent->getMass()){
        SKMass* mass = parent->getPassasgeInterMass();
        if(mass) parent->move(mass);
    }else{
        parent->move(parent->getExit());
    }
    
}