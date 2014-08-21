//
//  ImageLayerManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ImageLayerManager.h"
#include "ImageLayer.h"
#include "SaKumas_includes.h"
#include "tinyxml2.h"

namespace baseArea{
    
    ImageLayerManager::ImageLayerManager(BaseAreaMap* parent):
    m_parent(parent){
        
    }
    ImageLayerManager::~ImageLayerManager(){
        int size = (int)m_ImageLayer.size();
        for(int i = 0; i < size; i++){
            delete m_ImageLayer[i];
            m_ImageLayer[i] = 0;
        }
        safeCleanUp(m_ImageLayer);
    }
    void ImageLayerManager::update(GMInput *input, double deltaTime){
        
    }
    void ImageLayerManager::draw(GMSpriteBatch *s){
        
    }
    void ImageLayerManager::add(baseArea::ImageLayer *layer){
        m_ImageLayer.push_back(layer);
    }
    
}