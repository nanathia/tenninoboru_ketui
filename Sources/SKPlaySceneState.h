//
//  SKPlaySceneState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKPlaySceneState__
#define __Karakuri2_Mac__SKPlaySceneState__

#include "Karakuri.h"


class SKPlayScene;
class SKPlaySceneState;
class SKPlayChild;
class SKPlaySceneStateChild{
protected:
    SKPlayScene* m_user;
public:
    SKPlaySceneStateChild(SKPlayScene* user);
    virtual ~SKPlaySceneStateChild();
    virtual SKPlaySceneStateChild* update(GMInput* input, double deltaTime) = 0;
    virtual void draw(GMSpriteBatch* s) = 0;
};

class SKPlaySceneGame: public SKPlaySceneStateChild{
public:
    SKPlaySceneGame(SKPlayScene* user);
    ~SKPlaySceneGame();
    SKPlaySceneStateChild* update(GMInput* input, double deltaTime) override;
    void draw(GMSpriteBatch* s) override;
};

class SKPlaySceneInter: public SKPlaySceneStateChild{
protected:
    double m_time;
    SKPlayChild* m_prevChild;
    SKPlayChild* m_nextChild;
public:
    SKPlaySceneInter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
    ~SKPlaySceneInter();
    virtual SKPlaySceneStateChild* update(GMInput* input, double deltaTime) override = 0;
    virtual void draw(GMSpriteBatch* s) override = 0;
    // どれを作るべきか、勝手に判断して作るメソッド
    static SKPlaySceneInter* createInter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
};

class SKPlaySceneOuter: public SKPlaySceneStateChild{
protected:
    double m_time;
    SKPlayChild* m_prevChild;
    SKPlayChild* m_nextChild;
public:
    SKPlaySceneOuter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
    ~SKPlaySceneOuter();
    virtual SKPlaySceneStateChild* update(GMInput* input, double deltaTime) override = 0;
    virtual void draw(GMSpriteBatch* s) override = 0;
    // どれを作るべきか、勝手に判断して作るメソッド
    static SKPlaySceneOuter* createOuter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
};

class SKPlaySceneState{
    SKPlaySceneStateChild* m_child;
public:
    SKPlaySceneState(SKPlayScene* user);
    ~SKPlaySceneState();
    void update(GMInput* input, double deltaTime);
    void draw(GMSpriteBatch* s);
    void changeScene(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
};


#endif /* defined(__Karakuri2_Mac__SKPlaySceneState__) */
