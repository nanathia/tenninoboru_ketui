//
//  ESESDestroy.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ESDestroy__
#define __Karakuri2_Mac__ESDestroy__

#include "Karakuri.h"
#include "EnemyStrategys.h"

class ESDestroy: public EAStrategy{
public:
    ESDestroy();
    ~ESDestroy();
    
    void action(SKEnemy*) override;
    const char* resetAction(SKEnemy*)override;
};

#endif /* defined(__Karakuri2_Mac__ESDestroy__) */
