//
//  syokutyuu.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#pragma once

#include "EnemyStrategy.h"

class syokutyuu: public EnemyStrategy
{
public:
    syokutyuu();
    ~syokutyuu();
    
public:
    // １フレームの敵の処理
    void resetAction(SKEnemy*) override;
    void action(SKEnemy*) override;
};
