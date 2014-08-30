//
//  MapSelectSceneState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/30.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSceneState.h"

namespace mapSelect{
    
    SceneState::SceneState(MapSelectScene* user):
    m_child(0){
        m_child = new CarsorMove(user);
    }
    SceneState::~SceneState(){
        delete m_child;
        m_child = 0;
    }
    void SceneState::update(GMInput* input, double deltaTime){
        SceneStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void SceneState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    
    SceneStateChild::SceneStateChild(MapSelectScene*user):
    m_user(user){
    }
    SceneStateChild::~SceneStateChild(){
    }
    
    CarsorMove::CarsorMove(MapSelectScene* user):
    SceneStateChild(user){
    }
    CarsorMove::~CarsorMove(){
    }
    SceneStateChild* CarsorMove::update(GMInput* input, double deltaTime){
        SceneStateChild* next = this;
        return next;
    }
    void CarsorMove::draw(GMSpriteBatch* s){
    };
    
    CarsorBehind::CarsorBehind(MapSelectScene* user):
    SceneStateChild(user){
    }
    CarsorBehind::~CarsorBehind(){
    }
    SceneStateChild* CarsorBehind::update(GMInput* input, double deltaTime){
        SceneStateChild* next = this;
        return next;
    }
    void CarsorBehind::draw(GMSpriteBatch* s){
    };
    
    MapInterYesOrNo::MapInterYesOrNo(MapSelectScene* user):
    SceneStateChild(user){
    }
    MapInterYesOrNo::~MapInterYesOrNo(){
    }
    SceneStateChild* MapInterYesOrNo::update(GMInput* input, double deltaTime){
        SceneStateChild* next = this;
        return next;
    }
    void MapInterYesOrNo::draw(GMSpriteBatch* s){
    };
    
    
}
