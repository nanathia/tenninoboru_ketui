//
//  ESNomalMovePlayerLooking.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/14.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ESNomalMovePlayerLooking__
#define __Karakuri2_Mac__ESNomalMovePlayerLooking__

#include "Karakuri.h"
#include "EAStrategy.h"
#include "ESMove.h"

class ESNomalMovePlayerLooking: public ESMove{
    
public:
    ESNomalMovePlayerLooking();
    ~ESNomalMovePlayerLooking();
    
    void action(SKEnemy*) override;
    const char* resetAction(SKEnemy*)override;
};

#endif /* defined(__Karakuri2_Mac__ESNomalMovePlayerLooking__) */
