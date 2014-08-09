//
//  State_Nomal_Key.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__State_Nomal_Key__
#define __Karakuri2_Mac__State_Nomal_Key__

#include "Karakuri.h"
#include "State_Key.h"

class State_Nomal_Key : public State_Key{
public:
    State_Nomal_Key();
    ~State_Nomal_Key();
    
public:
    State_Key* update_key(GMInput* input, double deltaTime) override;
    
};

#endif /* defined(__Karakuri2_Mac__State_Nomal_Key__) */
