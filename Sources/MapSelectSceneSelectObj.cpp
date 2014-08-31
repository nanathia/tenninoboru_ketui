//
//  MapSelectSceneSelectObj.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSources.h"
#include "MapSelectSceneSelectObjState.h"

namespace mapSelect{
    
#pragma mark ---基本の定義---
    SelectObj::SelectObj(SKMapSelectScene* parent, const GMRect2D& rect, GMTexture2D* tex, const std::string& name):
    m_parent(parent),
    m_prev(0),
    m_next(0),
    m_carsor(0),
    m_state(0),
    m_rect(rect),
    m_tex(tex),
    m_name(name){
        m_state = new SelectObjState(this);
    }
    SelectObj::~SelectObj(){
        delete m_state;
        m_state = 0;
    }
    void SelectObj::update(GMInput *input, double deltaTime){
        m_state->update(input, deltaTime);
    }
    void SelectObj::draw(GMSpriteBatch *s){
        m_state->draw(s);
    }
    
#pragma mark ---前後関係連結の定義---
    void SelectObj::setPrev(SelectObj* prev){
        m_prev = prev;
    }
    void SelectObj::setNext(SelectObj* next){
        m_next = next;
    }
    SelectObj* SelectObj::getPrev(){
        return m_prev;
    }
    SelectObj* SelectObj::getNext(){
        return m_next;
    }
    
#pragma mark ---カーソル関係---
    void SelectObj::setCarsor(mapSelect::SelectCarsor *carsor){
        m_carsor = carsor;
    }
    SelectCarsor* SelectObj::getCarsor(){
        return m_carsor;
    }
    
#pragma mark ---親取得---
    SKMapSelectScene* SelectObj::getScene(){
        return m_parent;
    }
    
#pragma mark ---その他定義---
    const std::string& SelectObj::Name() const{
        return m_name;
    }
    const GMRect2D& SelectObj::Rect() const{
        return m_rect;
    }
    GMTexture2D* SelectObj::getTex(){
        return m_tex;
    }
    
}