//
//  SKGameOver.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/19.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKGameOver.h"
#include "SKGameOver.h"
#include "SaKumas_includes.h"
#include "GameMain.h"
#include "SKDrawFont.h"

SKGameOver* gGameOverScene = 0;

SKGameOver::SKGameOver():
m_BackMusic(0),
m_BackImage(0),
m_SpriteBatch(0),
m_BasicEffect(0),
counter(0)
{
    gGameOverScene = this;
}

SKGameOver::~SKGameOver(){
    
}

void SKGameOver::willAppear(GMGraphics* g){
    if(!gGameInst->getFontTex()){
        // 静流ずフォントの読み込み
        gGameInst->setFont(new GMTexture2D("sizuruFonts.png"));
    }
    m_BasicEffect = new GMBasicEffect();
    m_SpriteBatch = new GMSpriteBatch();
    m_BackImage = new GMTexture2D("SKGameOverImage.png");
    counter = 0;
    
}

void SKGameOver::didDisappear(){
    delete m_BackImage;
    m_BackImage = 0;
    
    delete m_BasicEffect;
    m_BasicEffect = 0;
    delete m_SpriteBatch;
    m_SpriteBatch = 0;
    
}

void SKGameOver::updateModel(GMInput* input, double deltaTime){

    if(counter >= 1.0){
        if(input->isKeyDownTriggered(GMKeyMaskSpace)) gGameInst->ChangeScene("title");
    }else{
        counter += deltaTime/2.0;
    }
}

void SKGameOver::drawView(GMGraphics* g){
    g->clear(GMColor::SkyBlue);
    
    GMMatrix projMatrix = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, SCREEN_SIZE.y, -1, 1);
    m_BasicEffect->setProjectionMatrix(projMatrix);
    m_BasicEffect->setViewMatrix(GMMatrix::Identity);
    m_BasicEffect->setWorldMatrix(GMMatrix::Identity);
    g->enableDepthTest(false);
    m_BasicEffect->enableFog(false);
    
    {
        m_BasicEffect->begin();
        m_SpriteBatch->begin();
        
        m_SpriteBatch->draw(m_BackImage, GMRect2D(0, 0, SCREEN_SIZE.x, SCREEN_SIZE.y), GMRect2D(0, 0, 700, 500));
        SKDrawFont::drawString("ゲームオーバー", 100, GMVector2D(150, 300), 0, m_SpriteBatch);
        
        m_SpriteBatch->end();
        m_BasicEffect->end();
    }
    
}