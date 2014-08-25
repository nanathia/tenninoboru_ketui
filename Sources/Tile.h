//
//  Tile.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__Tile__
#define __Karakuri2_Mac__Tile__

#include "Karakuri.h"

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class TileLayer;

    class Tile{
        int m_Gid;
        const double m_PIRadian;
        TileLayer* m_parent;
    public:
        Tile(tinyxml2::XMLElement* data, TileLayer* parent);
        ~Tile();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s, const GMRect2D& dest);
        TileLayer* getTileLayer();
        int getGid() const;
    };

}

#endif /* defined(__Karakuri2_Mac__Tile__) */
