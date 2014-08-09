//
//  UITemplate.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "UITemplate.h"
#include "SKUserInterface.h"

UITemplate::UITemplate():
m_drawRect(GMRect2D::Empty),
m_distanceOfWindow_String(GMVector2D::One*2),
m_strings_offset(GMVector2D(2, 2)),
m_characterSize(1.0),
m_isShow(true)
{
    
}

UITemplate::~UITemplate(){
}

void UITemplate::setUIRect(const GMRect2D& in){
    m_drawRect = SKUserInterface::convertRatioToPixel(in);
}

// 表示の操作
void UITemplate::setShow(bool flag){
    m_isShow = flag;
}

bool UITemplate::isShow(){
    return m_isShow;
}
