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
#include <algorithm>

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
    void TileLayer::draw(GMSpriteBatch *s){
        const GMVector2D& p_pos = m_parent->getBaseAreaMap()->getBaseAreaScene()->getCharMan()->getPlayer()->getPos();
        int start_x = std::max(((int)(p_pos.x)-11), 0);
        int end_x = std::min(((int)(p_pos.x)+12), m_width);
        int start_y = std::max(((int)(-p_pos.y)-7), 0);
        int end_y = std::min(((int)(-p_pos.y)+8), m_height);
        for(int y = start_y; y < end_y; y++){
            for(int x = start_x; x < end_x; x++){
                GMVector2D TileDestPoint = SKBaseAreaScene::convertMat2Draw(GMVector2D(x, y));
                m_Tiles[y*m_width+x]->draw(s, GMRect2D(TileDestPoint, SKBaseAreaScene::getTileDestSize()));
            }
        }
    }
    TileLayerManager* TileLayer::getManager(){
        return m_parent;
    }
    const std::string& TileLayer::getName(){
        return m_Name;
    }
    const int TileLayer::getWigth() const{
        return m_width;
    }
    const int TileLayer::getHeight() const{
        return m_height;
    }
    bool TileLayer::isCollision(const GMRect2D& rect) const{
        int start_x = std::max(((int)(rect.x)-2), 0);
        int end_x = std::min(((int)(rect.x)+2), m_width);
        int start_y = std::max(((int)(-rect.y)-2), 0);
        int end_y = std::min(((int)(-rect.y)+2), m_height);
        for(int y = start_y; y < end_y; y++){
            for(int x = start_x; x < end_x; x++){
                if(m_Tiles[y*m_width+x]->getGid()){
                    if(rect.intersects(GMRect2D(x, -y-1, 1, 1))){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
}