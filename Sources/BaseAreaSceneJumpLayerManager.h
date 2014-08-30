//
//  BaseAreaSceneJumpLayerManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaSceneJumpLayerManager__
#define __Karakuri2_Mac__BaseAreaSceneJumpLayerManager__

#include "Karakuri.h"
#include <list>

namespace baseArea{
    class TileLayer;
    class BaseAreaMap;
    
    class SceneJumpLayerManager{
        std::list<TileLayer*> m_data;
        BaseAreaMap* m_parent;
    public:
        SceneJumpLayerManager(BaseAreaMap* parent);
        ~SceneJumpLayerManager();
        void add(TileLayer* layer);
        const char* isCollisionJumpSceneAndGetTMXPass() const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaSceneJumpLayerManager__) */
