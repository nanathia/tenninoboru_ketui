//
//  SKSceneChangeOuters.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSceneChangeOuters.h"
#include "SKSceneChangeInters.h"
#include "SKPlaySceneState.h"
#include "Globals.h"

namespace playsceneouter{
    
    Dungeon::Dungeon(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
    SKPlaySceneOuter(prevChild, nextChild, user){
        
    }
    Dungeon::~Dungeon(){
        
    }
    SKPlaySceneStateChild* Dungeon::update(GMInput* input, double deltaTime){
        SKPlaySceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = SKPlaySceneInter::createInter(m_prevChild, m_nextChild, m_user);
        }
        return next;
    }
    void Dungeon::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        s->draw(0, SCREEN_SIZE, blue);
    }
    
    MapSelect::MapSelect(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
    SKPlaySceneOuter(prevChild, nextChild, user){
        
    }
    MapSelect::~MapSelect(){
        
    }
    SKPlaySceneStateChild* MapSelect::update(GMInput* input, double deltaTime){
        SKPlaySceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = SKPlaySceneInter::createInter(m_prevChild, m_nextChild, m_user);
        }
        return next;
    }
    void MapSelect::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        s->draw(0, SCREEN_SIZE, blue);
    }
    
    BaseArea::BaseArea(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
    SKPlaySceneOuter(prevChild, nextChild, user){
        
    }
    BaseArea::~BaseArea(){
        
    }
    SKPlaySceneStateChild* BaseArea::update(GMInput* input, double deltaTime){
        SKPlaySceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = SKPlaySceneInter::createInter(m_prevChild, m_nextChild, m_user);
        }
        return next;
    }
    void BaseArea::draw(GMSpriteBatch* s){
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        s->draw(0, SCREEN_SIZE, blue);
    }
    
}