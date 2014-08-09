//
//  GMFont.h
//  Game Framework
//
//  Created by numata on Oct 07, 2012.
//  Copyright 2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_FONT_H__
#define __GM_FONT_H__

#include "Karakuri.h"

#include <string>


/*!
    @class  GMFont
    @group  Graphics
    テクスチャを元にした等幅フォントを扱うためのクラスです。
    ASCII文字コードに基づいたテクスチャ画像を用意しておき、それを読み込んで文字を描画します。
 */
class GMFont : public GMObject {

    GMTexture2D*    mTex;
    GMVector2D      mCharSize;
    
public:
    /*!
        @method GMFont
        フォント画像のファイル名と、1文字あたりのサイズを指定します。
     */
    GMFont(const std::string& fontImageName, const GMVector2D& charSize);
    ~GMFont();
    
public:
    /*!
        @method drawString
        SpriteBatchを利用して、位置と色を指定して文字列を描画します。
     */
    void    drawString(GMSpriteBatch* spriteBatch, const std::string& str, const GMVector2D& pos, const GMColor& color = GMColor::White, double layerDepth=0.0);
    
};


#endif  //#ifndef __GM_FONT_H__

