//
//  TileSetManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__TileSetManager__
#define __Karakuri2_Mac__TileSetManager__

#include "Karakuri.h"
#include <vector>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class TileSet;
    class BaseAreaMap;
    class TileSetTile;
    
    class TileSetManager{
        std::vector<TileSet*> m_TileSet;
        BaseAreaMap* m_parent;
    public:
        TileSetManager(BaseAreaMap* parent);
        ~TileSetManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void add(TileSet* tileset);
        std::vector<TileSet*>& getTileSets();
        BaseAreaMap* getBaseAreaMap();
        void drawTile(GMSpriteBatch* s, const GMRect2D& dest, double radian, int gid) const;
        void drawTile(GMSpriteBatch* s, const GMRect2D& dest, int gid) const;
    };
        
}

#endif /* defined(__Karakuri2_Mac__TileSetManager__) */
