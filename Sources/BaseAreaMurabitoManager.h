//
//  MurabitoManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MurabitoManager__
#define __Karakuri2_Mac__MurabitoManager__

#include "Karakuri.h"
#include <list>
#include <deque>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{

    class Murabito;
    class BaseAreaMap;
    
    class MurabitoManager{
        BaseAreaMap* m_parent;
        std::list<Murabito*> m_Murabitos;
    public:
        MurabitoManager(tinyxml2::XMLElement* layer, BaseAreaMap* parent);
        ~MurabitoManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        BaseAreaMap* getBaseAreaMap();
        std::list<Murabito*>& getMurabitos();
        void add(Murabito* murabito);
        Murabito* isCollision(const GMRect2D& rect) const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__MurabitoManager__) */
