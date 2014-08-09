//
//  SKPlayScene.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKPlayScene__
#define __Karakuri2_Mac__SKPlayScene__

#include "Karakuri.h"
#include <vector>

class SKPlayer;
class SKEnemyMan;
class SKItemManager;
class SKEffectManager;
class SKMassManager;
class SKUserInterface;
class SKSoundManager;
class SKTextureManager;
class SKAnimationManager;
class SKBlockManager;
class SKPlayChild;
class SKPlayMenu;
class SKPlayAction;
class SKPlayFree;

enum SKTextureNames{
    Texture_floorName,
    Texture_messageName,
    Texture_itemName,
    Texture_blockName,
    // デバッグ用。矢印テクスチャ。
    Texture_directionName = 99,
};

class SKPlayScene : public GMScene{
    // 子シーケンスからのアクセスを許可する。
    friend class SKPlayMenu;
    friend class SKPlayAction;
    friend class SKPlayFree;
    
    // 子シーケンス
    SKPlayChild* m_child;
    
    // 各種使用クラス
    SKPlayer* m_player;
    SKEnemyMan* m_enemMan;
    SKItemManager* m_itemMan;
    SKEffectManager* m_EffectMan;
    SKMassManager* m_massMan;
    SKUserInterface* m_UI;
    SKSoundManager* m_soundMan;
    SKTextureManager* m_TexMan;
    SKAnimationManager* m_animeMan;
    SKBlockManager* m_blockMan;
    
    
// 画像描画のためのクラス
    GMBasicEffect* mBasicEffect;
    
// 行列
    GMMatrix m_projectionMatrix;
    GMMatrix m_viewMatrix;
    GMMatrix m_worldMatrix;
    
public:
    SKPlayScene();
    ~SKPlayScene();
    
public:
    void willAppear(GMGraphics *g) override;
    void didDisappear() override;
    
public:
    void updateModel(GMInput* input, double deltaTime) override;
    void drawView(GMGraphics* g) override;
    
public:
    // 取得関数
    GMBasicEffect* getCurrentEffect();
    SKPlayer* getPlayer() const;
    SKEffectManager* getEffectMan() const;
    SKItemManager* getItemMan() const;
    SKEnemyMan* getEnemMan() const;
    SKMassManager* getMassMan() const;
    SKUserInterface* getUI() const;
    SKSoundManager* getSoundMan() const;
    SKTextureManager* getTexMan() const;
    SKBlockManager* getBlockMan() const;
    SKAnimationManager* getAnimeMan() const;
    
public:
    // セット関数
    void setPlayer(SKPlayer* player);
    void setMassMan(SKMassManager* manager);
    
private:
    void loadStage();
    
};

extern SKPlayScene* gPlayScene;

#endif /* defined(__Karakuri2_Mac__SKPlayScene__) */
