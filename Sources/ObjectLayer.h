//
//  ObjectLayer.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ObjectLayer__
#define __Karakuri2_Mac__ObjectLayer__

#include "Karakuri.h"
#include <list>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class ObjectLayerManager;
    class MapElement;
    
    class ObjectLayer{
        std::list<MapElement*> m_Elements;
        const std::string m_Name;
        ObjectLayerManager* m_parent;
    public:
        ObjectLayer(ObjectLayerManager* parent, tinyxml2::XMLElement* data);
        ~ObjectLayer();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        
    };
    
}

#endif /* defined(__Karakuri2_Mac__ObjectLayer__) */
