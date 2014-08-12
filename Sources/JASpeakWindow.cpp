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
#include "JASpeakWindowState.h"
#include <string>

namespace{
    bool len(const char* _1, const char* _2){
        if(_1[0] == _2[0]){
            if(_1[1] == _2[1] && _1[2] == _2[2]){
                return true;
            }
        }
        return false;
    }
}

namespace JASpeakWindow{
    
    Window::Window():
    m_WindowRect(GMRect2D(25, 25, 950, 150)),
    m_color(GMColor::Black),
    m_state(0),
    m_characters(new std::vector<Character*>),
    m_characters_2(new std::vector<Character*>),
    m_returnKey(-1),
    m_nextReturnKey(-1)
    {
        m_color.a = 0.5;
        m_state = new WindowState(this);
    }
    Window::~Window(){
        int size = (int)m_characters->size();
        for(int i = 0; i < size; i++){
            delete (*m_characters)[i];
            (*m_characters)[i] = 0;
        }
        safeCleanUp(*m_characters);
        (*m_characters).clear();
        if(m_characters_2) delete m_characters_2;
        m_characters_2 = 0;
        if(m_characters) delete m_characters;
        m_characters = 0;
    }
    int Window::update(GMInput* input, double deltaTime){
        m_state->update(input, deltaTime);
        int size = (int)(*m_characters).size();
        for(int i = 0; i < size; i++){
            (*m_characters)[i]->update(input, deltaTime);
        }
        size = (int)(*m_characters_2).size();
        for(int i = 0; i < size; i++){
            (*m_characters_2)[i]->update(input, deltaTime);
        }
        int ret = m_returnKey;
        return ret;
    }
    void Window::draw(GMSpriteBatch* s){
        m_state->draw(s);
        int size = (int)(*m_characters).size();
        for(int i = 0; i < size; i++){
            (*m_characters)[i]->draw(s);
        }
        size = (int)(*m_characters_2).size();
        for(int i = 0; i < size; i++){
            (*m_characters_2)[i]->draw(s);
        }
    }
    void Window::setString(const std::string& str){
        if(!(*m_characters).empty()){
            int size = (int)(*m_characters).size();
            for(int i = 0; i < size; i++){
                delete (*m_characters)[i];
                (*m_characters)[i] = 0;
            }
            safeCleanUp((*m_characters));
            (*m_characters).clear();
        }
        int size = (int)str.size()/3;
        int xPos = 0;
        int yPos = 0;
        for(int i = 0; i < size; i++){
            if(xPos >= 19){
                xPos = 0;
                yPos++;
            }
            const char* cStr = &(str.c_str()[i*3]);
            if(len(cStr, "漸")){
                xPos = 0;
                yPos++;
                continue;
            }
            char destStr[256];
            destStr[0] = cStr[0];
            destStr[1] = cStr[1];
            destStr[2] = cStr[2];
            destStr[3] = '\0';
            Character* newChar = new Character(destStr, GMVector2D(xPos*50+50, 150-yPos*50));
            newChar->setNextLunchInterval(0.1);
            newChar->setCompleteTime(1);
            if(i != 0){
                newChar->setPrev((*m_characters)[(int)(*m_characters).size()-1]);
                (*m_characters)[(int)(*m_characters).size()-1]->setNext(newChar);
            }
            xPos++;
            (*m_characters).push_back(newChar);
        }
    }
    std::vector<Character*>& Window::getCharacters(){
        return (*m_characters);
    }
    GMColor Window::getColor() const{
        return m_color;
    }
    void Window::setColor(const GMColor& color){
        m_color = color;
    }
    GMRect2D Window::getRect() const{
        return m_WindowRect;
    }
    void Window::setRect(const GMRect2D& rect){
        m_WindowRect = rect;
    }
    void Window::addString(const string& str){
        m_chargeStrs.push_back(str);
    }
    std::deque<StrQuotation>& Window::getChargeStrs(){
        return m_chargeStrs;
    }
    void Window::allCharacterGoUnderLava(){
        int size = (int)(*m_characters).size();
        for(int i = 0; i < size; i++){
            (*m_characters)[i]->ill_Be_Back();
        }
        if(!m_chargeStrs.empty()){
            m_nextReturnKey = m_chargeStrs.front().getQuota();
        }else{
            m_nextReturnKey = -1;
        }
        this->push();
    }
    std::vector<Character*>& Window::getCharacters_2(){
        return *m_characters_2;
    }
    void Window::push(){
        if(m_characters_2) delete m_characters_2;
        m_characters_2 = m_characters;
        m_characters = new std::vector<Character*>;
        if(!m_chargeStrs.empty()){
            this->setString(m_chargeStrs.front().getStr());
            m_chargeStrs.pop_front();
        }
    }
    bool Window::isAllCharacterStilled(){
        return m_state->isAllCharacterStilled();
    }
    void Window::addString(const std::string &str, int key){
        m_chargeStrs.push_back(StrQuotation(str, key));
    }
    void Window::setNextReturnKey(int key){
        m_nextReturnKey = key;
    }
    void Window::setReturnKey(){
        m_returnKey = m_nextReturnKey;
    }
    int Window::getKey(){
        return m_returnKey;
    }
    void Window::setKey(int key){
        m_returnKey = key;
        m_nextReturnKey = -1;
    }
    
}