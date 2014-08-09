//
//  syokutyuu.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "syokutyuu.h"
#include "EAStrategy.h"
#include "syokutyuuFactory.h"
#include "ESNomalMoveInRoom.h"

syokutyuu::syokutyuu():
EnemyStrategy()
{
    this->m_child = new ESNomalMoveInRoom();
}

syokutyuu::~syokutyuu(){
    
}

void syokutyuu::resetAction(SKEnemy *e){
    const char* c;
    if((c = this->m_child->resetAction(e))){
        syokutyuuFactory fac;
        EAStrategy* ea = fac.create(e, c);
        delete m_child;
        m_child = ea;
    }
}

// １フレームの敵の処理
void syokutyuu::action(SKEnemy* e){
    m_child->action(e);
}