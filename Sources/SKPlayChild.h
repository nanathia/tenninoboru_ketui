//
//  SKPlayChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/07.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKPlayChild__
#define __Karakuri2_Mac__SKPlayChild__

#include "Karakuri.h"
#include "SKPlayBase.h"

class SKPlayScene;

class SKPlayChild{
public:
    virtual ~SKPlayChild();
    // 更新のみを任せる。
    virtual SKPlayChild* update(GMInput* input, double deltaTime) = 0;
    virtual void draw(GMSpriteBatch* s) = 0;
};

#endif /* defined(__Karakuri2_Mac__SKPlayChild__) */
