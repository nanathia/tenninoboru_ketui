//
//  UsingItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__UsingItem__
#define __Karakuri2_Mac__UsingItem__

#include "Karakuri.h"
#include "SKItem.h"

class UsingItem: public SKItem{
public:
    // 使用
    UsingItem();
    virtual ~UsingItem();
    virtual void use() = 0;
};

#endif /* defined(__Karakuri2_Mac__UsingItem__) */
