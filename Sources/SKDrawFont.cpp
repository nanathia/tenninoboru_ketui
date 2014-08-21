//
//  SKDrawFont.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/18.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SaKumas_includes.h"
#include "SKDrawFont.h"
#include "SKFont.h"
#include <string>

using namespace sizurus_fonts;

void SKDrawFont::drawString(const std::string& str, const GMVector2D& charSize, const GMVector2D& strPos, const GMVector2D& strWidth, GMSpriteBatch* s, GMColor c){
    SizurusFontsName fonts[256];
    ten_flags flags[256];
    sizurus_fonts::SKFont::convertChar2Name(fonts, str);
    int i = 0;
    
    while(fonts[i] != sizurusFonts_end){
        sizurus_fonts::SKFont::drawString_toWindow(fonts[i], GMRect2D(strPos.x+charSize.x*i, strPos.y, charSize.x, charSize.y), s, c);
        if(flags[i] == dakuten){
            sizurus_fonts::SKFont::drawString_toWindow(濁点, GMRect2D(strPos.x+charSize.x*i, strPos.y, charSize.x, charSize.y), s, c);
        }
        i++;
    }
}