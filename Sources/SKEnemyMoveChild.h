//
//  SKEnemyMoveChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/04.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEnemyMoveChild__
#define __Karakuri2_Mac__SKEnemyMoveChild__

#include "Karakuri.h"
#include "SKEnemyMoveState.h"

class SKEnemy;
class SKMass;

// 一歩も動けない状態以外は、何かしらの移動を返す。
// 一歩も動けない状態＝＝０を返却する。

namespace enemyMove{
    
    class MoveChild{
    protected:
        SKEnemy* m_parent;
    public:
        MoveChild(SKEnemy* e);
        virtual ~MoveChild();
        virtual MoveChild* updateNext(SKMass*& nextMass) = 0;
    };
    
    // ターゲットが何も設定されていない状態。（開始時、閉じ込められている時、ワープ直後、等。
    class MoveLeady: public MoveChild{
    public:
        MoveLeady(SKEnemy* e);
        ~MoveLeady();
        MoveChild* updateNext(SKMass*& nextMass) override;
    };
    
    class MoveRoom: public MoveChild{
        SKMass* m_exitMass;
    public:
        MoveRoom(SKEnemy* e, SKMass* targetRoomExit);
        ~MoveRoom();
        MoveChild* updateNext(SKMass*& nextMass) override;
    };
    
    class MoveChace: public MoveChild{
    public:
        MoveChace(SKEnemy* e);
        ~MoveChace();
        MoveChild* updateNext(SKMass*& nextMass) override;
    };
    
    class MovePassage: public MoveChild{
        double m_angle;
    public:
        MovePassage(SKEnemy* e, SKMass*& angleMass);
        ~MovePassage();
        MoveChild* updateNext(SKMass*& nextMass) override;
    };
    
}

#endif /* defined(__Karakuri2_Mac__SKEnemyMoveChild__) */
