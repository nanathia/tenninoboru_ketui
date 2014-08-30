//
//  SKMapSelect.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSources.h"
#include "JASpeakWindow.h"
#include "SKDungeonScene.h"
#include "SKBaseAreaScene.h"
#include "SKPlayScene.h"
#include "ResourceManagerSources.h"

namespace mapSelect{
    
    SKMapSelectScene::SKMapSelectScene(areaScenes firstCarsor):
    SKPlayChild(),
    m_TexMan(0),
    m_MusicMan(0),
    m_SoundMan(0),
    m_JaSpkWin(0),
    m_selectAreaMan(0),
    m_backImage(0),
    m_carsor(0){
        //マネージャーの用意
        m_JaSpkWin = new JASpeakWindow::Window;
        m_TexMan = new SKTextureManager;
        m_MusicMan = new SKMusicManager;
        m_SoundMan = new SKSoundManager;
        
        // リソースの割り当て
        m_TexMan->add(texName_Tetorapeddora, " MapSelectTetorapeddora.png");
        m_TexMan->add(texName_Tentinoreiei, " MapSelectTentinoreiei.png");
        m_TexMan->add(texName_Kaminoyasiro, " MapSelectKaminoyasiro.png");
        m_TexMan->add(texName_BGI, " MapSelectBGI.png");
        m_TexMan->add(texName_Gendoumurasaki, " MapSelectGendoumurasaki.png");
        m_TexMan->add(texName_Uminodoukutu, " MapSelectUminomeikyuu.png");
        m_TexMan->add(texName_Hyururimyururi, " MapSelectHyururimyururi.png");
        
        // シーンオブジェクトの用意
        m_backImage = new BackImage(this);
    }
    SKMapSelectScene::~SKMapSelectScene(){
        delete m_backImage;
        m_backImage = 0;
        
        delete m_SoundMan;
        m_SoundMan = 0;
        delete m_MusicMan;
        m_MusicMan = 0;
        delete m_TexMan;
        m_TexMan = 0;
        delete m_JaSpkWin;
        m_JaSpkWin = 0;
    }
    SKPlayChild* SKMapSelectScene::update(GMInput* input, double deltaTime){
        SKPlayChild* next = this;
        
        // 背景の更新
        m_backImage->update(input, deltaTime);
        
        if(input->isKeyDownTriggered(GMKeyMaskD)) gPlayScene->changeScene(new SKDungeonScene);
        else if(input->isKeyDownTriggered(GMKeyMaskB)) gPlayScene->changeScene(new baseArea::SKBaseAreaScene("テトラペッドラ"));
        return next;
    }
    void SKMapSelectScene::draw(GMSpriteBatch* s){
        GMGraphics::CurrentGraphics->clear(GMColor::Black);
        gPlayScene->getCurrentEffect()->setProjectionMatrix(GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, SCREEN_SIZE.y, 1, -1));
        
        // 背景の描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_backImage->draw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
    }
    JASpeakWindow::Window* SKMapSelectScene::getJaSpkWin(){
        return m_JaSpkWin;
    }
    SKSoundManager* SKMapSelectScene::getSoundMan(){
        return m_SoundMan;
    }
    SKMusicManager* SKMapSelectScene::getMusicMan(){
        return m_MusicMan;
    }
    SKTextureManager* SKMapSelectScene::getTexMan(){
        return m_TexMan;
    }
    
}