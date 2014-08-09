//
//  SKDrawFont.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/18.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKDrawFont__
#define __Karakuri2_Mac__SKDrawFont__

#include "Karakuri.h"

class SKFont;

class SKDrawFont{
    // 生成不要
    SKDrawFont();
    ~SKDrawFont();
    SKDrawFont(const SKDrawFont&);
public:
    static void drawString(const std::string& str, const GMVector2D& charSize, const GMVector2D& strPos, const GMVector2D& strWidth, GMSpriteBatch* s, GMColor c = GMColor::White);
};

#endif /* defined(__Karakuri2_Mac__SKDrawFont__) */
