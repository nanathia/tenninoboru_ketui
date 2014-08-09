//
//  SKTurnControl.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/01.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKTurnControl__
#define __Karakuri2_Mac__SKTurnControl__

#include <iostream>
#include "SKPlayerState.h"

namespace skturn{
    
////////////////////////////////////////////////////////////////////////////////////////
    
    // １ターンの概念
    class _turnChild{
    public:
        virtual void draw() = 0;
        
    public:
        _turnChild();
        virtual ~_turnChild();
    };
    
////////////////////////////////////////////////////////////////////////////////////////
    
    // 敵における１ターンの概念
    class _turnEnemy: public _turnChild{
    public:
        virtual void update(GMInput* input, double deltaTime) = 0;
        
        _turnEnemy();
        virtual ~_turnEnemy();
    };
    
    // 敵における１ターンの行動の概念
    class EnemyAction: public _turnEnemy{
        EnemyAction();
        virtual ~EnemyAction();
    };
    
    // 敵における１ターンの移動の概念
    class EnemyMove: public _turnEnemy{
    public:
        EnemyMove();
        virtual ~EnemyMove();
    };
    
////////////////////////////////////////////////////////////////////////////////////////
    
    // プレイヤーにおける１ターンの概念
    class _turnPlayer: public _turnChild{
    public:
        _turnPlayer();
        virtual ~_turnPlayer();
    };
    
    // プレイヤーにおける１ターンの行動の概念
    class PlayerAction: public _turnPlayer{
    public:
        PlayerAction();
        virtual ~PlayerAction();
    };
    
    // 移動の概念
    class PlayerMove: public _turnPlayer{
    public:
        PlayerMove();
        virtual ~PlayerMove();
    };
    
    // 攻撃について。
    class PlayerAttack: public PlayerAction{
    public:
        PlayerAttack();
        virtual ~PlayerAttack();
    };
    
    // 今のところ通常攻撃のみ
    class PlayerCloseRangeAttack: public PlayerAttack{
    public:
        PlayerCloseRangeAttack();
        virtual ~PlayerCloseRangeAttack();
    };
    
    // 遠距離攻撃
    class PlayerOpenRangeAttack: public PlayerAttack{
    public:
        PlayerOpenRangeAttack();
        virtual ~PlayerOpenRangeAttack();
    };
    
    
////////////////////////////////////////////////////////////////////////////////////////

    
    // 一周するターン管理クラス
    class SKTurnControl{
        std::list<_turnChild*> m_child;
    public:
        SKTurnControl();
        ~SKTurnControl();
    };
    
}

#endif /* defined(__Karakuri2_Mac__SKTurnControl__) */
