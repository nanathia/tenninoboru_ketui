//
//  MapSelectSceneSelectObjManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSources.h"

namespace mapSelect{
    
    SelectObjManager::SelectObjManager(SKMapSelectScene* scene):
    m_parent(scene){
        
    }
    SelectObjManager::~SelectObjManager(){
        if(m_data.empty()) return;
        auto it = m_data.begin();
        while(it != m_data.end()){
            delete *it;
            *it = 0;
            it++;
        }
        m_data.clear();
    }
    void SelectObjManager::update(GMInput *input, double deltaTime){
        if(m_data.empty()) return;
        auto it = m_data.begin();
        while(it != m_data.end()){
            (*it)->update(input, deltaTime);
            it++;
        }
    }
    void SelectObjManager::draw(GMSpriteBatch *s){
        if(m_data.empty()) return;
        auto it = m_data.begin();
        while(it != m_data.end()){
            (*it)->draw(s);
            it++;
        }
    }
    void SelectObjManager::add(mapSelect::SelectObj *obj){
        if(!obj) GMException("error: add To Null Pointer SelectObj.");
        if(!m_data.empty()){
            m_data.back()->setNext(obj);
            obj->setPrev(m_data.back());
        }
        m_data.push_back(obj);
        m_data.back()->setNext(m_data.front());
        m_data.front()->setPrev(m_data.back());
    }
    
}