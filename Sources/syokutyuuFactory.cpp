//
//  syokutyuuFakutory.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "syokutyuuFactory.h"
#include "SKEnemy.h"
#include "EAStrategys.h"
#include "randam_dungeon.h"
#include <vector>

EAStrategy* syokutyuuFactory::create(SKEnemy* e, const char* nextName){
    std::string next;
    if(nextName) next = nextName;
    EAStrategy* st;
    if(!nextName){
        if(e->isSeeingPlayer()){
            st = new ESNomalMovePlayerLooking();
        }else{
            st = new ESNomalMoveInRoom();
            e->setExit(e->getRandomRoomExitMass());
        }
    }else if(next == "meeting_player"){
        st = new ESNomalAttack();
    }else if(next == "room"){
        st = new ESNomalMoveInRoom();
    }else if(next == "seeing_player"){
        st = new ESNomalMovePlayerLooking();
    }else if(next == "passage"){
        st = new ESNomalMoveInPassage();
    }else if(next == "destroy"){
        st = new ESDestroy();
    }else if(next == "sleep"){
        st = new ESSleep();
    }
    return st;
}