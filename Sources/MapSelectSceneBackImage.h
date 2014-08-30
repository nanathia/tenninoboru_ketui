//
//  MapSelectSceneBackImage.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneBackImage__
#define __Karakuri2_Mac__MapSelectSceneBackImage__

#include "Karakuri.h"

namespace mapSelect{
    
    class SKMapSelectScene;
    
    class BackImage{
        double m_time;
        SKMapSelectScene* m_parent;
    public:
        BackImage(SKMapSelectScene* parent);
        ~BackImage();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
}

#endif /* defined(__Karakuri2_Mac__MapSelectSceneBackImage__) */
