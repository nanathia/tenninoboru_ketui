//
//  BaseAreaSiraberuLayerManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"

namespace baseArea{
    
    SiraberuLayerManager::SiraberuLayerManager(BaseAreaMap* parent):
    m_parent(parent){
        
    }
    SiraberuLayerManager::~SiraberuLayerManager(){
        if(m_data.empty()) return;
        auto it = m_data.begin();
        while(it != m_data.end()){
            delete *it;
            it++;
        }
        m_data.clear();
    }
    void SiraberuLayerManager::add(TileLayer* layer){
        m_data.push_back(layer);
    }
//    const std::string SiraberuLayerManager::isSiraberuCollision(const GMRect2D& rect) const{
//        if(m_data.empty()) return 0;
//        auto it = m_data.begin();
//        while(it != m_data.end()){
//            if((*it)->isCollision(rect)){
//                return (*it)->isCollisionANDGetNumberingStr(rect);
//            }
//            it++;
//        }
//        return 0;
//    }
//    int 
//    
}

