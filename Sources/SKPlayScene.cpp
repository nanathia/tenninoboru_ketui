//
//  SKPlayScene.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKPlayScene.h"
#include "SaKumas_includes.h"
#include "SKBlockManager.h"
#include "SKUserInterface.h"
#include "spriterFiles.h"
#include "GameMain.h"
#include "SKPlayFree.h"
#include "SKPlayMenu.h"
#include "SKPlayAction.h"
#include "ItemCommandInfo.h"
#include "SKItemInclude.h"

SKPlayScene* gPlayScene = 0;

void SKPlayScene::willAppear(GMGraphics *g){
    // 画像管理クラスの初期化
    mBasicEffect = new GMBasicEffect();
    
    // オブジェクト管理クラスの初期化
    m_TexMan = new SKTextureManager();
    
    // テクスチャの読み込み
    m_TexMan->add(Texture_floorName, "SKFloorImage.png");
    m_TexMan->add(Texture_messageName, "messageIm.png");
    m_TexMan->add(Texture_itemName, "SKItemImage.png");
    m_TexMan->add(Texture_blockName, "SKBlockImage.png");
    m_TexMan->add(Texture_directionName, "direction.png");
    if(!gGameInst->getFontTex()){
        // 静流ずフォントの読み込み
        gGameInst->setFont(new GMTexture2D("sizuruFonts.png"));
    }
    
    // 色々読み込み
//    m_player = new SKPlayer();
    m_enemMan = new SKEnemyMan();
    m_itemMan = new SKItemManager();
    m_blockMan = new SKBlockManager();
//    m_EffectMan;
    m_massMan = new SKMassManager(50, 50, width_num, height_num, g);
    m_UI = new SKUserInterface();
//    m_soundMan;
//    m_animeMan;
    
    // SKキー
    SKKeyHandle::create();
    
    // シーケンスの用意
    m_child = new SKPlayFree();
}

void SKPlayScene::didDisappear(){
    delete m_child;
    m_child = 0;
    
    SKKeyHandle::destroy();
    
    delete m_UI;
    m_UI = 0;
    delete m_massMan;
    m_massMan = 0;
    
    delete m_enemMan;
    m_enemMan = 0;
    delete m_itemMan;
    m_itemMan = 0;
    delete m_blockMan;
    m_blockMan = 0;
    
    delete m_TexMan;
    m_TexMan = 0;
    
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
    m_massMan->update();
    SKKeyHandle::KeyFlag_update(input, deltaTime);
    
    SKPlayChild* next = m_child->update(input, deltaTime, this);
    this->m_player->objectUpdate(input, deltaTime);
    
    // そもそもプレイヤー以外は毎フレーム見る必要はない
    this->m_enemMan->update_allEnemy(input, deltaTime);
    this->m_itemMan->update_allItem(input, deltaTime);
    this->m_blockMan->update_allBlock(input, deltaTime);

    if(next != m_child){
        delete m_child;
        m_child = next;
    }
    
    m_UI->updateUI(input, deltaTime);
}

