//
//  WanaItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__WanaItem__
#define __Karakuri2_Mac__WanaItem__

#include "Karakuri.h"
#include "SKItem.h"

class WanaItem: public SKItem{
public:
    // 踏む
    WanaItem();
    virtual ~WanaItem();
    virtual void humu(){};
    
};

#endif /* defined(__Karakuri2_Mac__WanaItem__) */
