//
//  GMFont.cpp
//  Game Framework
//
//  Created by numata on Oct 07, 2012.
//  Copyright 2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#include "GMFont.h"


GMFont::GMFont(const std::string& fontImageName, const GMVector2D& charSize)
{
    mTex = new GMTexture2D(fontImageName);
    mCharSize = charSize;
}

GMFont::~GMFont()
{
    delete mTex;
    mTex = 0;
}

void GMFont::drawString(GMSpriteBatch* spriteBatch, const std::string& str, const GMVector2D& pos, const GMColor& color, double layerDepth)
{
    double x = 0.0;
    double y = 0.0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\n') {
            y += mCharSize.y;
        }
    }

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '\n') {
            x = 0.0;
            y -= mCharSize.y;
            continue;
        }
        GMVector2D texPos;
        if (c < '0') {
            texPos.x = mCharSize.x * (c - ' ');
            texPos.y = mCharSize.y * 6;
        }
        else if (c >= '0' && c <= '9') {
            texPos.x = mCharSize.x * (c - '0');
            texPos.y = mCharSize.y * 5;
        }
        else if (c >= ':' && c <= '@') {
            texPos.x = mCharSize.x * (c - ':');
            texPos.y = mCharSize.y * 4;
        }
        else if (c >= 'A' && c <= 'Z') {
            texPos.x = mCharSize.x * (c - 'A');
            texPos.y = mCharSize.y * 3;
        }
        else if (c >= '[' && c <= '`') {
            texPos.x = mCharSize.x * (c - '[');
            texPos.y = mCharSize.y * 2;
        }
        else if (c >= 'a' && c <= 'z') {
            texPos.x = mCharSize.x * (c - 'a');
            texPos.y = mCharSize.y * 1;
        }
        else {
            texPos.x = mCharSize.x * (c - '{');
            texPos.y = mCharSize.y * 0;
        }
        spriteBatch->draw(mTex, GMVector2D(pos.x + x, pos.y + y),
                          GMRect2D(texPos.x, texPos.y, mCharSize.x, mCharSize.y),
                          color, layerDepth);

        x += mCharSize.x;
    }
}

