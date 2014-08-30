//
//  SKEnemy.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEnemy__
#define __Karakuri2_Mac__SKEnemy__

#include "Karakuri.h"
#include "SKObject.h"
#include "SKMoveObject.h"
#include "EnemyStrategys.h"

class State_Enemy;
class SKMass;
namespace enemyState{
    class SKEnemyState;
}
namespace enemyMove {
    class SKEnemyMoveState;
}
class EnemyStrategy;
class SKDungeonScene;

class SKEnemy : public SKMoveObject{
protected:
    enemyState::SKEnemyState* m_state;
    unsigned m_flags;
    // 行動トリガー ０で無、１で移動、２でその他行動。
    int m_isAction;
    // 行動中フラグ
    bool m_isSameAct;
    // 移動の移譲
    enemyMove::SKEnemyMoveState* m_move;
    
public:
    // 状態フラグ
    enum enemy_flags{
        state_poison =      1<<0,
        state_mahi =        1<<1,
        state_donsoku =     1<<2,
        state_muteki =      1<<3,
        state_kanasibari =  1<<4,
        state_migawari =    1<<5,
        state_baisoku =     1<<6,
        state_dead =        1<<7,
    };
        
public:
    
    // 外部からの操作関数
    void setMove();
    void setAction();
    bool isMove();
    bool isAction();
    void resetMoveOrAction();
    void setEnt(const char* name);
    
    // 行動中フラグに関して
    void doAct();
    bool isDoing();
    void doEnd();
    
    // 移動に関して
    enemyMove::SKEnemyMoveState* getMove();
    
    static SKMass* virtualMove(SKMass* pos, int x, int y, int falseCounter = 0);
    // プレイヤーが視界範囲にいるか
    bool isSeeingPlayer();
    // プレイヤーに隣接しているか
    bool isMeetingPlayer();
    // フラグ関係
    // フラグが立っているか
    bool isFlag(enemy_flags) const;
    // フラグを立てる
    void upFlag(unsigned flag);
    // フラグを下げる
    void downFlag(unsigned flag);
    // フラグを全て下げる。
    void clearFlag();
    
    // 攻撃関係
    // このオブジェクトに攻撃する
    void attackReaction(SKObject* attackSKObject);
    // 現在のストラテジーを取得
    EnemyStrategy* getStrategy() const;
    // プレイヤーと同じ部屋かどうか
    bool isSameRoomWithPlayer();
    // 通常移動出来るマスを取得
    SKMass* isNomalMoveMass(SKMass* mass);
    // 一足飛びの位置にプレイヤーが居るかどうか
    SKMass* isOneStepAttackToPlayer();
    // 障害物を考えずに、どの方向がプレイヤーに近いか
    SKMass* isNearestPlayerMass();
    // 方向取得
    double getRadianForMass(SKMass* mass);
    // 進行できる通路を取得
    SKMass* getPassasgeInterMass();
    // 敵が塞いでいる通路を返す。
    SKMass* getPassageInterMassOnMoveObject();
    
public:
    void objectInit(GMGraphics* g) override;
    static SKEnemy* createRandomEnemy(SKDungeonScene* scene);
    
    SKEnemy(SKDungeonScene* scene);
    virtual ~SKEnemy();
};


#endif /* defined(__Karakuri2_Mac__SKEnemy__) */
