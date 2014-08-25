//
//  TileLayerManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "TileLayerManager.h"
#include "SaKumas_includes.h"
#include "TileLayer.h"
#include "tinyxml2.h"
#include <string>

namespace baseArea{
    
    TileLayerManager::TileLayerManager(BaseAreaMap* parent):
    m_parent(parent){
        
    }
    TileLayerManager::~TileLayerManager(){
        int size = (int)m_tileLayer.size();
        for(int i = 0; i < size; i++){
            delete m_tileLayer[i];
            m_tileLayer[i] = 0;
        }
        safeCleanUp(m_tileLayer);
    }
    void TileLayerManager::update(GMInput *input, double deltaTime){
        
    }
    void TileLayerManager::FirstDraw(GMSpriteBatch *s){
        int size = (int)m_tileLayer.size();
        for(int i = 0; i < size; i++){
            if(m_tileLayer[i]->getName().find("firstdraw") == string::npos) continue;
            m_tileLayer[i]->draw(s);
        }
    }
    void TileLayerManager::SecondDraw(GMSpriteBatch *s){
        int size = (int)m_tileLayer.size();
        for(int i = 0; i < size; i++){
            if(m_tileLayer[i]->getName().find("seconddraw") == string::npos) continue;
            m_tileLayer[i]->draw(s);
        }
    }
    void TileLayerManager::add(baseArea::TileLayer *layer){
        m_tileLayer.push_back(layer);
    }
    BaseAreaMap* TileLayerManager::getBaseAreaMap(){
        return m_parent;
    }
    bool TileLayerManager::isCollision(const GMRect2D& rect) const{
        int size = (int)m_tileLayer.size();
        for(int i = 0; i < size; i++){
            if(m_tileLayer[i]->getName() != "collision") continue;
            if(m_tileLayer[i]->isCollision(rect)) return true;
        }
        return false;
    }
    
}