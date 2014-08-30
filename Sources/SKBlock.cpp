//
//  SKBlock.cpp
//  : Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKBlock.h"
#include "SaKumas_includes.h"

SKBlock::SKBlock(SKDungeonScene* scene):
SKObject(scene)
{
}

SKBlock::~SKBlock(){
    
}


bool SKBlock::objectUpdate(GMInput* input, double deltaTime){
    SKObject::objectUpdate(input, deltaTime);
    
    return true;
}


void SKBlock::objectDraw(int i_x, int i_y){

    int nameNum = 4;
    
    GMDraw::Begin();
    gPlayScene->getCurrentEffect()->setTexture(m_scene->getTexMan()->get(Texture_blockName));
    GMDraw::FillQuad(GMVector3D(i_x, i_y, 10), GMVector3D(i_x+mass_size+1, i_y, 10),
                     GMVector3D(i_x+mass_size+1, i_y+mass_size+1, 10), GMVector3D(i_x, i_y+mass_size+1, 10),
                     GMVector3D(0, 0, 1), GMVector3D(0, 0, 1),
                     GMVector3D(0, 0, 1), GMVector3D(0, 0, 1),
                     GMVector2D(1.0/7*nameNum, 0), GMVector2D(1.0/7*(nameNum+1), 0),
                     GMVector2D(1.0/7*(nameNum+1), 1), GMVector2D(1.0/7*nameNum, 1));
    GMDraw::End();
}

void SKBlock::objectInit(GMGraphics* g){
    
}