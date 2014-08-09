//
//  ESNomalAttack.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ESNomalAttack__
#define __Karakuri2_Mac__ESNomalAttack__

#include "Karakuri.h"
#include "EnemyStrategys.h"

class ESNomalAttack: public EAStrategy{
public:
    ESNomalAttack();
    ~ESNomalAttack();
    
    void action(SKEnemy*) override;
    const char* resetAction(SKEnemy*)override;
};

#endif /* defined(__Karakuri2_Mac__ESNomalAttack__) */
