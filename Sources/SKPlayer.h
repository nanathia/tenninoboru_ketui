//
//  SKPlayer.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKPlayer__
#define __Karakuri2_Mac__SKPlayer__

#include "Karakuri.h"
#include "SKObject.h"
#include "ScmlObject.h"
#include "SKMoveObject.h"
#include "SKPlayerState.h"
#include <list>
#include <vector>
using namespace std;

class PlayerPorch;
class _turnControl;
class CallBack;
class SwordItem;
class ShieldItem;
class UdewaItem;
class EpuipmentItem;
class SKDungeonScene;

class SKPlayer : public SKMoveObject{
    friend class PlayerLeady;
    friend class PlayerChoiceAngle;
    friend class PlayerNanameInput;
    friend class PlayerPorch;
    friend class PlayerWait;
    friend class PlayerOpenMenu;
    friend class PlayerMoving;
    
    bool m_isItemSelectEnd;
    std::vector<SKMass*> m_walked_way;
    SKMass* m_exitMass;
    spriter::ScmlObject* m_animation;
    PlayerPorch* m_porch;
    SKPlayerState* m_state;

    _turnControl* m_turnControl;
    
    // 装備品
    SwordItem* m_equipmentSword;
    ShieldItem* m_equipmentShield;
    UdewaItem* m_equipmentUdewa_1;
    UdewaItem* m_equipmentUdewa_2;
    
    // 行動中
    bool m_isAct;
    
public:
    SKPlayer(SKDungeonScene* parent);
    ~SKPlayer();
    
public:
    bool objectUpdate(GMInput* input, double deltaTime) override;
    void objectInit(GMGraphics* g) override;
    
    void objectDraw(int d_x, int d_y) override;
    
    // 移動元を取得
    SKMass* getPreviousMass() const;
    // 部屋を出たマスを取得
    SKMass* getExitEntrance() const;
    
    // 階層移動処理
    void extendFloor();
    bool isNextActionEnabled();
    
    // 次にアイテム画面を強制終了
    void endItemSelect();
    
    PlayerPorch* getPorch();
    
    // 装備関係
    void soubiSword(SwordItem* sword);
    void soubiShiled(ShieldItem* shield);
    void soubiUdewa_1(UdewaItem* udewa);
    void soubiUdewa_2(UdewaItem* udewa);
    SwordItem* getSword();
    ShieldItem* getShield();
    UdewaItem* getUdewa_1();
    UdewaItem* getUdewa_2();
    
    // 画面出力関係
    GMVector2D getCameraPos(int dx, int dy);
    
    _turnControl* getTurn(){
        return m_turnControl;
    }
    
    // 行動中
    bool isAct();
    void doAct();
    void doEnd();
    
    // 親を取得
    SKDungeonScene* getDungeonScene();
    
};


class _turnControl{
    SKPlayer* m_parent;
public:
    _turnControl(SKPlayer* parent);
    std::list<SKEnemy*> m_actionEnemys;
    void actionCreate();
    bool action();
    bool move();
    bool isAction();
    
};


#endif /* defined(__Karakuri2_Mac__SKPlayer__) */
