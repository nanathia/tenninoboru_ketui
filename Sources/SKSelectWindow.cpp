//
//  SKSelectWindow.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/08.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSelectWindow.h"
#include "SKDrawFont.h"
#include "SaKumas_includes.h"
#include "GameMain.h"
#include "SKTitle.h"
#include "SKPlayScene.h"
#include "SKSoundManager.h"
#include "SKMusicManager.h"

namespace selectWindow{
    
    Window::Window():
    m_carsor(0),
    m_rect(GMRect2D(0, 0)),
    m_Color(GMColor::Black){
        m_Color.a = 0.5;
    }
    Window::~Window(){
        int size = (int)m_elements.size();
        for(int i = 0; i < size; i++){
            delete m_elements[i];
            m_elements[i] = 0;
        }
        safeCleanUp(m_elements);
        delete m_carsor;
        m_carsor = 0;
    }
    void Window::setRectAuto(){
        if(m_elements.empty()) return;
        int size = (int)m_elements.size();
        for(int i = 0; i < size; i++){
            GMRect2D elemRect = m_elements[i]->getRect();
            if(i == 0){
                m_rect = elemRect;
            }else{
                m_rect = m_rect.unionRect(elemRect);
            }
        }
    }
    Element* Window::update(GMInput *input, double deltaTime){
        return m_carsor->update(input, deltaTime);
    }
    void Window::draw(GMSpriteBatch *s){
        s->draw(0, m_rect, m_Color);
        int size = (int)m_elements.size();
        for(int i = 0; i < size; i++){
            m_elements[i]->draw(s);
        }
        m_carsor->draw(s);
    }
    GMRect2D Window::getRect() const{
        return m_rect;
    }
    GMColor Window::getColor() const{
        return m_Color;
    }
    void Window::setColor(const GMColor& color){
        m_Color = color;
    }
    void Window::addElement(Element *elem){
        if(!m_elements.empty()){
            m_elements[(int)m_elements.size()-1]->setNext(elem);
            elem->setPrev(m_elements[(int)m_elements.size()-1]);
        }
        m_elements.push_back(elem);
        this->setRectAuto();
    }
    std::vector<Element*>& Window::getElements(){
        return m_elements;
    }
    void Window::setCarsor(Carsor* carsor){
        m_carsor = carsor;
    }
    
    Element::Element(Window* window):
    m_rect(0, 0),
    m_labelColor(GMColor::White),
    m_labelStr(""),
    m_myWindow(window),
    m_OnCarsor(0),
    m_preElement(0),
    m_nextElement(0){
    }
    Element::~Element(){
    }
    void Element::draw(GMSpriteBatch *s){
        SKDrawFont::drawString(m_labelStr, m_rect.height, GMVector2D(m_rect.x, m_rect.y), 0, s);
    }
    GMRect2D Element::getRect() const{
        return m_rect;
    }
    void Element::setRect(const GMRect2D& rect){
        m_rect = rect;
    }
    GMColor Element::getColor() const{
        return m_labelColor;
    }
    void Element::setColor(const GMColor& color){
        m_labelColor = color;
    }
    std::string Element::getLabel() const{
        return m_labelStr;
    }
    void Element::setLabel(const std::string& label){
        m_labelStr = label;
    }
    Element* Element::getNext(){
        return m_nextElement;
    }
    Element* Element::getPrev(){
        return m_preElement;
    }
    void Element::setNext(Element* next){
        m_nextElement = next;
    }
    void Element::setPrev(Element* prev){
        m_preElement = prev;
    }
    Carsor* Element::getCarsor() const{
        return m_OnCarsor;
    }
    void Element::setCarsor(Carsor *carsor){
        m_OnCarsor = carsor;
    }
    
    Carsor::Carsor(Window* window):
    m_Color(GMColor::White),
    m_Window(window),
    m_UnderElement(0){
        m_Color.a = 0.5;
    }
    Carsor::~Carsor(){
    }
    Element* Carsor::update(GMInput* input, double deltaTime){
        if(!m_UnderElement){
            GMException("うにゃにゃー");
        }
        if(input->isKeyDownTriggered(GMKeyMaskZ | GMKeyMaskReturn)){
            // 決定キーが押された。
            // 現在選択エレメントを返す。
            if(dynamic_cast<SKTitle*>(gGameInst->GetCurrentScene())){
                gTitleScene->getSoundMan()->get(SoundName_Selected)->play();
            }else if(dynamic_cast<SKPlayScene*>(gGameInst->GetCurrentScene())){
                // TODO::タイトルセレクト音再生の実装。
            }
            return m_UnderElement;
        }
        if(input->isKeyDownTriggered(GMKeyMaskLeft | GMKeyMaskUp)){
            m_UnderElement->setCarsor(0);
            if(m_UnderElement->getPrev()){
                m_UnderElement = m_UnderElement->getPrev();
            }else{
                m_UnderElement = m_Window->getElements()[m_Window->getElements().size()-1];
            }
            m_UnderElement->setCarsor(this);
            if(dynamic_cast<SKTitle*>(gGameInst->GetCurrentScene())){
                gTitleScene->getSoundMan()->get(SoundName_SelectChange)->play();
            }else if(dynamic_cast<SKPlayScene*>(gGameInst->GetCurrentScene())){
            }
        }else if(input->isKeyDownTriggered(GMKeyMaskRight | GMKeyMaskDown)){
            m_UnderElement->setCarsor(0);
            if(m_UnderElement->getNext()){
                m_UnderElement = m_UnderElement->getNext();
            }else{
                m_UnderElement = m_Window->getElements()[0];
            }
            m_UnderElement->setCarsor(this);
            if(dynamic_cast<SKTitle*>(gGameInst->GetCurrentScene())){
                gTitleScene->getSoundMan()->get(SoundName_SelectChange)->play();
            }else if(dynamic_cast<SKPlayScene*>(gGameInst->GetCurrentScene())){
            }
        }
        return 0;
    }
    void Carsor::draw(GMSpriteBatch* s){
        if(!m_UnderElement){
            if(m_Window->getElements().empty()) GMException("はれはれはー");
            m_UnderElement = m_Window->getElements()[0];
        }
        s->draw(0, m_UnderElement->getRect(), m_Color);
    }
    void Carsor::setColor(const GMColor& color){
        m_Color = color;
    }
    GMColor Carsor::getColor() const{
        return m_Color;
    }

}