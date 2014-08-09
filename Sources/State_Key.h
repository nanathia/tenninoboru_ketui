//
//  State_Key.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__State_Key__
#define __Karakuri2_Mac__State_Key__

#include "SKKeyHandler.h"
#include "Karakuri.h"

class State_Key{
    
public:
    virtual ~State_Key();
    virtual State_Key* update_key(GMInput* input, double deltaTime) = 0;
};

#endif /* defined(__Karakuri2_Mac__State_Key__) */
