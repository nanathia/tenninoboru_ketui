//
//  SKUdewa.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKUdewa__
#define __Karakuri2_Mac__SKUdewa__

#include "Karakuri.h"
#include "EpuipmentItem.h"

class SKDungeonScene;

class UdewaItem: public EpuipmentItem{
public:
    UdewaItem(SKDungeonScene* scene);
    virtual ~UdewaItem();
    void hazusu() override;
    void soubi() override;
    CarsorSelectReAction* getSelectReaction() override;
    void getSetumei(std::string& str) override;
    
};

#endif /* defined(__Karakuri2_Mac__SKUdewa__) */
