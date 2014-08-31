//
//  MapSelectSceneSelectObjState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/09/01.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MapSelectSceneSelectObjState.h"
#include "SKDrawFont.h"
#include "MapSelectSources.h"

namespace mapSelect{
    
    SelectObjState::SelectObjState(SelectObj* user):
    m_child(0){
        m_child = new SelectObjSelecting(user);
    }
    SelectObjState::~SelectObjState(){
        delete m_child;
        m_child = 0;
    }
    void SelectObjState::update(GMInput* input, double deltaTime){
        SelectObjStateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void SelectObjState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    
    SelectObjStateChild::SelectObjStateChild(SelectObj*user):
    m_user(user){
    }
    SelectObjStateChild::~SelectObjStateChild(){
    }
    
#pragma mark ---カーソルが乗っている---
    SelectObjSelecting::SelectObjSelecting(SelectObj* user):
    SelectObjStateChild(user),
    m_time(0){
    }
    SelectObjSelecting::~SelectObjSelecting(){
    }
    SelectObjStateChild* SelectObjSelecting::update(GMInput* input, double deltaTime){
        SelectObjStateChild* next = this;
        m_time += deltaTime;
        if(m_time >= 1){
            m_time = 0;
        }
        m_time2 += deltaTime*2;
        if(m_time2 >= 1){
            m_time2 = 1;
        }
        if(!m_user->getCarsor()) next = new SelectObjNoneSelecting(m_user);
        return next;
    }
    void SelectObjSelecting::draw(GMSpriteBatch* s){
        GMColor c = GMColor::White;
        c.a = m_time;
        GMColor blue = GMColor::Red;
        blue.a = m_time2;
        s->draw(m_user->getTex(), m_user->Rect(), GMRect2D(0,m_user->getTex()->getSize()), c, 0, m_user->getTex()->getSize()*0.5, GMSpriteFlipHorizontally);
        SKDrawFont::drawString(m_user->Name().c_str(), GMVector2D(50, 50), GMVector2D(SCREEN_SIZE.x/2-150, SCREEN_SIZE.y-100), 0, s, blue);
    };
    
#pragma mark ---カーソルが乗っていない---
    SelectObjNoneSelecting::SelectObjNoneSelecting(SelectObj* user):
    SelectObjStateChild(user){
    }
    SelectObjNoneSelecting::~SelectObjNoneSelecting(){
    }
    SelectObjStateChild* SelectObjNoneSelecting::update(GMInput* input, double deltaTime){
        SelectObjStateChild* next = this;
        if(m_user->getCarsor()) next = new SelectObjSelecting(m_user);
        return next;
    }
    void SelectObjNoneSelecting::draw(GMSpriteBatch* s){
        GMColor c = GMColor::White;
        s->draw(m_user->getTex(), m_user->Rect(), GMRect2D(0,m_user->getTex()->getSize()), c, 0, m_user->getTex()->getSize()*0.5, GMSpriteFlipHorizontally);
    };
    
    
}
