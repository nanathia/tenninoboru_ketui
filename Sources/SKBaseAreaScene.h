//
//  SKBaseAreaScene.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKBaseAreaScene__
#define __Karakuri2_Mac__SKBaseAreaScene__

#include "Karakuri.h"

namespace baseArea{
    
    class SKBaseAreaScene: public GMScene{
        GMTexture2D* m_BackImage;
        GMMusic* m_BackMusic;
        GMBasicEffect* m_BasicEffect;
        GMSpriteBatch* m_SpriteBatch;
        
    public:
        SKBaseAreaScene();
        ~SKBaseAreaScene();
        void drawView(GMGraphics* g) override;
        void updateModel(GMInput* input, double deltaTime) override;
        void willAppear(GMGraphics* g) override;
        void didDisappear() override;
    };
    
};

#endif /* defined(__Karakuri2_Mac__SKBaseAreaScene__) */
