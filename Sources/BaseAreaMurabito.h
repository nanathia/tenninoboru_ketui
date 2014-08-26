//
//  BaseAreaMurabito.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaMurabito__
#define __Karakuri2_Mac__BaseAreaMurabito__

#include "Karakuri.h"

class BaseAreaMurabitoManager;
class SKSpeakWindow;

class BaseAreaMurabito{
    SKSpeakWindow* m_spkWin;
public:
    BaseAreaMurabito(BaseAreaMurabitoManager* parent);
    ~BaseAreaMurabito();
    void update(GMInput* input, double deltaTime);
    void draw(GMSpriteBatch* s);
};

#endif /* defined(__Karakuri2_Mac__BaseAreaMurabito__) */
