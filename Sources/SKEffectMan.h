//
//  SKEffectMan.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEffectMan__
#define __Karakuri2_Mac__SKEffectMan__

#include "Karakuri.h"

class SKTextureManager;
class SKEffect;

class SKEffectManager{
    SKTextureManager* m_texMan;
public:
    SKEffectManager();
    ~SKEffectManager();
    void update(GMInput* input, double deltaTime);
    void draw(GMSpriteBatch* s);
public:
    
};

#endif /* defined(__Karakuri2_Mac__SKEffectMan__) */
