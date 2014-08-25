//
//  TileSet.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__TileSet__
#define __Karakuri2_Mac__TileSet__

#include "Karakuri.h"

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class TileSet;
    class TileSetManager;
    class TileSetImage;
    
    class TileSetTile{
        bool m_isCollision;
        int m_Id;
        struct nextTile{
            int m_offsetX;
            int m_offsetY;
            int m_interval;
        };
        nextTile* m_nextTile;
        TileSet* m_parent;
    public:
        TileSetTile(tinyxml2::XMLElement* data, TileSet* parent);
        ~TileSetTile();
    };
    
    class TileSetImage{
        const int m_TileSetWidth;
        const int m_TileSetHeight;
        const int m_TileXNum;
        const int m_TileYNum;
        const GMVector2D m_TileOrigin;
        GMTexture2D* m_tex;
        TileSet* m_parent;
    public:
        TileSetImage(tinyxml2::XMLElement* data, TileSet* parent);
        ~TileSetImage();
    public:
        void draw(GMSpriteBatch* s, const GMRect2D& dest, int git) const;
        void draw(GMSpriteBatch* s, const GMRect2D& dest, double radian, int git) const;
    public:
        int getTileSetWidth() const;
        int getTileSetHeight() const;
        int getTileXNum() const;
        int getTileYNum() const;
    };
    
    class TileSet{
        const int m_FirstGid;
        const int m_TileWidth;
        const int m_TileHeight;
        const std::string m_Name;
        TileSetImage* m_Image;
        TileSetManager* m_parent;
    public:
        TileSet(tinyxml2::XMLElement* data, TileSetManager* parent);
        ~TileSet();
    public:
        int getTileWidth() const;
        int getTileHeight() const;
        int getFirstGit() const;
        const std::string& getName() const;
        TileSetImage* getImage();
        TileSetManager* getManager();
    };
    
}

#endif /* defined(__Karakuri2_Mac__TileSet__) */
