//
//  SyokutyuuState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SyokutyuuState__
#define __Karakuri2_Mac__SyokutyuuState__

#include "SKEnemyState.h"
class SKMass;
class SKMoveObject;

// 食虫植物
namespace enemyState{

    class SyokutyuuAttack: public SKEnemyState{
    public:
        SyokutyuuAttack();
        ~SyokutyuuAttack();
        SKEnemyState* update(GMInput* input, double deltaTime, SKEnemy* enem) override;
        void draw(int dx, int dy, SKEnemy* enem) override;
    };
    
    class SyokutyuuLeady: public SKEnemyState{
    public:
        SyokutyuuLeady();
        ~SyokutyuuLeady();
        SKEnemyState* update(GMInput* input, double deltaTime, SKEnemy* enem) override;
        void draw(int dx, int dy, SKEnemy* enem) override;
    };
    
    class SyokutyuuMove: public SKEnemyState{
        SKMass* m_start;
        SKMass* m_end;
    public:
        SyokutyuuMove(SKMass* start, SKMass* end);
        ~SyokutyuuMove();
        SKEnemyState* update(GMInput* input, double deltaTime, SKEnemy* enem) override;
        void draw(int dx, int dy, SKEnemy* enem) override;
    };
    
    class SyokutyuuDamage: public SKEnemyState{
    public:
        SyokutyuuDamage();
        ~SyokutyuuDamage();
        SKEnemyState* update(GMInput* input, double deltaTime, SKEnemy* enem) override;
        void draw(int dx, int dy, SKEnemy* enem) override;
    };
    
    class SyokutyuuSimetukeru: public SKEnemyState{
    public:
        SyokutyuuSimetukeru();
        ~SyokutyuuSimetukeru();
        SKEnemyState* update(GMInput* input, double deltaTime, SKEnemy* enem) override;
        void draw(int dx, int dy, SKEnemy* enem) override;
    };
    
}

#endif /* defined(__Karakuri2_Mac__SyokutyuuState__) */
