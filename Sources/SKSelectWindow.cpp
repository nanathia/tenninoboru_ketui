//
//  SKSelectWindow.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/08.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSelectWindow.h"
#include "SKDrawFont.h"

namespace selectWindow{
    
//    Window::Window():
//    m_carsor(0),
//    m_rect(GMRect2D(0, 0)),
//    m_Color(GMColor::Black){
//        m_Color.a = 0.7;
//    }
//    Window::~Window(){
//    }
//    void Window::setRectAuto(){
//        if(m_elements.empty()) return;
//        int size = (int)m_elements.size();
//        for(int i = 0; i < size; i++){
//            GMRect2D elemRect = m_elements[i]->getRect();
//            if(i == 0){
//                m_rect = elemRect;
//            }else{
//                m_rect.unionRect(elemRect);
//            }
//        }
//    }
//    Element* Window::update(GMInput *input, double deltaTime){
//        return 0;
//    }
//    void Window::draw(GMSpriteBatch *s){
//        s->draw(0, m_rect, m_Color);
//        int size = (int)m_elements.size();
//        for(int i = 0; i < size; i++){
//            m_elements[i]->draw(s);
//        }
//        m_carsor->draw(s);
//    }
//    GMRect2D Window::getRect() const{
//        return m_rect;
//    }
//    GMColor Window::getColor() const{
//        return m_Color;
//    }
//    void Window::setColor(const GMColor& color){
//        m_Color = color;
//    }
//    void Window::addElement(Element *elem){
//        if(!m_elements.empty()){
//            m_elements[(int)m_elements.size()-1]->setNext(elem);
//            elem->setPrev(m_elements[(int)m_elements.size()-1]);
//        }
//        m_elements.push_back(elem);
//        this->setRectAuto();
//    }
//    
//    Element::Element(Window* window):
//    m_rect(0, 0),
//    m_labelColor(GMColor::Black),
//    m_labelStr(""),
//    m_myWindow(window),
//    m_OnCarsor(0),
//    m_preElement(0),
//    m_nextElement(0){
//    }
//    Element::~Element(){
//    }
//    void Element::draw(GMSpriteBatch *s){
//        SKDrawFont::drawString(m_labelStr, m_rect.height, GMVector2D(m_rect.x, m_rect.y), 0, s);
//    }
//    GMRect2D Element::getRect() const{
//        return m_rect;
//    }
//    void Element::setRect(const GMRect2D& rect){
//        m_rect = rect;
//    }
//    GMColor Element::getColor() const{
//        return m_labelColor;
//    }
//    void Element::setColor(const GMColor& color){
//        m_labelColor = color;
//    }
//    std::string Element::getLabel() const{
//        return m_labelStr;
//    }
//    void Element::setLabel(const std::string& label){
//        m_labelStr = label;
//    }
//    Element* Element::getNext(){
//        return m_nextElement;
//    }
//    Element* Element::getPrev(){
//        return m_preElement;
//    }
//    void Element::setNext(Element* next){
//        m_nextElement = next;
//    }
//    void Element::setPrev(Element* prev){
//        m_preElement = prev;
//    }
//    Carsor* Element::getCarsor() const{
//        return m_OnCarsor;
//    }
//    void Element::setCarsor(Carsor *carsor){
//        m_OnCarsor = carsor;
//    }

}