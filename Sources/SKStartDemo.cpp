//
//  SKStartDemo.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKStartDemo.h"
#include "GameMain.h"
#include "SKDrawFont.h"
#include "JASpeakWindow.h"
#include "StartDemoChild.h"
#include "SKMusicManager.h"
#include "SKSoundManager.h"
#include "SKTextureManager.h"

SKStartDemo* gStartDemo = 0;

SKStartDemo::SKStartDemo():
m_SoundMan(0),
m_MusicMan(0),
m_SpriteBatch(0),
m_BasicEffect(0),
m_state(0),
m_texMan(0){
    gStartDemo = this;
}

SKStartDemo::~SKStartDemo(){
}

void SKStartDemo::willAppear(GMGraphics* g){
    if(!gGameInst->getFontTex()){
        // 静流ずフォントの読み込み
        gGameInst->setFont(new GMTexture2D("sizuruFonts.png"));
    }
    m_BasicEffect = new GMBasicEffect();
    m_SpriteBatch = new GMSpriteBatch();
    m_MusicMan = new SKMusicManager;
    m_SoundMan = new SKSoundManager;
    m_MusicMan->add(musicName_MainBGM, "SKStartDemoBGM.mp3");
    m_texMan = new SKTextureManager;
    m_texMan->add(texName_jiikuuakuu, "SKStartDemojikuuakuu.png");
    m_texMan->add(texName_sakuma, "SKStartDemoSakuma1.png");
    m_texMan->add(texName_sakuma_c, "SKStartDemoSakuma1_c.png");
    m_texMan->add(texName_Tetorapeddora, "SKStartDemoBGI.png");

    m_state = new startdemo::StartDemoState(this);
    
}

void SKStartDemo::didDisappear(){
    delete m_state;
    m_state = 0;
    
    delete m_texMan;
    m_texMan = 0;
    delete m_BasicEffect;
    m_BasicEffect = 0;
    delete m_SpriteBatch;
    m_SpriteBatch = 0;
    delete m_MusicMan;
    m_MusicMan = 0;
    delete m_SoundMan;
    m_SoundMan = 0;
    
}

void SKStartDemo::updateModel(GMInput* input, double deltaTime){
    m_state->update(input, deltaTime);
    
}

void SKStartDemo::drawView(GMGraphics* g){
    g->clear(GMColor::Black);
    
    GMMatrix projMatrix = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, SCREEN_SIZE.y, -1, 1);
    m_BasicEffect->setProjectionMatrix(projMatrix);
    m_BasicEffect->setViewMatrix(GMMatrix::Identity);
    m_BasicEffect->setWorldMatrix(GMMatrix::Identity);
    g->enableDepthTest(false);
    m_BasicEffect->enableFog(false);
    
    {
        m_BasicEffect->begin();
        m_SpriteBatch->begin();
        
        m_state->draw(m_SpriteBatch);
        
        m_SpriteBatch->end();
        m_BasicEffect->end();
    }
    
}

SKSoundManager* SKStartDemo::getSoundMan(){
    return m_SoundMan;
}
SKMusicManager* SKStartDemo::getMusicMan(){
    return m_MusicMan;
}
SKTextureManager* SKStartDemo::getTexMan(){
    return m_texMan;
}









