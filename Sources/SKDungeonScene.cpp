//
//  SKDungeonScene.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/18.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKDungeonScene.h"
#include "SaKumas_includes.h"
#include "SKBlockManager.h"
#include "SKUserInterface.h"
#include "spriterFiles.h"
#include "GameMain.h"
#include "SKDungeonScene.h"
#include "SKBaseAreaScene.h"
#include "SKPlayChild.h"
#include "ItemCommandInfo.h"
#include "SKItemInclude.h"

SKDungeonScene::SKDungeonScene():
m_blockMan(0),
m_EffectMan(0),
m_massMan(0),
m_UI(0),
m_soundMan(0),
m_TexMan(0),
m_enemMan(0),
m_itemMan(0),
m_player(0)
{
    gPlayScene->setChild(this);
    // オブジェクト管理クラスの初期化
    m_TexMan = new SKTextureManager();
    
    // テクスチャの読み込み
    m_TexMan->add(Texture_floorName, "SKFloorImage.png");
    m_TexMan->add(Texture_messageName, "messageIm.png");
    m_TexMan->add(Texture_itemName, "SKItemImage.png");
    m_TexMan->add(Texture_blockName, "SKBlockImage.png");
    m_TexMan->add(Texture_directionName, "direction.png");
    
    m_enemMan = new SKEnemyMan();
    m_itemMan = new SKItemManager();
    m_blockMan = new SKBlockManager();
    //    m_EffectMan;
    m_massMan = new SKMassManager(50, 50, width_num, height_num);
    m_UI = new SKUserInterface();
    //    m_soundMan;
}

SKDungeonScene::~SKDungeonScene(){
    
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
    
}

SKPlayChild* SKDungeonScene::update(GMInput *input, double deltaTime){
    SKPlayChild* next = this;
    
    m_massMan->update();
    
    this->m_player->objectUpdate(input, deltaTime);
    
    // そもそもプレイヤー以外は毎フレーム見る必要はない
    this->m_enemMan->update_allEnemy(input, deltaTime);
    this->m_itemMan->update_allItem(input, deltaTime);
    this->m_blockMan->update_allBlock(input, deltaTime);
    
    m_UI->updateUI(input, deltaTime);
    
    return next;
}

void SKDungeonScene::draw(GMSpriteBatch *s){
    
    // カメラ特性の設定（プロジェクション行列）
    GMVector2D screenSize = GMGraphics::CurrentGraphics->getScreenSize();
    GMMatrix projMatrix = GMMatrix::CreatePerspectiveFieldOfView(GMMath::ToRadians(60.0), screenSize.x/screenSize.y, 1.0, 5000000.0);
    gPlayScene->getCurrentEffect()->setProjectionMatrix(projMatrix);
    // カメラの位置と向きの計算
    GMVector3D cameraPos = GMVector3D(screenSize.x/2, screenSize.y/2-180, 200);
    GMMatrix cameraRota = GMMatrix::CreateRotationY(0.03*M_PI);
    cameraPos = cameraPos.transform(cameraRota);
    GMVector3D cameraUp = GMVector3D(0.0, 0.0, 1.0);
    GMMatrix viewMatrix = GMMatrix::CreateLookAt(cameraPos, GMVector3D(screenSize.x/2, screenSize.y/2, 0), cameraUp);
    gPlayScene->getCurrentEffect()->setViewMatrix(viewMatrix);
    
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
    gPlayScene->getCurrentEffect()->enableFog(true);
    gPlayScene->getCurrentEffect()->setFogMode(GMFogModeLinear);
    gPlayScene->getCurrentEffect()->setFogRange(300, 400);
    
    // 描画の設定
    GMMatrix world;
    GMDrawSys::SetBlendMode(GMBlendModeAlpha);
    gPlayScene->getCurrentEffect()->enableTexture(true);
    GMGraphics::CurrentGraphics->enableDepthTest(true);
    {
        GMVector2D ofs = screenSize/2 + mass_size/2;
        GMVector2D d = m_player->getCameraPos(ofs.x, ofs.y);
        world = GMMatrix::CreateTranslation(d.x-ofs.x, d.y-ofs.y, 0) * GMMatrix::Identity;
    }
    gPlayScene->getCurrentEffect()->setWorldMatrix(world);
    GMGraphics::CurrentGraphics->enableDepthTest(true);
    
    
    // ゲーム画面の描画
    gPlayScene->getCurrentEffect()->begin();
    m_massMan->allDraw_currentGameGraph();
    gPlayScene->getCurrentEffect()->end();
    
    // 2D描画に移行
    projMatrix = GMMatrix::CreateOrthographicOffCenter(0, screenSize.x, 0, screenSize.y, -1, 1);
    gPlayScene->getCurrentEffect()->setProjectionMatrix(projMatrix);
    gPlayScene->getCurrentEffect()->setViewMatrix(GMMatrix::Identity);
    gPlayScene->getCurrentEffect()->setWorldMatrix(GMMatrix::Identity);
    GMGraphics::CurrentGraphics->enableDepthTest(false);
    gPlayScene->getCurrentEffect()->enableFog(false);
    
    // UIの描画
    gPlayScene->getCurrentEffect()->begin();
    m_UI->drawUI();
    gPlayScene->getCurrentEffect()->end();
}


SKPlayer* SKDungeonScene::getPlayer() const{
    return m_player;
}

SKEffectManager* SKDungeonScene::getEffectMan() const{
    // TODO: SKDungeonScene::getEffectMan()の実装
    return NULL;
}

SKItemManager* SKDungeonScene::getItemMan() const{
    return m_itemMan;
}

SKEnemyMan* SKDungeonScene::getEnemMan() const{
    return m_enemMan;
}

SKMassManager* SKDungeonScene::getMassMan() const{
    return m_massMan;
}

SKUserInterface* SKDungeonScene::getUI() const{
    return m_UI;
    return NULL;
}

SKSoundManager* SKDungeonScene::getSoundMan() const{
    // TODO: SKDungeonScene::getSoundMan()の実装
    return NULL;
}

SKTextureManager* SKDungeonScene::getTexMan() const{
    return m_TexMan;
}

void SKDungeonScene::loadStage(){
    
}


void SKDungeonScene::setPlayer(SKPlayer* player){
    m_player = player;
}

void SKDungeonScene::setMassMan(SKMassManager* manager){
    m_massMan = manager;
}

SKBlockManager* SKDungeonScene::getBlockMan() const{
    return m_blockMan;
}