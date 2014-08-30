//
//  MapSelectSceneBackImage.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSources.h"
#include "ResourceManagerSources.h"

namespace mapSelect{
    
    BackImage::BackImage(SKMapSelectScene* parent):
    m_time(0),
    m_parent(parent){
        
    }
    BackImage::~BackImage(){
        
    }
    void BackImage::update(GMInput *input, double deltaTime){
        
    }
    void BackImage::draw(GMSpriteBatch *s){
        s->draw(m_parent->getTexMan()->get(SKMapSelectScene::texName_BGI), GMRect2D(0, SCREEN_SIZE));
    }
    
}