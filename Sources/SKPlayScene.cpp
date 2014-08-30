//
//  SKPlayScene.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKPlayScene.h"
#include "SKPlayChild.h"
#include "SKDungeonScene.h"
#include "SKBaseAreaScene.h"
#include "SKPlaySceneState.h"
#include "SKSceneChangeOuters.h"
#include "SKMapSelect.h"
#include "Globals.h"

SKPlayScene* gPlayScene = 0;

void SKPlayScene::willAppear(GMGraphics *g){
    // 画像管理クラスの初期化
    mBasicEffect = new GMBasicEffect;
    mSpriteBatch = new GMSpriteBatch;
    // シーケンスの用意
    m_child = new mapSelect::SKMapSelectScene(mapSelect::SKMapSelectScene::scene_TetoraPeddora);
    m_state = new SKPlaySceneState(this);
}

void SKPlayScene::didDisappear(){
    delete m_state;
    m_state = 0;
    delete m_child;
    m_child = 0;
    
    delete mSpriteBatch;
    mSpriteBatch = 0;
    delete mBasicEffect;
    mBasicEffect = 0;
    
}


SKPlayScene::SKPlayScene():
m_child(0),
m_state(0)
{
    gPlayScene = this;
}

SKPlayScene::~SKPlayScene(){
}

void SKPlayScene::updateModel(GMInput* input, double deltaTime){
    m_state->update(input, deltaTime);
}

void SKPlayScene::drawView(GMGraphics* g){
    // 画面のクリア
    g->clear(GMColor::LimeGreen);
    m_state->draw(mSpriteBatch);
}

GMBasicEffect* SKPlayScene::getCurrentEffect(){
    return mBasicEffect;
}

baseArea::SKBaseAreaScene* SKPlayScene::getBaseArea(){
#if IS_DEBUG
#endif
    return m_state->getBaseAreaScene();
}

SKDungeonScene* SKPlayScene::getDungeonScene(){
    return m_state->getDungeonScene();
}

void SKPlayScene::setChild(SKPlayChild *child){
    m_child = child;
}

void SKPlayScene::changeScene(SKPlayChild *nextScene){
    m_state->changeScene(m_child, nextScene);
}

SKPlayChild* SKPlayScene::getChild(){
    return m_child;
}
