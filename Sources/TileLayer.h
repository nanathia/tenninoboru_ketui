//
//  TileLayer.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__TileLayer__
#define __Karakuri2_Mac__TileLayer__

#include "Karakuri.h"
#include <vector>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class Tile;
    class TileLayerManager;
    
    class TileLayer{
        std::vector<Tile*> m_Tiles;
        const std::string m_Name;
        const int m_width;
        const int m_height;
        TileLayerManager* m_parent;
    public:
        TileLayer(tinyxml2::XMLElement* data, TileLayerManager* parent);
        ~TileLayer();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s, const GMRect2D& dest);
        TileLayerManager* getManager();
    };
    
}

#endif /* defined(__Karakuri2_Mac__TileLayer__) */
