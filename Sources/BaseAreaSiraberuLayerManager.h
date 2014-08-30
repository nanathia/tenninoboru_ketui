//
//  BaseAreaSiraberuLayerManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaSiraberuLayerManager__
#define __Karakuri2_Mac__BaseAreaSiraberuLayerManager__

#include "Karakuri.h"
#include <list>

namespace baseArea{
    
    class SiraberuLayer;
    class BaseAreaMap;
    class TileLayer;
    class Siraberu;
    
    class SiraberuLayerManager{
        std::list<TileLayer*> m_data;
        BaseAreaMap* m_parent;
    public:
        SiraberuLayerManager(BaseAreaMap* parent);
        ~SiraberuLayerManager();
        void add(TileLayer* layer);
//        const TileLayer* isSiraberuCollision(const GMRect2D&) const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaSiraberuLayerManager__) */
