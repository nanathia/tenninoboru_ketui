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

class SKPlayChild;
class SKDungeonScene;
namespace baseArea{
    class SKBaseAreaScene;
}

enum SKTextureNames{
    Texture_floorName,
    Texture_messageName,
    Texture_itemName,
    Texture_blockName,
    // デバッグ用。矢印テクスチャ。
    Texture_directionName = 99,
};

class SKPlayScene : public GMScene{
    // 子シーケンス
    SKPlayChild* m_child; 
    
// 画像描画のためのクラス
    GMBasicEffect* mBasicEffect;
    GMSpriteBatch* mSpriteBatch;
    
public:
    SKPlayScene();
    ~SKPlayScene();
    
public:
    void willAppear(GMGraphics *g) override;
    void didDisappear() override;
    void updateModel(GMInput* input, double deltaTime) override;
    void drawView(GMGraphics* g) override;
    
public:
    GMBasicEffect* getCurrentEffect();
    SKDungeonScene* getDungeonScene();
    baseArea::SKBaseAreaScene* getBaseArea();
    void setChild(SKPlayChild* child);
    
};

extern SKPlayScene* gPlayScene;

#endif /* defined(__Karakuri2_Mac__SKPlayScene__) */
