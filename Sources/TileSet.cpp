//
//  TileSet.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "TileSet.h"
#include "tinyxml2.h"

namespace baseArea{
    
    TileSetTile::TileSetTile(tinyxml2::XMLElement* data, TileSet* parent):
    m_parent(parent),
    m_isCollision(0),
    m_nextTile(0),
    m_Id(data->IntAttribute("id")){
        tinyxml2::XMLElement* c = data->FirstChildElement();
        while(c){
            std::string name = c->Name();
            if(name == "properties"){
                tinyxml2::XMLElement* c2 = c->FirstChildElement();
                while(c2){
                    std::string name2 = c2->Attribute("name");
                    if(name2 == "collision"){
                        m_isCollision = c2->IntAttribute("value");
                    }else if(name2 == "intervalTile"){
                        if(!m_nextTile) m_nextTile = new nextTile;
                        m_nextTile->m_interval = c2->IntAttribute("value");
                    }else if(name2 == "nextTile"){
                        if(!m_nextTile) m_nextTile = new nextTile;
                        c2->QueryIntAttribute("value", &m_nextTile->m_offsetX);
                    }
                    c2 = c2->NextSiblingElement();
                }
            }
            c = c->NextSiblingElement();
        }
    }
    TileSetTile::~TileSetTile(){
        if(m_nextTile) delete m_nextTile;
        m_nextTile = 0;
    }
    
    TileSetImage::TileSetImage(tinyxml2::XMLElement* data, TileSet* parent):
    m_parent(parent),
    m_tex(new GMTexture2D(data->Attribute("source"))),
    m_TileSetWidth(data->IntAttribute("width")),
    m_TileSetHeight(data->IntAttribute("height")),
    m_TileYNum(this->m_TileSetHeight/parent->getTileHeight()),
    m_TileXNum(this->m_TileSetWidth/parent->getTileWidth()),
    m_TileOrigin(parent->getTileWidth(), parent->getTileHeight())
    {
    }
    TileSetImage::~TileSetImage(){
        delete m_tex;
        m_tex = 0;
    }
    void TileSetImage::draw(GMSpriteBatch* s, const GMRect2D &dest, int gid) const{
        if(!gid) return;
        gid -= m_parent->getFirstGit();
        GMRect2D src(
                     (gid%m_TileXNum)*m_parent->getTileWidth(),
                     (gid/m_TileXNum)*m_parent->getTileHeight(),
                     m_parent->getTileWidth(),
                     m_parent->getTileHeight());
        s->draw(m_tex, dest, src, GMColor::White);
    }
    void TileSetImage::draw(GMSpriteBatch* s, const GMRect2D &_dest, double radian, int gid) const{
        if(!gid) return;
        gid -= m_parent->getFirstGit();
        GMRect2D dest(_dest.x, _dest.y, _dest.width, _dest.height);
        if(radian==0.5*M_PI || radian == -0.5*M_PI){
            dest.width = _dest.height;
            dest.height = _dest.width;
        }
        if(radian == -0.5*M_PI){
            dest.y+=dest.width;
        }else if(radian == 0.5*M_PI){
            dest.x+=dest.height;
        }
        GMRect2D src(
                     (gid%m_TileXNum)*m_parent->getTileWidth(),
                     (gid/m_TileXNum)*m_parent->getTileHeight(),
                     m_parent->getTileWidth(),
                     m_parent->getTileHeight());
        s->draw(m_tex, dest, src, GMColor::White, radian, 0, GMSpriteFlipHorizontally);
    }
    int TileSetImage::getTileSetWidth() const{
        return m_TileSetWidth;
    }
    int TileSetImage::getTileSetHeight() const{
        return m_TileSetHeight;
    }
    int TileSetImage::getTileXNum() const{
        return m_TileXNum;
    }
    int TileSetImage::getTileYNum() const{
        return m_TileYNum;
    }
    
    TileSet::TileSet(tinyxml2::XMLElement* data, TileSetManager* parent):
    m_parent(parent),
    m_FirstGid(data->IntAttribute("firstgid")),
    m_Name(data->Attribute("name")),
    m_TileHeight(data->IntAttribute("tilewidth")),
    m_TileWidth(data->IntAttribute("tileheight")),
    m_Image(0)
    {
        tinyxml2::XMLElement* c = data->FirstChildElement();
        while(c){
            std::string name = c->Name();
            if(name == "image"){
               if(m_Name!="number") m_Image = new TileSetImage(c, this);
            }if(name == "tile"){
            }
            c = c->NextSiblingElement();
        }
    }
    TileSet::~TileSet(){
        delete m_Image;
        m_Image = 0;
    }
    int TileSet::getTileHeight() const{
        return m_TileHeight;
    }
    int TileSet::getTileWidth() const{
        return m_TileWidth;
    }
    int TileSet::getFirstGit() const{
        return m_FirstGid;
    }
    const std::string& TileSet::getName() const{
        return m_Name;
    }
    TileSetImage* TileSet::getImage(){
        return m_Image;
    }
    TileSetManager* TileSet::getManager(){
        return m_parent;
    }
    
}