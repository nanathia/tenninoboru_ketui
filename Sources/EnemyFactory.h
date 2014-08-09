//
//  EnemyFactory.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__EnemyFactory__
#define __Karakuri2_Mac__EnemyFactory__

#include <string>
#include "EnemyStrategy.h"


class EnemyFactory{
public:
    EnemyStrategy* createStrategy(std::string& name, SKEnemy*);
};

#endif /* defined(__Karakuri2_Mac__EnemyFactory__) */
