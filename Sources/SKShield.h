//
//  SKShield.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKShield__
#define __Karakuri2_Mac__SKShield__

#include "Karakuri.h"
#include "EpuipmentItem.h"

class ShieldItem: public EpuipmentItem{
    
public:
    ShieldItem();
    virtual ~ShieldItem();
    void hazusu() override;
    void soubi() override;
    CarsorSelectReAction* getSelectReaction() override;
    void getSetumei(std::string& str) override;
    
};

#endif /* defined(__Karakuri2_Mac__SKShield__) */
