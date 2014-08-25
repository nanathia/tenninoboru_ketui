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
#include "Globals.h"

SKPlayScene* gPlayScene = 0;

void SKPlayScene::willAppear(GMGraphics *g){
    // 画像管理クラスの初期化
    mBasicEffect = new GMBasicEffect;
    mSpriteBatch = new GMSpriteBatch;
    // シーケンスの用意
    m_child = new baseArea::SKBaseAreaScene("テトラペッドラ");
}

void SKPlayScene::didDisappear(){
    delete m_child;
    m_child = 0;
    
    delete mSpriteBatch;
    mSpriteBatch = 0;
    delete mBasicEffect;
    mBasicEffect = 0;
    
}


SKPlayScene::SKPlayScene():
m_child(0)
{
    gPlayScene = this;
}

SKPlayScene::~SKPlayScene(){
}

void SKPlayScene::updateModel(GMInput* input, double deltaTime){
    SKPlayChild* nextChild = m_child->update(input, deltaTime);
    if(nextChild != m_child){
        delete m_child;
        m_child = nextChild;
        nextChild = 0;
    }
}

void SKPlayScene::drawView(GMGraphics* g){
    // 画面のクリア
    g->clear(GMColor::LimeGreen);
    if(m_child) m_child->draw(mSpriteBatch);
    
}

GMBasicEffect* SKPlayScene::getCurrentEffect(){
    return mBasicEffect;
}

baseArea::SKBaseAreaScene* SKPlayScene::getBaseArea(){
#if IS_DEBUG
#endif
    return reinterpret_cast<baseArea::SKBaseAreaScene*>(m_child);
}

SKDungeonScene* SKPlayScene::getDungeonScene(){
    return reinterpret_cast<SKDungeonScene*>(m_child);
}

void SKPlayScene::setChild(SKPlayChild *child){
    m_child = child;
}
