//
//  MessageUI.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MessageUI.h"
#include "SaKumas_includes.h"
#include "SKFont.h"
using namespace sizurus_fonts;

MessageUI::MessageUI():
m_messageCount(0)
{
    
}

MessageUI::~MessageUI(){
    
}

void MessageUI::update(GMInput *input, double deltaTime){
    // TODO: メッセージUIの実装

    if(m_message != ""){
        if(m_messages.empty()){
            m_messageCount += deltaTime/2;
        }else{
           m_messageCount += deltaTime*3;
        }
    }
    if(m_messageCount >= 1){
        m_messageCount = 0;
        m_message = "";
    }
    if(m_message=="" && !m_messages.empty()){
        m_message = *m_messages.begin();
        m_messages.erase(m_messages.begin());
    }
}

void MessageUI::draw(GMSpriteBatch *s) const{
    // TODO:
    if(m_message == "") return;
    
    SizurusFontsName fonts[256];
    std::string str = m_message;
    SKFont::convertChar2Name(fonts, str);
    int i = 0;
    
    GMColor c = GMColor::White;
    gPlayScene->getDungeonScene()->getTexMan()->get(Texture_messageName)->getSize();
    s->draw(gPlayScene->getDungeonScene()->getTexMan()->get(Texture_messageName), GMRect2D(50, 0, SCREEN_SIZE.x-100, 150), GMRect2D(0, gPlayScene->getDungeonScene()->getTexMan()->get(Texture_messageName)->getSize()), c);
    
    while(fonts[i] != sizurusFonts_end){
        SKFont::drawString_toWindow(fonts[i], GMRect2D(50*(i+1), 100, 50, 50), s);
        i++;
    }
    
}

void MessageUI::textInput(const std::string& str){
    m_messages.push_back(str);
    if(m_messages.size() == 20){
        GMException( "アイテム確保過多" );
    }
}
