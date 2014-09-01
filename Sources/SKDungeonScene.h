//
//  SKDungeonScene.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/18.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKDungeonScene__
#define __Karakuri2_Mac__SKDungeonScene__

#include "Karakuri.h"
#include "SKPlayChild.h"

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
namespace dungeonscenestate{
    class DungeonSceneState;
}

class SKDungeonScene: public SKPlayChild{
    SKPlayer* m_player;
    SKEnemyMan* m_enemMan;
    SKItemManager* m_itemMan;
    SKEffectManager* m_EffectMan;
    SKMassManager* m_massMan;
    SKUserInterface* m_UI;
    SKSoundManager* m_soundMan;
    SKTextureManager* m_TexMan;
    SKBlockManager* m_blockMan;
    const std::string m_name;
    // 状態
    dungeonscenestate::DungeonSceneState* m_state;
    
public:
    SKDungeonScene(const std::string& DungeonName);
    ~SKDungeonScene();
    SKPlayChild* update(GMInput* input, double deltaTime) override;
    void draw(GMSpriteBatch* s) override;
    
public:
    // 取得関数
    SKPlayer* getPlayer() const;
    SKEffectManager* getEffectMan() const;
    SKItemManager* getItemMan() const;
    SKEnemyMan* getEnemMan() const;
    SKMassManager* getMassMan() const;
    SKUserInterface* getUI() const;
    SKSoundManager* getSoundMan() const;
    SKTextureManager* getTexMan() const;
    SKBlockManager* getBlockMan() const;
    const std::string& Name() const;
    
public:
    // セット関数
    void setPlayer(SKPlayer* player);
    void setMassMan(SKMassManager* manager);
    
public:
    // その他いろいろ
    void nextFloor();
    
private:
    void loadStage();
};

#endif /* defined(__Karakuri2_Mac__SKDungeonScene__) */
