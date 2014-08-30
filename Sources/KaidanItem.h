//
//  KaidanItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__KaidanItem__
#define __Karakuri2_Mac__KaidanItem__

#include "Karakuri.h"
#include "SKItem.h"

class SKDungeonScene;

class KaidanItem: public SKItem{
public:
    KaidanItem(SKDungeonScene* scene);
    virtual ~KaidanItem();
    void noru();
    void getSetumei(std::string& strIn) override;
    CarsorSelectReAction* getSelectReaction() override;

};

#endif /* defined(__Karakuri2_Mac__KaidanItem__) */
