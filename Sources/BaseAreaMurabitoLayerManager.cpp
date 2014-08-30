//
//  MurabitoLayerManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"

namespace baseArea{
    
    MurabitoLayerManager::MurabitoLayerManager(BaseAreaMap* parent):
    m_parent(parent){
        
    }
    MurabitoLayerManager::~MurabitoLayerManager(){
        if(m_data.empty()) return;
        auto it = m_data.begin();
        while(it != m_data.end()){
            delete *it;
            *it = 0;
            it++;
        }
        m_data.clear();
    }
    void MurabitoLayerManager::add(baseArea::TileLayer *layer){
        m_data.push_back(layer);
    }
    MurabitoManager* MurabitoLayerManager::createMurabitos() const{
        MurabitoManager* ret = 0;
        return ret;
    }
    
}