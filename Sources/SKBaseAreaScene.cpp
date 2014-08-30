//
//  SKBaseAreaScene.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKBaseAreaScene.h"
#include "SKPlayScene.h"
#include "BaseAreaSouces.h"
#include "SKSoundManager.h"
#include "SKMusicManager.h"
#include "SKMapSelect.h"
#include "SKTextureManager.h"
#include "Globals.h"
#include "BaseAreaMap.h"
#include "SKSpeakWindow.h"
#include "SKDungeonScene.h"

#pragma mark １マスの幅
namespace {
    const GMVector2D TileDestSize(50, 50);
}

#pragma mark ベースエリアシーンの基底
namespace baseArea{
    
    SKBaseAreaScene::SKBaseAreaScene(const std::string& areaName):
    SKPlayChild(),
    m_CharacterMan(0),
    m_Map(0),
    m_SoundMan(0),
    m_MusicMan(0),
    m_TexMan(0),
    m_ViewMatrix(GMMatrix::Identity),
    m_Camera(0),
    m_nomalSpeakWindow(0){
        m_nomalSpeakWindow = new SKSpeakWindow::Window;
        m_SoundMan = new SKSoundManager;
        m_MusicMan = new SKMusicManager;
        m_TexMan = new SKTextureManager;
        m_TexMan->add(texName_player, "baseSakuma.png");
        if(areaName == "テトラペッドラ"){
            m_Map = new BaseAreaMap(this, "tetora", "tmx");
        }
        m_CharacterMan = new CharacterManager(this);
        m_Camera = new Camera(this);
    }
    SKBaseAreaScene::~SKBaseAreaScene(){
        delete m_Camera;
        m_Camera = 0;
        delete m_Map;
        m_Map = 0;
        delete m_CharacterMan;
        m_CharacterMan = 0;
        delete m_TexMan;
        m_TexMan = 0;
        delete m_SoundMan;
        m_SoundMan = 0;
        delete m_MusicMan;
        m_MusicMan = 0;
        delete m_nomalSpeakWindow;
        m_nomalSpeakWindow = 0;
    }
    SKPlayChild* SKBaseAreaScene::update(GMInput *input, double deltaTime){
        SKPlayChild* next = this;
        m_CharacterMan->update(input, deltaTime);
        m_Camera->update(input, deltaTime);
        m_nomalSpeakWindow->update(input, deltaTime);
        m_Map->update(input, deltaTime);
        if(input->isKeyDownTriggered(GMKeyMaskD)){
            SKDungeonScene* test = new SKDungeonScene();
            gPlayScene->changeScene(test);
        }else if(input->isKeyDownTriggered(GMKeyMaskM)){
            gPlayScene->changeScene(new mapSelect::SKMapSelectScene(mapSelect::SKMapSelectScene::scene_TetoraPeddora));
        }
        return next;
    }
    void SKBaseAreaScene::draw(GMSpriteBatch *s){
        // 設定
        GMGraphics::CurrentGraphics->clear(GMColor::Black);
        GMMatrix prjMt = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, -SCREEN_SIZE.y, -1, 1);
        gPlayScene->getCurrentEffect()->setProjectionMatrix(prjMt);
        gPlayScene->getCurrentEffect()->setWorldMatrix(GMMatrix::Identity);
        GMGraphics::CurrentGraphics->enableDepthTest(false);
        gPlayScene->getCurrentEffect()->enableFog(false);
        
        gPlayScene->getCurrentEffect()->setViewMatrix(m_Camera->createRevirthMatrix());
        // マップ描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_Map->getTileLayerMan()->FirstDraw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
        
        prjMt = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, SCREEN_SIZE.y, -1, 1);
        gPlayScene->getCurrentEffect()->setViewMatrix(m_ViewMatrix);
        gPlayScene->getCurrentEffect()->setProjectionMatrix(prjMt);
        
        gPlayScene->getCurrentEffect()->setViewMatrix(m_Camera->createViewMatrix());
        // プレイヤー, 村人描画
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_CharacterMan->draw(s);
        m_Map->draw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
        
        prjMt = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, -SCREEN_SIZE.y, -1, 1);
        gPlayScene->getCurrentEffect()->setProjectionMatrix(prjMt);
        gPlayScene->getCurrentEffect()->setWorldMatrix(GMMatrix::Identity);
        gPlayScene->getCurrentEffect()->setViewMatrix(m_Camera->createRevirthMatrix());
        // マップ描画２
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_Map->getTileLayerMan()->SecondDraw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
        
        // UI描画
        gPlayScene->getCurrentEffect()->setViewMatrix(GMMatrix::Identity);
        prjMt = GMMatrix::CreateOrthographicOffCenter(0, SCREEN_SIZE.x, 0, SCREEN_SIZE.y, -1, 1);
        gPlayScene->getCurrentEffect()->setProjectionMatrix(prjMt);
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        m_nomalSpeakWindow->draw(s);
        s->end();
        gPlayScene->getCurrentEffect()->end();
    }
    CharacterManager* SKBaseAreaScene::getCharMan(){
        return m_CharacterMan;
    }
    BaseAreaMap* SKBaseAreaScene::getMap(){
        return m_Map;
    }
    SKTextureManager* SKBaseAreaScene::getTexMan(){
        return m_TexMan;
    }
    SKMusicManager* SKBaseAreaScene::getMusicMan(){
        return m_MusicMan;
    }
    SKSoundManager* SKBaseAreaScene::getSoundMan(){
        return m_SoundMan;
    }
    void SKBaseAreaScene::setViewMatrix(const GMMatrix& view){
        m_ViewMatrix = view;
    }
    SKSpeakWindow::Window* SKBaseAreaScene::getNomalSpeakWin(){
        return m_nomalSpeakWindow;
    }
    
#pragma mark 共通処理メソッド
    // 描画座標を取得
    GMVector2D SKBaseAreaScene::convertMat2Draw(const GMVector2D& matrixVector){
        return matrixVector*TileDestSize;
    }
    const GMVector2D& SKBaseAreaScene::getTileDestSize(){
        return TileDestSize;
    }

}