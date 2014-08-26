//
//  BaseAreaMapObject.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/25.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "tinyxml2.h"
#include <string>

namespace baseArea{
    
    MapElement::MapElement(ObjectLayer* parent, tinyxml2::XMLElement* data):
    m_parent(parent),
    m_Name(data->Name()),
    m_rect(0, 0){
        
    }
    MapElement::~MapElement(){
        
    }
    const std::string& MapElement::getName() const{
        return m_Name;
    }
    const GMRect2D& MapElement::getRect() const{
        return m_rect;
    }
    bool MapElement::isCollision(const GMRect2D& rect) const{
        return m_rect.intersects(rect);
    }
    
}