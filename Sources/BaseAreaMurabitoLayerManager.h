//
//  MurabitoLayerManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MurabitoLayerManager__
#define __Karakuri2_Mac__MurabitoLayerManager__

#include "Karakuri.h"
#include <list>

namespace baseArea{
    class BaseAreaMap;
    class TileLayer;
    class MurabitoManager;
    
    class MurabitoLayerManager{
        std::list<TileLayer*> m_data;
        BaseAreaMap* m_parent;
    public:
        MurabitoLayerManager(BaseAreaMap* parent);
        ~MurabitoLayerManager();
        void add(TileLayer* layer);
        MurabitoManager* createMurabitos() const;
    };
    
}


#endif /* defined(__Karakuri2_Mac__MurabitoLayerManager__) */
