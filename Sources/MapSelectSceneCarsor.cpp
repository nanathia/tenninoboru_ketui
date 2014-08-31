//
//  MapSelectSceneCarsor.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSources.h"
#include "MapSelectSceneCarsorState.h"

namespace mapSelect{
    
    SelectCarsor::SelectCarsor(SelectObj* firstSelect, SKMapSelectScene* parent):
    m_parent(parent),
    m_state(0){
        m_state = new SelectCarsorState(firstSelect, this);
    }
    SelectCarsor::~SelectCarsor(){
        delete m_state;
        m_state = 0;
    }
    void SelectCarsor::update(GMInput *input, double deltaTime){
        m_state->update(input, deltaTime);
    }
    void SelectCarsor::draw(GMSpriteBatch *s){
        m_state->draw(s);
    }
    SKMapSelectScene* SelectCarsor::getScene(){
        return m_parent;
    }
    SelectObj* SelectCarsor::getCurrentObj(){
        return m_state->getCurrentObj();
    }
    
}