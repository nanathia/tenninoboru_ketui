//
//  SKTitle.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKTitle__
#define __Karakuri2_Mac__SKTitle__

#include "Karakuri.h"

namespace titleScene{
    class SceneChild;
}

class SKTitle : public GMScene{
    GMBasicEffect* m_BasicEffect;
    GMSpriteBatch* m_SpriteBatch;
    titleScene::SceneChild* m_child;
    
public:
    void drawView(GMGraphics* g) override;
    void updateModel(GMInput* input, double deltaTime) override;
    void willAppear(GMGraphics* g) override;
    void didDisappear() override;
    SKTitle();
    ~SKTitle();
};

extern SKTitle* gTitleScene;

#endif /* defined(__Karakuri2_Mac__SKTitle__) */

