//
//  SKTitleChild.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKTitleChild.h"
#include "LogoChild.h"
#include "Globals.h"
#include "GameMain.h"

namespace titleScene{
    
    SceneChild::SceneChild():
    m_time(0),
    m_animationTime(0),
    m_BGMusic(0)
    {
    }
    SceneChild::~SceneChild(){
        delete m_BGMusic;
        m_BGMusic = 0;
    }
    
    TitleLogo::TitleLogo():
    SceneChild(){
        m_LogoImage = new GMTexture2D("JKLogo.png");
        m_child = new LogoInter();
    }
    TitleLogo::~TitleLogo(){
        delete m_child;
        m_child = 0;
        delete m_LogoImage;
        m_LogoImage = 0;
    }
    SceneChild* TitleLogo::update(GMInput *input, double deltaTime){
        SceneChild* next = this;
        LogoChild* nextChild = m_child->update(this, input, deltaTime);
        if(nextChild != m_child){
            if(nextChild){
                delete m_child;
                m_child = nextChild;
            }else{
                next = new TitleMain();
            }
        }
        return next;
    }
    void TitleLogo::draw(GMSpriteBatch *s){
        m_child->draw(this, s);
    }
    
    TitleMain::TitleMain():
    SceneChild(){
        m_BGImage = new GMTexture2D("タイトルメイン背景.png");
    }
    TitleMain::~TitleMain(){
        delete m_BGImage;
        m_BGImage = 0;
    }
    SceneChild* TitleMain::update(GMInput *input, double deltaTime){
        SceneChild* next = this;
        return next;
    }
    void TitleMain::draw(GMSpriteBatch *s){
        GMGraphics::CurrentGraphics->clear(GMColor::White);
        GMColor white = GMColor::White;
        white.a = m_animationTime;
        s->draw(m_BGImage, GMRect2D(0, 0, SCREEN_SIZE.x, SCREEN_SIZE.y));
        s->draw(0, GMRect2D(0, SCREEN_SIZE), white);
    }
    
}