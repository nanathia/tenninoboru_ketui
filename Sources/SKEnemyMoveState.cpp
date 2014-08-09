//
//  SKEnemyMoveState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/04.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKEnemyMoveState.h"
#include "SKEnemyMoveChild.h"
#include "SaKumas_includes.h"

namespace enemyMove{

    SKEnemyMoveState::SKEnemyMoveState(SKEnemy* e):
    m_state(0),
    m_parent(e){
        m_state = new MoveLeady(e);
    }
    SKEnemyMoveState::~SKEnemyMoveState(){
    }
    SKMass* SKEnemyMoveState::getNext(){
        MoveChild* nextState = m_state->updateNext(m_nextMass);
        if(nextState != m_state){
            delete m_state;
            m_state = nextState;
            nextState = 0;
        }
        return m_nextMass;
    }

}

