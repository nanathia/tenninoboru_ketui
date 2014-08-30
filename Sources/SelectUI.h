//
//  SelectUI.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SelectUI__
#define __Karakuri2_Mac__SelectUI__

#include "Karakuri.h"
#include "UITemplate.h"
#include "ItemCommandInfo.h"

class SKDungeonScene;

class SelectUI: public UITemplate{
    const int page_max = 20;
    int m_carsor;
    CarsorSelectReAction* m_child;
    SKDungeonScene* m_scene;
    
public:
    SelectUI(SKDungeonScene* scene);
    ~SelectUI();
    
    void UiOn();
    void UiOff();
    bool isUiOpened();
    
    void update(GMInput* input, double deltaTime) override;
    void draw(GMSpriteBatch* s) const override;
};

#endif /* defined(__Karakuri2_Mac__SelectUI__) */
