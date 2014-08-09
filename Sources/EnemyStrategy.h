//
//  EnemyStrategy.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__EnemyStrategy__
#define __Karakuri2_Mac__EnemyStrategy__

#include "Karakuri.h"

class EAStrategy;
class SKEnemy;

// 名前を入れるだけでアルゴリズムを組むクラス

class EnemyStrategy{
    friend class EnemyFactory;
protected:
    EAStrategy* m_child;
public:
    EnemyStrategy();
    virtual ~EnemyStrategy();
    
public:
    // １フレームの敵の処理
    virtual void action(SKEnemy*) = 0;
    virtual void resetAction(SKEnemy*) = 0;
    
    EAStrategy* getChild() const;
};

#endif /* defined(__Karakuri2_Mac__EnemyStrategy__) */
