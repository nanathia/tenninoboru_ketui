//
//  KusaItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__KusaItem__
#define __Karakuri2_Mac__KusaItem__

#include "Karakuri.h"
#include "UsingItem.h"

class SKDungeonScene;

class KusaItem: public UsingItem{
    
public:
    KusaItem(SKDungeonScene* scene);
    void use() override;
    CarsorSelectReAction* getSelectReaction() override;
    void getSetumei(std::string& str) override;
    
};


#endif /* defined(__Karakuri2_Mac__KusaItem__) */
