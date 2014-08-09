//
//  SKEnemyChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEnemyChild__
#define __Karakuri2_Mac__SKEnemyChild__

#include "Karakuri.h"
#include "SKEnemy.h"

namespace enemyChild{

    class syokutyuu: public SKEnemy{
    public:
        syokutyuu();
        ~syokutyuu();
        bool objectUpdate(GMInput* input, double deltaTime) override;
        void objectDraw(int d_x, int d_y) override;
    };
    
    class suiryuu: public SKEnemy{
        suiryuu();
        ~suiryuu();
    };
    
    class dokubati: public SKEnemy{
        dokubati();
        ~dokubati();
    };
    
    class ookami: public SKEnemy{
        ookami();
        ~ookami();
    };
    
}

#endif /* defined(__Karakuri2_Mac__SKEnemyChild__) */
