//
//  SKSpeakCharManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSpeakCharManager.h"
#include "SKSpeakCharacter.h"

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

namespace SKSpeakWindow{
    
    CharacterManager::CharacterManager(const std::string& str):
    m_next(0),
    m_prev(0){
        int size = (int)str.size()/3;
        int xPos = 0;
        int yPos = 0;
        auto it = m_Characters.begin();
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
                newChar->setPrev(m_Characters.back());
                m_Characters.back()->setNext(newChar);
            }
            xPos++;
            m_Characters.push_back(newChar);
            it++;
        }
    }
    CharacterManager::~CharacterManager(){
        if(!m_Characters.empty()){
            auto it = m_Characters.begin();
            while(it != m_Characters.end()){
                delete (*it);
                *it = 0;
                it++;
            }
            m_Characters.clear();
        }
    }
    void CharacterManager::update(GMInput *input, double deltaTime){
        if(!m_Characters.empty()){
            auto it = m_Characters.begin();
            while(it != m_Characters.end()){
                (*it)->update(input, deltaTime);
                it++;
            }
            it = m_Characters.begin();
            while(it != m_Characters.end()){
                if((*it)->isVanished()){
                    delete (*it);
                    *it = 0;
                    it = m_Characters.erase(it);
                    continue;
                }
                it++;
            }
        }
    }
    void CharacterManager::draw(GMSpriteBatch *s){
        if(!m_Characters.empty()){
            auto it = m_Characters.begin();
            while(it != m_Characters.end()){
                (*it)->draw(s);
                it++;
            }
        }
    }
    bool CharacterManager::isHolded(){
        if(!m_Characters.empty()){
            auto it = m_Characters.begin();
            while(it != m_Characters.end()){
                if(!(*it)->isStill()){
                    return false;
                }
                it++;
            }
        }
        return true;
    }
    bool CharacterManager::isVanished() const{
        return m_Characters.empty();
    }
    void CharacterManager::goUnderLava(){
        if(!m_Characters.empty()){
            auto it = m_Characters.begin();
            while(it != m_Characters.end()){
                (*it)->ill_Be_Back();
                it++;
            }
        }
    }
    void CharacterManager::setNext(CharacterManager* next){
        m_next = next;
    }
    void CharacterManager::setPrev(SKSpeakWindow::CharacterManager *prev){
        m_prev = prev;
    }
    
}