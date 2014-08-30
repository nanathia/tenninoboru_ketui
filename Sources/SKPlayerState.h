//
//  SKPlayerState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/13.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKPlayerState__
#define __Karakuri2_Mac__SKPlayerState__

#include "Karakuri.h"

class SKMass;
class SKPlayer;

class SKPlayerState{
protected:
    double m_animationTime;
    double m_time;
    SKPlayer* m_user;
public:
    SKPlayerState(SKPlayer* user);
    virtual ~SKPlayerState(){};
    virtual SKPlayerState* update(GMInput* input, double deltaTime) = 0;
    virtual void draw(int dx, int dy) = 0;
    // カメラ
    virtual GMVector2D getCameraPos(int dx, int dy);
};

class PlayerWait: public SKPlayerState{
public:
    PlayerWait(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerLeady: public SKPlayerState{
public:
    PlayerLeady(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerChoiceAngle: public SKPlayerState{
public:
    PlayerChoiceAngle(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerMoving: public SKPlayerState{
    SKMass* m_startMass;
    SKMass* m_endMass;
public:
    PlayerMoving(SKPlayer* user, SKMass* moveStartMass, SKMass* MoveEndMass);
    ~PlayerMoving();
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
    GMVector2D getCameraPos(int dx, int dy) override;
};

class PlayerNanameInput: public SKPlayerState{
public:
    PlayerNanameInput(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerAttack: public SKPlayerState{
    bool m_isAttacked;
public:
    PlayerAttack(SKPlayer* user);
    ~PlayerAttack();
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerDamage: public SKPlayerState{
public:
    PlayerDamage(SKPlayer* user);
    ~PlayerDamage();
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerOpenMenu: public SKPlayerState{
public:
    PlayerOpenMenu(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerWaitingEnemyMove: public SKPlayerState{
public:
    PlayerWaitingEnemyMove(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

class PlayerWaitingEnemyAction: public SKPlayerState{
public:
    PlayerWaitingEnemyAction(SKPlayer* user);
    SKPlayerState* update(GMInput* input, double deltaTime) override;
    void draw(int dx, int dy) override;
};

#endif /* defined(__Karakuri2_Mac__SKPlayerState__) */
