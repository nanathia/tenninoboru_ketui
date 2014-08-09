//
//  ESSleep.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ESSleep.h"

ESSleep::ESSleep():
EAStrategy(){
    
}

ESSleep::~ESSleep(){
    
}

const char* ESSleep::resetAction(SKEnemy *parent){
    return 0;
}

void ESSleep::action(SKEnemy*){
    return;
}