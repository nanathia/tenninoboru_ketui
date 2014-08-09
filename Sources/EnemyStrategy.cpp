//
//  EnemyStrategy.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "EnemyStrategy.h"
#include "EAStrategy.h"

EnemyStrategy::EnemyStrategy():
m_child(0)
{
    
}

EnemyStrategy::~EnemyStrategy(){
    delete m_child;
    m_child = 0;
}

EAStrategy* EnemyStrategy::getChild() const{
    return m_child;
};