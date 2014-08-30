//
//  SKSword.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKSword__
#define __Karakuri2_Mac__SKSword__

#include "Karakuri.h"
#include "EpuipmentItem.h"

class SKDungeonScene;

class SwordItem: public EpuipmentItem{
    
public:
    SwordItem(SKDungeonScene* scene);
    virtual ~SwordItem();
    void getSetumei(std::string& str) override;
    void hazusu() override;
    void soubi() override;
    CarsorSelectReAction* getSelectReaction() override;
    
};

#endif /* defined(__Karakuri2_Mac__SKSword__) */
