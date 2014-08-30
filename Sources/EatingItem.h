//
//  EatingItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__EatingItem__
#define __Karakuri2_Mac__EatingItem__

#include "Karakuri.h"
#include "UsingItem.h"

class CarsorSelectReAction;
class SKDungeonScene;

class EatingItem: public UsingItem{
    
public:
    EatingItem(SKDungeonScene* scene);
    void use() override;
    CarsorSelectReAction* getSelectReaction() override;
    void getSetumei(std::string& str) override;
    
};

#endif /* defined(__Karakuri2_Mac__EatingItem__) */
