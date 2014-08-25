//
//  SKSpeakWindow.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSpeakWindow.h"
#include "SKSpeakCharacter.h"
#include "SaKumas_includes.h"
#include "SKSpeakWindowState.h"
#include <string>


namespace SKSpeakWindow{
    
    Window::Window():
    m_WindowRect(GMRect2D(25, 25, 950, 150)),
    m_color(GMColor::Black),
    m_state(0),
    m_returnKey(-1),
    m_nextReturnKey(-1),
    m_isLockInput(0)
    {
        m_color.a = 0.5;
        m_state = new WindowState(this);
    }
    Window::~Window(){
        delete m_state;
        m_state = 0;
        
        int size = (int)m_Strs.size();
        for(int i = 0; i < size; i++){
            delete m_Strs[i];
            m_Strs[i] = 0;
        }
    }
    int Window::update(GMInput* input, double deltaTime){
        if(!m_isLockInput) m_state->update(input, deltaTime);
        int size = (int)m_Strs.size();
        for(int i = 0; i < size; i++){
            m_Strs[i]->update(input, deltaTime);
        }
        if(!m_Strs.empty()){
            if(m_Strs.back()->isVanished()){
                delete m_Strs.back();
                m_Strs.back() = 0;
                m_Strs.pop_back();
            }
        }
        int ret = m_returnKey;
        return ret;
    }
    void Window::draw(GMSpriteBatch* s){
        m_state->draw(s);
        int size = (int)m_Strs.size();
        for(int i = 0; i < size; i++){
            m_Strs[i]->draw(s);
        }
    }
    CharacterManager* Window::getCharacters(){
        return m_Strs.front();
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
        m_Strs.front()->goUnderLava();
        if(!m_chargeStrs.empty()){
            m_nextReturnKey = m_chargeStrs.front().getQuota();
        }else{
            m_nextReturnKey = -1;
        }
        this->push();
    }
    void Window::push(){
        m_Strs.push_front(new CharacterManager(m_chargeStrs.front().getStr()));
        if(!m_chargeStrs.empty()){
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
    void Window::EnableInput(){
        m_isLockInput = true;
    }
    void Window::DisableInput(){
        m_isLockInput = false;
    }
    void Window::setString(const std::string &str){
        m_Strs.push_front(new CharacterManager(str));
    }
    
}