void SKPlayScene::drawView(GMGraphics* g){
    // 画面のクリア
    g->clear(GMColor::LimeGreen);
    // カメラ特性の設定（プロジェクション行列）
    GMVector2D screenSize = g->getScreenSize();
    GMMatrix projMatrix = GMMatrix::CreatePerspectiveFieldOfView(GMMath::ToRadians(60.0), screenSize.x/screenSize.y, 1.0, 5000000.0);
    mBasicEffect->setProjectionMatrix(projMatrix);
    // カメラの位置と向きの計算
    GMVector3D cameraPos = GMVector3D(screenSize.x/2, screenSize.y/2-180, 200);
    GMMatrix cameraRota = GMMatrix::CreateRotationY(0.03*M_PI);
    cameraPos = cameraPos.transform(cameraRota);
    GMVector3D cameraUp = GMVector3D(0.0, 0.0, 1.0);
    GMMatrix viewMatrix = GMMatrix::CreateLookAt(cameraPos, GMVector3D(screenSize.x/2, screenSize.y/2, 0), cameraUp);
    mBasicEffect->setViewMatrix(viewMatrix);
    
//    // ライティングの設定
//    mBasicEffect->enableLighting(true);
//    mBasicEffect->enableLight(0, true);
//    mBasicEffect->enableLight(1, true);
//    mBasicEffect->enableLight(2, true);
//    mBasicEffect->enableLight(3, true);
//    mBasicEffect->setLightTypeAsPoint(0, GMVector3D(1, 1, 1));
//    mBasicEffect->setLightTypeAsPoint(1, GMVector3D(-1, 1, 1));
//    mBasicEffect->setLightTypeAsPoint(2, GMVector3D(1, 1, -1));
//    mBasicEffect->setLightTypeAsPoint(3, GMVector3D(-1, 1, -1));
//    mBasicEffect->setLightAmbientColor(0, GMColor(0.7, 0.7, 0.7, 1.0));
//    mBasicEffect->setLightAmbientColor(1, GMColor(0.7, 0.7, 0.7, 1.0));
//    mBasicEffect->setLightAmbientColor(2, GMColor(0.7, 0.7, 0.7, 1.0));
//    mBasicEffect->setLightAmbientColor(3, GMColor(0.7, 0.7, 0.7, 1.0));
    
    // フォグの設定
    // （テスト用に一時フォグをOFF）
    mBasicEffect->enableFog(true);
    mBasicEffect->setFogMode(GMFogModeLinear);
    mBasicEffect->setFogRange(300, 400);

    
    // 描画の設定
    GMMatrix world;
    GMDrawSys::SetBlendMode(GMBlendModeAlpha);
    mBasicEffect->enableTexture(true);
    g->enableDepthTest(true);
    {
        GMVector2D ofs = screenSize/2 + mass_size/2;
        GMVector2D d = m_player->getCameraPos(ofs.x, ofs.y);
        world = GMMatrix::CreateTranslation(d.x-ofs.x, d.y-ofs.y, 0) * GMMatrix::Identity;
    }
    mBasicEffect->setWorldMatrix(world);
    g->enableDepthTest(true);
    
    
    // ゲーム画面の描画
    mBasicEffect->begin();
    m_massMan->allDraw_currentGameGraph();
    mBasicEffect->end();
    
    // 2D描画に移行
    projMatrix = GMMatrix::CreateOrthographicOffCenter(0, screenSize.x, 0, screenSize.y, -1, 1);
    mBasicEffect->setProjectionMatrix(projMatrix);
    mBasicEffect->setViewMatrix(GMMatrix::Identity);
    mBasicEffect->setWorldMatrix(GMMatrix::Identity);
    g->enableDepthTest(false);
    mBasicEffect->enableFog(false);
    
    // UIの描画
    mBasicEffect->begin();
    m_UI->drawUI();
    mBasicEffect->end();
    
}

SKPlayer* SKPlayScene::getPlayer() const{
    return m_player;
}

SKEffectManager* SKPlayScene::getEffectMan() const{
    // TODO: SKPlayScene::getEffectMan()の実装
    return NULL;
}

SKItemManager* SKPlayScene::getItemMan() const{
    return m_itemMan;
}

SKEnemyMan* SKPlayScene::getEnemMan() const{
    return m_enemMan;
}

SKMassManager* SKPlayScene::getMassMan() const{
    return m_massMan;
}

SKUserInterface* SKPlayScene::getUI() const{
    return m_UI;
    return NULL;
}

SKSoundManager* SKPlayScene::getSoundMan() const{
    // TODO: SKPlayScene::getSoundMan()の実装
    return NULL;
}

SKTextureManager* SKPlayScene::getTexMan() const{
    return m_TexMan;
}

SKAnimationManager* SKPlayScene::getAnimeMan() const{
    // TODO: SKPlayScene::getAnimeMan()の実装
    return NULL;
}

void SKPlayScene::loadStage(){
    
}


void SKPlayScene::setPlayer(SKPlayer* player){
    m_player = player;
}

void SKPlayScene::setMassMan(SKMassManager* manager){
    m_massMan = manager;
}

SKBlockManager* SKPlayScene::getBlockMan() const{
    return m_blockMan;
}

GMBasicEffect* SKPlayScene::getCurrentEffect(){
    return mBasicEffect;
}
