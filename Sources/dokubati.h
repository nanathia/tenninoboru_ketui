//
//  dokubati.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//
#pragma once

#include "Karakuri.h"
#include "SaKumas_includes.h"

#include "EnemyStrategy.h"

class dokubati: public EnemyStrategy{
public:
    dokubati();
    ~dokubati();
    
public:
    // １フレームの敵の処理
    void resetAction(SKEnemy*) override;
    void action(SKEnemy*) override;
};