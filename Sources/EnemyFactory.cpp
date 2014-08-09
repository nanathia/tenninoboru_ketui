//
//  EnemyFactory.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "EnemyFactory.h"
#include "syokutyuuFactory.h"
#include "EnemyStrategys.h"
#include "EAStrategys.h"
#include "SaKumas_includes.h"

EnemyStrategy* EnemyFactory::createStrategy(std::string& name, SKEnemy* enem){
    EnemyStrategy* strategy = 0;
    
    if(name == "syokutyuu"){
        strategy = new syokutyuu();
        strategy->m_child = syokutyuuFactory().create(enem, 0);
        enem->setName("食虫植物");
    }
    else if(name == "dokubati"){
        strategy = new dokubati();
        //TODO: 毒蜂の初期化の実装
    }
    else if(name == "mamusi"){
        strategy = new mamusi();
        //TODO: 蝮の初期化の実装
    }
    
    return strategy;
}