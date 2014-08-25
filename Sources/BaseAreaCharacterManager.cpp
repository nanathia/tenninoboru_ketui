//
//  BaseAreaCharacterManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/21.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"

namespace baseArea{
    
    CharacterManager::CharacterManager(SKBaseAreaScene* parent):
    m_Player(0),
    m_Murabitos(0),
    m_parent(parent){
        m_Player = new Player(parent);
    }
    CharacterManager::~CharacterManager(){
        delete m_Player;
        m_Player = 0;
    }
    void CharacterManager::update(GMInput *input, double deltaTime){
        m_Player->update(input, deltaTime);
    }
    void CharacterManager::draw(GMSpriteBatch *s){
        m_Player->draw(s);
    }
    Player* CharacterManager::getPlayer(){
        return m_Player;
    }
    MurabitoManager* CharacterManager::getMurabitoMan(){
        return m_Murabitos;
    }
    
}