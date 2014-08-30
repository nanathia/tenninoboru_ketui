//
//  SKSceneChangeInters.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSceneChangeInters.h"
#include "SKPlayChild.h"
#include "SKPlayScene.h"
#include "Globals.h"

namespace playsceneinter{
    
    Dungeon::Dungeon(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
    SKPlaySceneInter(prevChild, nextChild, user){
        
    }
    Dungeon::~Dungeon(){
        
    }
    SKPlaySceneStateChild* Dungeon::update(GMInput* input, double deltaTime){
        SKPlaySceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = new SKPlaySceneGame(m_user);
        }
        return next;
    }
    void Dungeon::draw(GMSpriteBatch* s){
        m_nextChild->draw(s);
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        s->end();
        gPlayScene->getCurrentEffect()->end();
    }
    
    MapSelect::MapSelect(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
    SKPlaySceneInter(prevChild, nextChild, user){
        
    }
    MapSelect::~MapSelect(){
        
    }
    SKPlaySceneStateChild* MapSelect::update(GMInput* input, double deltaTime){
        SKPlaySceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = new SKPlaySceneGame(m_user);
        }
        return next;
    }
    void MapSelect::draw(GMSpriteBatch* s){
        m_nextChild->draw(s);
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        s->end();
        gPlayScene->getCurrentEffect()->end();
    }
    
    BaseArea::BaseArea(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
    SKPlaySceneInter(prevChild, nextChild, user){
        
    }
    BaseArea::~BaseArea(){
        
    }
    SKPlaySceneStateChild* BaseArea::update(GMInput* input, double deltaTime){
        SKPlaySceneStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            next = new SKPlaySceneGame(m_user);
        }
        return next;
    }
    void BaseArea::draw(GMSpriteBatch* s){
        m_nextChild->draw(s);
        GMColor blue = GMColor::Blue;
        blue.a = 1-m_time;
        gPlayScene->getCurrentEffect()->begin();
        s->begin();
        s->fill(GMRect2D(0, SCREEN_SIZE), blue);
        s->end();
        gPlayScene->getCurrentEffect()->end();
    }
    
}