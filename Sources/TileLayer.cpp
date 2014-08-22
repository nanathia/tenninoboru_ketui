//
//  TileLayer.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "SaKumas_includes.h"
#include "tinyxml2.h"

namespace baseArea{
    
    TileLayer::TileLayer(tinyxml2::XMLElement* data, TileLayerManager* parent):
    m_Name(data->Attribute("name")),
    m_width(data->IntAttribute("width")),
    m_height(data->IntAttribute("height")),
    m_parent(parent)
    {
        tinyxml2::XMLElement* c = data->FirstChildElement();
        while(c){
            std::string name = c->Name();
            if(name == "data"){
                tinyxml2::XMLElement* c2 = c->FirstChildElement();
                while(c2){
                    std::string name2 = c2->Name();
                    if(name2 == "tile"){
                        m_Tiles.push_back(new Tile(c2, this));
                    }
                    c2 = c2->NextSiblingElement();
                }
            }
            c = c->NextSiblingElement();
        }
    }
    TileLayer::~TileLayer(){
        if(!m_Tiles.empty()){
            auto it = m_Tiles.begin();
            while(it != m_Tiles.end()){
                delete *it;
                *it = 0;
                it++;
            }
            safeCleanUp(m_Tiles);
        }
    }
    void TileLayer::update(GMInput *input, double deltaTime){
        
    }
    void TileLayer::draw(GMSpriteBatch *s, const GMRect2D& dest){
        GMVector2D tileDest(dest.width/m_width, dest.height/m_height);
        for(int y = 0; y < m_height; y++){
            for(int x = 0; x < m_width; x++){
                m_Tiles[y*m_width+x]->draw(s, GMRect2D(dest.x + tileDest.x*x, dest.y + tileDest.y*y, tileDest.x, tileDest.y));
            }
        }
    }
    TileLayerManager* TileLayer::getManager(){
        return m_parent;
    }
    
}