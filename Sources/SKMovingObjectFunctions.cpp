//
//  SKMovingObjectFunctions.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/08.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKMovingObjectFunctions.h"
#include "Sakumas_includes.h"


SKMovingObjectFunctions::SKMovingObjectFunctions():
m_movingTargetMass(0)
{
}


SKMovingObjectFunctions::~SKMovingObjectFunctions(){
    
}

GMVector2D SKMovingObjectFunctions::movingDrawPoint(SKMass* p) const{
    
    // 没った
    if(!m_movingTargetMass){
        throw "ターゲットマスがない";
    }
    int px, py, tx, ty;
    p->getPos(px, py);
    this->m_movingTargetMass->getPos(tx, ty);
    
    GMVector2D pv = GMVector2D(px, py);
    GMVector2D tv = GMVector2D(tx, ty);
    return GMVector2D::Lerp(pv, tv, gPlayScene->getPlayer()->getMovingTime());
}