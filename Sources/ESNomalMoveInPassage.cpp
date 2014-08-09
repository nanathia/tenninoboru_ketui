//
//  ESNomalMoveInPassage.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ESNomalMoveInPassage.h"

ESNomalMoveInPassage::ESNomalMoveInPassage():
ESMove()
{
    
}

ESNomalMoveInPassage::~ESNomalMoveInPassage(){
    
}

const char* ESNomalMoveInPassage::resetAction(SKEnemy *parent){
    const char* next = 0;
    
    if(parent->getMass()->getRoom()){
        if(parent->isSeeingPlayer()){
            next = "seeing_player";
        }else{
            next = "room";
            parent->setExit(parent->getRandomRoomExitMass());
        }
    }
    
    return next;
}

void ESNomalMoveInPassage::action(SKEnemy* parent){

    SKMass* mass = parent->getMass();
    parent->move();
    if(parent->getMass() == mass){
        // ぶつかって移動できていない場合
        SKMass* mass_ = 0;
        if((mass_ = parent->getBestTargetMass())){
            parent->move(mass_);
        }else{
//            GMException("むううー");
        }
    }
    
}