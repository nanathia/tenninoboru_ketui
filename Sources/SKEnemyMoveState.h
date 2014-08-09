//
//  SKEnemyMoveState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/04.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEnemyMoveState__
#define __Karakuri2_Mac__SKEnemyMoveState__

#include "Karakuri.h"

class SKMass;
class SKEnemy;

namespace enemyMove{
    class MoveChild;
    
    class SKEnemyMoveState{
        MoveChild* m_state;
        SKEnemy* m_parent;
        SKMass* m_nextMass;
    public:
        SKEnemyMoveState(SKEnemy* parent);
        ~SKEnemyMoveState();
        SKMass* getNext();
    };
    
}

#endif /* defined(__Karakuri2_Mac__SKEnemyMoveState__) */
