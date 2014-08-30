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
    class BaseAreaMap;
    
    class TileLayer{
        std::vector<Tile*> m_Tiles;
        const std::string m_Name;
        const int m_width;
        const int m_height;
        BaseAreaMap* m_parent;
    public:
        TileLayer(tinyxml2::XMLElement* data, BaseAreaMap* parent);
        ~TileLayer();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        BaseAreaMap* getBaseAreaMap();
        const std::string& getName();
        const int getWigth() const;
        const int getHeight() const;
        bool isCollision(const GMRect2D& rect) const;
        const std::string isCollisionANDGetNumberingStr(const GMRect2D& rect) const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__TileLayer__) */
