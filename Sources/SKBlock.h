//
//  SKBlock.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKBlock__
#define __Karakuri2_Mac__SKBlock__

#include "SKObject.h"

class SKDungeonScene;

class SKBlock : public SKObject{
    
public:
    SKBlock(SKDungeonScene* scene);
    ~SKBlock();
    
    void objectDraw(int s_draw_x, int s_draw_y) override;
    bool objectUpdate(GMInput* input, double deltaTime) override;
    void objectInit(GMGraphics* g) override;
};

#endif /* defined(__Karakuri2_Mac__SKBlock__) */
