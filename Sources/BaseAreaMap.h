//
//  BaseAreaMap.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaMap__
#define __Karakuri2_Mac__BaseAreaMap__

#include "Karakuri.h"
#include <string>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class ImageLayerManager;
    class TileLayerManager;
    class ObjectLayerManager;
    class TileSetManager;
    class SKBaseAreaScene;
    class Player;
    
    class BaseAreaMap{
        ImageLayerManager* m_ImageLayerMan;
        TileLayerManager* m_TileLayerMan;
        ObjectLayerManager* m_ObjectLayerMan;
        TileSetManager* m_TileSetMan;
        SKBaseAreaScene* m_parent;
        
    public:
        BaseAreaMap(SKBaseAreaScene* parent, const std::string& fileName, const std::string& extetion);
        ~BaseAreaMap();
        void update(GMInput* intput, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        ImageLayerManager* getImageLayerMan();
        TileLayerManager* getTileLayerMan();
        ObjectLayerManager* getObjectLayerMan();
        TileSetManager* getTileSetMan();
        SKBaseAreaScene* getBaseAreaScene();
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaMap__) */
