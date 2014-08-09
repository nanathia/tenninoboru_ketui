//
//  UITemplate.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__UITemplate__
#define __Karakuri2_Mac__UITemplate__

#include "Karakuri.h"

class UITemplate{
protected:
    // 表示のオン・オフのフラグ
    bool m_isShow;
    // UI枠を描画する領域
    GMRect2D m_drawRect;
    // 枠端から、どの程度開けて文字を描画するか。（ピクセル単位
    GMVector2D m_distanceOfWindow_String;
    // 文字と文字の間に、どの程度の感覚を開けて描画するか。（ピクセル単位
    GMVector2D m_strings_offset;
    // 文字サイズ。14*28 をデフォルト値とした 0~1 の比率で表す。
    double m_characterSize;
    
public:
    UITemplate();
    virtual ~UITemplate();
    
    // UI 表示領域のセット
    void setUIRect(const GMRect2D&);
    // 情報の更新、取りまとめ
    virtual void update(GMInput* input, double deltaTime) = 0;
    // 更新した情報から画面への、テキストの描画。
    virtual void draw(GMSpriteBatch* s) const = 0;
    
public:
    // 表示の操作
    void setShow(bool flag);
    bool isShow();
};

#endif /* defined(__Karakuri2_Mac__UITemplate__) */
