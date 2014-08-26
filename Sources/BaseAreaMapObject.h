//
//  BaseAreaMapObject.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/25.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaMapObject__
#define __Karakuri2_Mac__BaseAreaMapObject__

#include "Karakuri.h"

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class ObjectLayer;
    
    class MapElement{
        ObjectLayer* m_parent;
        const std::string m_Name;
        const GMRect2D m_rect;
    public:
        MapElement(ObjectLayer* parent, tinyxml2::XMLElement* data);
        ~MapElement();
        bool isCollision(const GMRect2D& rect) const;
        const GMRect2D& getRect() const;
        const std::string& getName() const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaMapObject__) */
