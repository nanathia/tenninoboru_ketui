//
//  NenryouItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__NenryouItem__
#define __Karakuri2_Mac__NenryouItem__

#include "Karakuri.h"
#include "UsingItem.h"

class SKDungeonScene;

class NenryouItem: public UsingItem{
    
public:
    NenryouItem(SKDungeonScene* scene);
    ~NenryouItem();
    void use() override;
    CarsorSelectReAction* getSelectReaction() override;
    void getSetumei(std::string& str) override;
    
};

#endif /* defined(__Karakuri2_Mac__NenryouItem__) */
