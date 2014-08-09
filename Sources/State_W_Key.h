//
//  State_W_Key.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__State_W_Key__
#define __Karakuri2_Mac__State_W_Key__

#include "Karakuri.h"
#include "State_Key.h"
#include "SKKeyHandler.h"

class State_W_Key: public State_Key{
    
public:
    State_W_Key();
    ~State_W_Key();
    
public:
    State_Key* update_key(GMInput* input, double deltaTime) override;
    
};

#endif /* defined(__Karakuri2_Mac__State_W_Key__) */
