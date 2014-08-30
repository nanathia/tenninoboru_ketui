//
//  SKMapSelect.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKMapSelect.h"
#include "Globals.h"

namespace mapSelect{
    
    SKMapSelectScene::SKMapSelectScene(areaScenes firstCarsor):
    SKPlayChild(){
        
    }
    SKMapSelectScene::~SKMapSelectScene(){
        
    }
    SKPlayChild* SKMapSelectScene::update(GMInput* input, double deltaTime){
        SKPlayChild* next = this;
        return next;
    }
    void SKMapSelectScene::draw(GMSpriteBatch* s){
        
    }
    
}