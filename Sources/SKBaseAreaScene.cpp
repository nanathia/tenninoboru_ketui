//
//  SKBaseAreaScene.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKBaseAreaScene.h"
#include "SKPlayScene.h"
#include "Globals.h"
#include "BaseAreaMap.h"

namespace baseArea{
    
    SKBaseAreaScene::SKBaseAreaScene(const std::string& areaName):
    m_CharacterMan(0),
    m_Map(0){
        if(areaName == "テトラペッドラ"){
            m_Map = new BaseAreaMap("tetora", "tmx");
        }
    }
    SKBaseAreaScene::~SKBaseAreaScene(){
        
    }
    SKPlayChild* SKBaseAreaScene::update(GMInput *input, double deltaTime){
        SKPlayChild* next = this;
        return next;
    }
    void SKBaseAreaScene::draw(GMSpriteBatch *s){
        // 設定
        GMGraphics::CurrentGraphics->clear(GMColor::Black);
        GMMatrix prjMt = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, SCREEN_SIZE.y, 0, -1, 1);
        gPlayScene->getCurrentEffect()->setProjectionMatrix(prjMt);
        gPlayScene->getCurrentEffect()->setViewMatrix(GMMatrix::Identity);
        gPlayScene->getCurrentEffect()->setWorldMatrix(GMMatrix::Identity);
        GMGraphics::CurrentGraphics->enableDepthTest(false);
        gPlayScene->getCurrentEffect()->enableFog(false);
        
        // 描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_Map->draw(s, GMRect2D(0, SCREEN_SIZE));
        s->end();
        gPlayScene->getCurrentEffect()->end();
    }

}