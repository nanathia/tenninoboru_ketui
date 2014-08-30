//
//  SKUserInterface.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/14.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKUserInterface.h"
#include "SaKumas_includes.h"
#include "Globals.h"
#include "GameMain.h"
#include <sstream>

namespace{
    GMRect2D defaultMessage(0.5, 0.15, 0.85, 0.25);
    GMRect2D defaultStatus(0.5, 0.9, 0.85, 0.15);
    GMRect2D defaultSelectSize(0.5, 0.5, 2.0/3.0, 9.0);
    GMColor briteColor(0, 0, 200, 0.4);
}

SKUserInterface::SKUserInterface(SKDungeonScene* scene):
m_scene(scene),
m_message(0),
m_status(0),
m_select(0),
mSpriteBatch(0)
{
    mSpriteBatch = new GMSpriteBatch();
    m_message = new MessageUI(scene);
    m_select = new SelectUI(scene);
    m_status = new StatusUI(scene);
}

SKUserInterface::~SKUserInterface(){
    delete m_message;
    m_message = 0;
    delete m_select;
    m_select = 0;
    delete m_status;
    m_status = 0;
    
    delete mSpriteBatch;
    mSpriteBatch = 0;
}


std::string SKUserInterface::convertNum2Str(int num){
    std::ostringstream oss;
    oss << num;
    std::string str = oss.str();
    std::string returnStr;
    int size = (int)str.size();
    for(int i = 0; i < size; i++){
        if(str[i] == '0'){
            returnStr += "零";
        }else if(str[i] == '1'){
            returnStr += "一";
        }else if(str[i] == '2'){
            returnStr += "二";
        }else if(str[i] == '3'){
            returnStr += "三";
        }else if(str[i] == '4'){
            returnStr += "四";
        }else if(str[i] == '5'){
            returnStr += "五";
        }else if(str[i] == '6'){
            returnStr += "六";
        }else if(str[i] == '7'){
            returnStr += "七";
        }else if(str[i] == '8'){
            returnStr += "八";
        }else if(str[i] == '9'){
            returnStr += "九";
        }else{
            int* a = 0;
            *a = 1;
        }
    }
    return returnStr;
}

// 画面座標に変換する
GMRect2D SKUserInterface::convertRatioToPixel(const GMRect2D& in){
    GMRect2D rect(in.x*SCREEN_SIZE.x, in.y*SCREEN_SIZE.y, in.width*SCREEN_SIZE.x, in.height*SCREEN_SIZE.y);
    return GMRect2D(rect.x-rect.width/2, rect.y-rect.height/2, rect.width, rect.height);
}

int g_quePos = 0;
double g_flameRates[100] = {0.0};
double g_flameRate = 0;

// 描画する
void SKUserInterface::drawUI() const{
    mSpriteBatch->begin();
    ostringstream oss;
    oss << "FlameRate : " << g_flameRate;
    gGameInst->getFont()->drawString(mSpriteBatch, oss.str().c_str(), GMVector2D(50, SCREEN_SIZE.y-100), GMColor::Red);
    
    if(m_select->isShow()) m_select->draw(mSpriteBatch);
    if(m_status->isShow()) m_status->draw(mSpriteBatch);
    if(m_message->isShow()) m_message->draw(mSpriteBatch);
    
    mSpriteBatch->end();
}

void SKUserInterface::updateUI(GMInput* input, double deltaTime){
    g_flameRates[g_quePos] = 1.0/deltaTime;
    g_quePos++;
    if(g_quePos >= 100){
        g_quePos = 0;
    }
    for(int i = 0; i < 100; i++){
        g_flameRate += g_flameRates[i];
    }
    g_flameRate /= 100.0;
    m_select->update(input, deltaTime);
    m_status->update(input, deltaTime);
    m_message->update(input, deltaTime);
    
}

void SKUserInterface::textInput(const std::string& str){
    m_message->textInput(str);
}

bool SKUserInterface::isMenuOpen(){
    return m_select->isUiOpened();
}

void SKUserInterface::uiOn(){
    m_select->UiOn();
}

void SKUserInterface::uiOff(){
    m_select->UiOff();
}
