//
//  SKEnemyState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEnemyState__
#define __Karakuri2_Mac__SKEnemyState__

#include "Karakuri.h"

class SKEnemy;

namespace enemyState{

    class SKEnemyState{
    protected:
        double m_time;
        double m_animationTime;
        SKEnemy* m_user;
    public:
        SKEnemyState(SKEnemy* user);
        virtual ~SKEnemyState();
        virtual SKEnemyState* update(GMInput* input, double deltaTime, SKEnemy* enem) = 0;
        virtual void draw(int dx, int dy, SKEnemy* enem) = 0;
        
    };
    
//    class StanderdMove: public SKEnemyState{
//        
//    };
//    
//    class DoubleMove: public SKEnemyState{
//        
//    };
//    
//    class TripleMove: public SKEnemyState{
//        
//    };
    

}

#endif /* defined(__Karakuri2_Mac__SKEnemyState__) */
