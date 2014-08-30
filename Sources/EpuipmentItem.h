//
//  EpuipmentItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__EpuipmentItem__
#define __Karakuri2_Mac__EpuipmentItem__

#include "Karakuri.h"
#include "SKItem.h"
#include "SKItemContainar.h"

class SKDungeonScene;

class EpuipmentItem: public SKItem{
protected:
    SKItemContainer* m_containar;
    
public:
    EpuipmentItem(SKDungeonScene* scene);
    virtual ~EpuipmentItem();
    
    // 装備する
    virtual void soubi() = 0;
    // 外す
    virtual void hazusu() = 0;
    
};

#endif /* defined(__Karakuri2_Mac__EpuipmentItem__) */
