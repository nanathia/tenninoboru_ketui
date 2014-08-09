//
//  SKGameOver.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/19.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKGameOver__
#define __Karakuri2_Mac__SKGameOver__

#include "Karakuri.h"

class SKGameOver: public GMScene{
    GMTexture2D* m_BackImage;
    GMMusic* m_BackMusic;
    GMBasicEffect* m_BasicEffect;
    GMSpriteBatch* m_SpriteBatch;
    double counter;
    
public:
    void drawView(GMGraphics* g) override;
    void updateModel(GMInput* input, double deltaTime) override;
    void willAppear(GMGraphics* g) override;
    void didDisappear() override;
    SKGameOver();
    ~SKGameOver();
};

#endif /* defined(__Karakuri2_Mac__SKGameOver__) */
