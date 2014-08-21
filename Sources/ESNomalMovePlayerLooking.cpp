//
//  ESNomalMovePlayerLooking.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/14.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ESNomalMovePlayerLooking.h"
#include "SKDungeonScene.h"

ESNomalMovePlayerLooking::ESNomalMovePlayerLooking():
ESMove()
{
    
}

ESNomalMovePlayerLooking::~ESNomalMovePlayerLooking(){
    
}

const char* ESNomalMovePlayerLooking::resetAction(SKEnemy *parent){
    const char* next = 0;
    
    if(parent->isMeetingPlayer()){
        next = "meeting_player";
    }else if(!parent->isSeeingPlayer()){
        next = "room";
        SKMass* mass = gPlayScene->getDungeonScene()->getPlayer()->getExit();
        if(!mass) mass = parent->getRandomRoomExitMass();
        parent->setExit(mass);
    }else if(!parent->getMass()->getRoom()){
        next = "passage";
    }
    
    return next;
}

void ESNomalMovePlayerLooking::action(SKEnemy* parent){
    parent->move(gPlayScene->getDungeonScene()->getPlayer());
}