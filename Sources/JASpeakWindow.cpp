//
//  JASpeakWindow.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "JASpeakWindow.h"
#include "JASpeakCharacter.h"
#include "SaKumas_includes.h"
#include <string>

namespace JASpeakWindow{
    
    Window::Window():
    m_WindowRect(GMRect2D(50, 0, 700, 150)){
        std::string str = "私は、時空亜空。時間と空間の管理者だ。";
        int size = (int)str.size()/3;
        for(int i = 0; i < size; i++){
            const char* cStr = &(str.c_str()[i*3]);
            char destStr[256];
            destStr[0] = cStr[0];
            destStr[1] = cStr[1];
            destStr[2] = cStr[2];
            destStr[3] = '\0';
            m_characters.push_back(new Character(destStr, GMVector2D(i*50+50, 100)));
        }
    }
    Window::~Window(){
        int size = (int)m_characters.size();
        for(int i = 0; i < size; i++){
            delete m_characters[i];
            m_characters[i] = 0;
        }
        safeCleanUp(m_characters);
    }
    void Window::update(GMInput* input, double deltaTime){
        int size = (int)m_characters.size();
        for(int i = 0; i < size; i++){
            m_characters[i]->update(input, deltaTime);
        }
    }
    void Window::draw(GMSpriteBatch* s){
        int size = (int)m_characters.size();
        for(int i = 0; i < size; i++){
            m_characters[i]->draw(s);
        }
    }
    
}