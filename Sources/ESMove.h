//
//  ESMove.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/21.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ESMove__
#define __Karakuri2_Mac__ESMove__

#include "EAStrategy.h"

class ESMove: public EAStrategy{
public:
    ESMove();
    virtual ~ESMove();
    bool isMove() override{
        return true;
    }
    
};

#endif /* defined(__Karakuri2_Mac__ESMove__) */
