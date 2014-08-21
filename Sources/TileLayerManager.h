//
//  TileLayerManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__TileLayerManager__
#define __Karakuri2_Mac__TileLayerManager__

#include "Karakuri.h"
#include <vector>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class TileLayer;
    class BaseAreaMap;
    
    class TileLayerManager{
        std::vector<TileLayer*> m_tileLayer;
        BaseAreaMap* m_parent;
    public:
        TileLayerManager(BaseAreaMap* parent);
        ~TileLayerManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s, const GMRect2D& dest);
        void add(TileLayer* layer);
        BaseAreaMap* getBaseAreaMap();
    };
    
}

#endif /* defined(__Karakuri2_Mac__TileLayerManager__) */
