//
//  BaseAreaMurabitoManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaMurabitoManager__
#define __Karakuri2_Mac__BaseAreaMurabitoManager__

#include "Karakuri.h"
#include <list>

namespace baseArea{

    class BaseAreaMurabito;
    class BaseAreaMap;
    
    class BaseAreaMurabitoManager{
        BaseAreaMap* m_parent;
        std::list<BaseAreaMurabito*> m_Murabitos;
    public:
        BaseAreaMurabitoManager(BaseAreaMap* parent);
        ~BaseAreaMurabitoManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        BaseAreaMap* getBaseAreaMap();
        std::list<BaseAreaMurabito*>& getMurabitos();
        void add(BaseAreaMurabito* murabito);
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaMurabitoManager__) */
