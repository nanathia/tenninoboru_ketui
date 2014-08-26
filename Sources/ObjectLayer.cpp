//
//  ObjectLayer.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "tinyxml2.h"
#include <string>


namespace baseArea{
    
    ObjectLayer::ObjectLayer(ObjectLayerManager* parent, tinyxml2::XMLElement* data):
    m_parent(parent),
    m_Name(data->Name()){
        tinyxml2::XMLElement* c = data->FirstChildElement();
        while(c){
            m_Elements.push_back(new MapElement(this, c));
            c = c->NextSiblingElement();
        }
    }
    ObjectLayer::~ObjectLayer(){
        if(!m_Elements.empty()){
            auto it = m_Elements.begin();
            while(it != m_Elements.end()){
                delete *it;
                *it = 0;
                it++;
            }
        }
    }
    void ObjectLayer::update(GMInput *input, double deltaTime){
        
    }
    void ObjectLayer::draw(GMSpriteBatch *s){
        
    }
    
}