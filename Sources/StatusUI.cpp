//
//  StatusUI.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "StatusUI.h"
#include "SaKumas_includes.h"
#include "GameMain.h"
#include <sstream>


StatusUI::StatusUI(){
    
}

StatusUI::~StatusUI(){
    
}

void StatusUI::update(GMInput *input, double deltaTime){
    
}

void StatusUI::draw(GMSpriteBatch *s) const{
    GMColor c = GMColor::SkyBlue;
    c.a = 0.2;
    
    s->draw(0, GMVector2D(50, SCREEN_SIZE.y-100), GMRect2D(50, SCREEN_SIZE.y-100, SCREEN_SIZE.x-100, 100), c);
    
    // TODO: ステータスUIの実装
    GMFont* f = gGameInst->getFont();
    std::ostringstream oss;
    oss << " " << gPlayScene->getMassMan()->getKaisou() << "F  "
    << "Lv" << 1
    << "  HP" << gPlayScene->getPlayer()->getHp()
    << "/" << 100
    << "      " << 0 << "G";
    std::string str = oss.str();
    f->drawString(s, str, GMVector2D(50, SCREEN_SIZE.y - 50));
}