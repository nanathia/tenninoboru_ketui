//
//  ObjectLayerManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ObjectLayerManager__
#define __Karakuri2_Mac__ObjectLayerManager__

#include "Karakuri.h"
#include <vector>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class ObjectLayer;
    class BaseAreaMap;
    
    class ObjectLayerManager{
        std::vector<ObjectLayer*> m_ObjectLayer;
        BaseAreaMap* m_parent;
    public:
        ObjectLayerManager(BaseAreaMap* parent);
        ~ObjectLayerManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void add(ObjectLayer* layer);
    };
    
}

#endif /* defined(__Karakuri2_Mac__ObjectLayerManager__) */
