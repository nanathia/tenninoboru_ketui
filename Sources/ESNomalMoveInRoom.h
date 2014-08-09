//
//  ESNomalMoveInRoom.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ESNomalMoveInRoom__
#define __Karakuri2_Mac__ESNomalMoveInRoom__

#include "Karakuri.h"
#include "EnemyStrategys.h"
#include "ESMove.h"

class ESNomalMoveInRoom: public ESMove{
    
public:
    ESNomalMoveInRoom();
    ~ESNomalMoveInRoom();
    
    void action(SKEnemy*) override;
    const char* resetAction(SKEnemy*)override;
};

#endif /* defined(__Karakuri2_Mac__ESNomalMoveInRoom__) */
