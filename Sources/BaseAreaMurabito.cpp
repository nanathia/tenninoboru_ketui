//
//  Murabito.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "tinyxml2.h"
#include "SKSpeakWindow.h"
#include "SpeakStrManager.h"

namespace baseArea{
    namespace{
        Murabito::obj_type convertData2Type(const char* data){
            std::string str = data;
            Murabito::obj_type ret = Murabito::type_bottom;
            if(str == "left"){
                ret = Murabito::type_left;
            }else if(str == "right"){
                ret = Murabito::type_right;
            }else if(str == "top"){
                ret = Murabito::type_top;
            }else if(str == "bottom"){
                ret = Murabito::type_bottom;
            }else if(str == "freeMove"){
                ret = Murabito::type_freeMove;
            }
            return ret;
        }
    }
    
    Murabito::Murabito(tinyxml2::XMLElement* data, BaseAreaMap* parent):
    m_parent(parent),
    m_type(convertData2Type(data->Attribute("type"))),
    m_Rect(0, 0, 1, -1),
    m_speak(0),
    m_Name(data->Name()){
        m_speak = new characterspeak::SpeakStrManager(data);
    }
    Murabito::~Murabito(){
        delete m_speak;
        m_speak = 0;
    }
    void Murabito::update(GMInput *input, double deltaTime){
    }
    void Murabito::draw(GMSpriteBatch *s){
        s->draw(0, GMRect2D(SKBaseAreaScene::convertMat2Draw(GMVector2D(m_Rect.x, m_Rect.y)), SKBaseAreaScene::convertMat2Draw(GMVector2D(m_Rect.width, m_Rect.height))), GMColor::Red);
    }
    void Murabito::setPos(const GMVector2D &pos){
        m_Rect.x = pos.x;
        m_Rect.y = -pos.y;
    }
    const std::string& Murabito::Name() const{
        return m_Name;
    }
    bool Murabito::isCollision(const GMRect2D& rect) const{
        return m_Rect.intersects(rect);
    }
    characterspeak::SpeakStrManager* Murabito::getSpeak(){
        return m_speak;
    }
    
}