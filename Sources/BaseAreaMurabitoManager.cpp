//
//  BaseAreaMurabitoManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaMurabitoManager.h"

namespace baseArea{
    
    BaseAreaMurabitoManager::BaseAreaMurabitoManager(BaseAreaMap* parent):
    m_parent(parent){
        
    }
    BaseAreaMurabitoManager::~BaseAreaMurabitoManager(){
        if(m_Murabitos.empty()) return;
        auto it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            delete *it;
            *it = 0;
            it++;
        }
        m_Murabitos.clear();
    }
    void BaseAreaMurabitoManager::update(GMInput* input, double deltaTime){
        auto it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            (*it)->update(input, deltaTime);
            it++;
        }
    }
    void BaseAreaMurabitoManager::draw(GMSpriteBatch* s){
        auto it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            (*it)->draw(GMSpriteBatch* s);
            it++;
        }
    }
    BaseAreaMap* BaseAreaMurabitoManager::getBaseAreaMap(){
        return m_parent;
    }
    std::list<BaseAreaMurabito*>& BaseAreaMurabitoManager::getMurabitos(){
        return m_Murabitos;
    }
    void BaseAreaMurabitoManager::add(BaseAreaMurabito* murabito){
        m_Murabitos.push_back(murabito);
    }
    
}