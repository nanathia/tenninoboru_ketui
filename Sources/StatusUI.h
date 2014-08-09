//
//  StatusUI.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__StatusUI__
#define __Karakuri2_Mac__StatusUI__

#include "Karakuri.h"
#include "UITemplate.h"

class StatusUI: public UITemplate{
    
public:
    StatusUI();
    ~StatusUI();
    
    void update(GMInput* input, double deltaTime) override;
    void draw(GMSpriteBatch* s) const override;
};

#endif /* defined(__Karakuri2_Mac__StatusUI__) */
