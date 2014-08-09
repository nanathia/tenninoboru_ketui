//
//  SKMovingObjectFunctions.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/08.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMovingObjectFunctions__
#define __Karakuri2_Mac__SKMovingObjectFunctions__

#include "Karakuri.h"
#include "SaKumas_includes.h"
#include "randam_dungeon.h"

class SKMovingObjectFunctions{
protected:
    SKMass* m_movingTargetMass;

public:
    // マス移動中の描画位置補間
    GMVector2D movingDrawPoint(SKMass* point) const;
    
public:
    SKMovingObjectFunctions();
    ~SKMovingObjectFunctions();
    // 部屋内かどうか。そうでない場合はNULLを返す
//    _room* isInRoom();
};

#endif /* defined(__Karakuri2_Mac__SKMovingObjectFunctions__) */
