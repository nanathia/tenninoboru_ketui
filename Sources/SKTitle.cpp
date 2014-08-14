//
//  SKTitle.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKTitle.h"
#include "SKTitleChild.h"
#include "SaKumas_includes.h"
#include "GameMain.h"
#include "SKDrawFont.h"
#include "SKTitleChild.h"
#include "SKSoundManager.h"
#include "SKMusicManager.h"

SKTitle* gTitleScene = 0;

SKTitle::SKTitle():
m_SpriteBatch(0),
m_BasicEffect(0),
m_child(0)
{
    gTitleScene = this;
}

SKTitle::~SKTitle(){
}

void SKTitle::willAppear(GMGraphics* g){
    if(!gGameInst->getFontTex()){
        // フォントの読み込み
        gGameInst->setFont(new GMTexture2D("sizuruFonts.png"));
    }
    m_BasicEffect = new GMBasicEffect();
    m_SpriteBatch = new GMSpriteBatch();
    m_SoundMan = new SKSoundManager;
    m_SoundMan->add(SoundName_Logo, "SKLogoSound.wav");
    m_MusicMan = new SKMusicManager;
    m_MusicMan->add(MusicName_Main, "SKTitleMainBGM.mp3");
    m_child = new titleScene::TitleLogo();
}

void SKTitle::didDisappear(){
    delete m_MusicMan;
    m_MusicMan = 0;
    delete m_SoundMan;
    m_SoundMan = 0;
    delete m_BasicEffect;
    m_BasicEffect = 0;
    delete m_SpriteBatch;
    m_SpriteBatch = 0;
    
}

void SKTitle::updateModel(GMInput* input, double deltaTime){
    titleScene::SceneChild* next = m_child->update(input, deltaTime);
    if(next != m_child){
        delete m_child;
        m_child = next;
    }
}

void SKTitle::drawView(GMGraphics* g){
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
        
        m_child->draw(m_SpriteBatch);
        
        m_SpriteBatch->end();
        m_BasicEffect->end();
    }
    
}

SKSoundManager* SKTitle::getSoundMan(){
    return m_SoundMan;
}
SKMusicManager* SKTitle::getMusicMan(){
    return m_MusicMan;
}