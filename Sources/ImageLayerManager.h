//
//  ImageLayerManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ImageLayerManager__
#define __Karakuri2_Mac__ImageLayerManager__

#include "Karakuri.h"
#include <vector>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class ImageLayer;
    class BaseAreaMap;
    
    class ImageLayerManager{
        std::vector<ImageLayer*> m_ImageLayer;
        BaseAreaMap* m_parent;
    public:
        ImageLayerManager(BaseAreaMap* parent);
        ~ImageLayerManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void add(ImageLayer* layer);
    };
    
}

#endif /* defined(__Karakuri2_Mac__ImageLayerManager__) */
