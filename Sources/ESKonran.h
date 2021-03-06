//
//  ESKonran.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ESKonran__
#define __Karakuri2_Mac__ESKonran__

#include "Karakuri.h"
#include "EnemyStrategys.h"

class ESKonran: public EAStrategy{
public:
    ESKonran();
    ~ESKonran();
    
    void action(SKEnemy*) override;
    const char* resetAction(SKEnemy*)override;
};

#endif /* defined(__Karakuri2_Mac__ESKonran__) */
