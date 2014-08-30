//
//  SKEnemyChild.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKEnemyChild.h"
#include "SaKumas_includes.h"
#include "SKEnemyState.h"
#include "SyokutyuuState.h"
#include "SKDrawFont.h"
#include <sstream>

namespace enemyChild{

    syokutyuu::syokutyuu(SKDungeonScene* scene):
    SKEnemy(scene){
        this->setName("食虫植物");
        m_hp = 100;
    }
    syokutyuu::~syokutyuu(){
        
    }
    bool syokutyuu::objectUpdate(GMInput* input, double deltaTime){
        enemyState::SKEnemyState* next = m_state->update(input, deltaTime, this);
        if(next != m_state){
            delete m_state;
            m_state = next;
            next = 0;
        }
        if(this->isFlag(state_dead)){
            return true;
        }
        return false;
    }
    void syokutyuu::objectDraw(int d_x, int d_y){
        m_state->draw(d_x, d_y, this);
    }

}