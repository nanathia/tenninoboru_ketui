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
#include "MapSelectSceneState.h"
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
    m_carsor(0),
    m_state(0){
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
        m_TexMan->add(texName_Carsor, "mapSelectCarsor.png");
        
        // シーンオブジェクトの用意
        m_backImage = new BackImage(this);
        m_selectAreaMan = new SelectObjManager(this);
        SelectObj* firstObj = 0;
        m_selectAreaMan->add(firstObj = new SelectObj(this, GMRect2D(180, 350, 100, 100), m_TexMan->get(SKMapSelectScene::texName_Tetorapeddora), "テトラペッドラ"));
        m_selectAreaMan->add(new SelectObj(this, GMRect2D(110, 550, 100, 100), m_TexMan->get(SKMapSelectScene::texName_Gendoumurasaki), "ゲンドウムラサキの錫杖"));
        m_selectAreaMan->add(new SelectObj(this, GMRect2D(110, 100, 100, 100), m_TexMan->get(SKMapSelectScene::texName_Tentinoreiei), "天地ノ霊影"));
        m_selectAreaMan->add(new SelectObj(this, GMRect2D(700, 300, 100, 100), m_TexMan->get(SKMapSelectScene::texName_Uminodoukutu), "海の洞窟"));
        m_selectAreaMan->add(new SelectObj(this, GMRect2D(900, 250, 100, 100), m_TexMan->get(SKMapSelectScene::texName_Kaminoyasiro), "神の社"));
        m_selectAreaMan->add(new SelectObj(this, GMRect2D(500, 150, 100, 100), m_TexMan->get(SKMapSelectScene::texName_Hyururimyururi), "ヒュルリミュルリ"));
        m_carsor = new SelectCarsor(firstObj, this);
        
        // 状態の用意
        m_state = new SceneState(this);
        
        // 時空亜空さんの用意
        m_JaSpkWin = new JASpeakWindow::Window;
    }
    SKMapSelectScene::~SKMapSelectScene(){
        delete m_JaSpkWin;
        m_JaSpkWin = 0;
        
        delete m_state;
        m_state = 0;
        
        delete m_carsor;
        m_carsor = 0;
        delete m_selectAreaMan;
        m_selectAreaMan = 0;
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
        
        // エリア選択オブジェクトの更新
        m_selectAreaMan->update(input, deltaTime);
        
        // カーソルの更新
        m_carsor->update(input, deltaTime);
        
        // 状態に移譲する更新
        m_state->update(input, deltaTime);
        
        // 時空亜空さんの更新
        m_JaSpkWin->update(input, deltaTime);
        
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
        
        // エリアオブジェクトの描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_selectAreaMan->draw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
        
        // カーソルのの描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_carsor->draw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
        
        // 状態に移譲する描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_state->draw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
        
        // 時空亜空さんのお言葉を描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_JaSpkWin->draw(s);
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
    BackImage* SKMapSelectScene::getBackImage(){
        return m_backImage;
    }
    SelectCarsor* SKMapSelectScene::getCarsor(){
        return m_carsor;
    }
    SelectObjManager* SKMapSelectScene::getSelectObjMan(){
        return m_selectAreaMan;
    }
    bool SKMapSelectScene::isChangeAreaReady() const{
        return m_state->isChangeAreaReady();
    }
    void SKMapSelectScene::ChangeBaseAreaReady(){
        m_state->changeBaseAreaReady();
    }
    
}