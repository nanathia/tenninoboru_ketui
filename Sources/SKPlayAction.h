//
//  SKPlayAction.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/07.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKPlayAction__
#define __Karakuri2_Mac__SKPlayAction__

#include "SKPlayChild.h"
#include "Karakuri.h"

class SKPlayAction: public SKPlayChild{
    SKPlayChild* update(GMInput* input, double deltaTime, SKPlayScene* parent) override;
};
#endif /* defined(__Karakuri2_Mac__SKPlayAction__) */
