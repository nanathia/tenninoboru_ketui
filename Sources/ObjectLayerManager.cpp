//
//  ObjectLayerManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ObjectLayerManager.h"
#include "ObjectLayer.h"
#include "SaKumas_includes.h"
#include "tinyxml2.h"

namespace baseArea{
    
    ObjectLayerManager::ObjectLayerManager(BaseAreaMap* parent):
    m_parent(parent){
    }
    ObjectLayerManager::~ObjectLayerManager(){
        int size = (int)m_ObjectLayer.size();
        for(int i = 0; i < size; i++){
            delete m_ObjectLayer[i];
            m_ObjectLayer[i] = 0;
        }
        safeCleanUp(m_ObjectLayer);
    }
    void ObjectLayerManager::update(GMInput *input, double deltaTime){
        
    }
    void ObjectLayerManager::draw(GMSpriteBatch *s){
        
    }
    void ObjectLayerManager::add(baseArea::ObjectLayer *layer){
        m_ObjectLayer.push_back(layer);
    }
    
}