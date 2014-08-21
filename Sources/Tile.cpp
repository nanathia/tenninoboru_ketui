//
//  Tile.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "tinyxml2.h"

namespace{
    double convertTiledFileAngle2Radian(int tiledAngle){
        double ret = 0;
        if(tiledAngle==0 || tiledAngle==8){
        }else if(tiledAngle==2 || tiledAngle==6){
            ret = -0.5;
        }else if(tiledAngle==4 || tiledAngle==12){
            ret = -1.0;
        }else if(tiledAngle==10 || tiledAngle==14){
            ret = 0.5;
        }
        return ret;
    }
}

namespace baseArea{
    
    Tile::Tile(tinyxml2::XMLElement* data, TileLayer* parent):
    m_parent(parent),
    m_Gid(data->IntAttribute("gid") & 0x0fffffff),
    m_PIRadian(convertTiledFileAngle2Radian(data->UnsignedAttribute("gid") >> 28)*M_PI){
    }
    Tile::~Tile(){
        
    }
    void Tile::update(GMInput *input, double deltaTime){
    }
    void Tile::draw(GMSpriteBatch *s, const GMRect2D& dest){
        if(m_PIRadian){
            getTileLayer()->getManager()->getBaseAreaMap()->getTileSetMan()->drawTile(s, dest, m_PIRadian, m_Gid);
        }else{
            getTileLayer()->getManager()->getBaseAreaMap()->getTileSetMan()->drawTile(s, dest, m_Gid);
        }
    }
    TileLayer* Tile::getTileLayer(){
        return m_parent;
    }
    
}