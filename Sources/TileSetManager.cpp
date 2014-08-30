//
//  TileSetManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "TileSetManager.h"
#include "TileSet.h"
#include "SaKumas_includes.h"
#include "tinyxml2.h"

namespace baseArea{
    
    TileSetManager::TileSetManager(BaseAreaMap* parent):
    m_parent(parent){
        
    }
    TileSetManager::~TileSetManager(){
        int size = (int)m_TileSet.size();
        for(int i = 0; i < size; i++){
            delete m_TileSet[i];
            m_TileSet[i] = 0;
        }
        safeCleanUp(m_TileSet);
    }
    void TileSetManager::update(GMInput* input, double deltaTime){
        
    }
    void TileSetManager::draw(GMSpriteBatch *s){
        
    }
    void TileSetManager::add(baseArea::TileSet *tileset){
        m_TileSet.push_back(tileset);
    }
    std::vector<TileSet*>& TileSetManager::getTileSets(){
        return m_TileSet;
    }
    BaseAreaMap* TileSetManager::getBaseAreaMap(){
        return m_parent;
    }
    void TileSetManager::drawTile(GMSpriteBatch *s, const GMRect2D &dest, int gid) const{
        int size = (int)m_TileSet.size();
        TileSet* set = 0;
        for(int i = 1; i < size; i++){
            if(m_TileSet[i]->getFirstGit() > gid){
                set = m_TileSet[i-1];
                break;
            }
        }
        if(!set) set = m_TileSet[size-1];
        set->getImage()->draw(s, dest, gid);
    }
    void TileSetManager::drawTile(GMSpriteBatch *s, const GMRect2D &dest, double radian, int gid) const{
        int size = (int)m_TileSet.size();
        TileSet* set = 0;
        for(int i = 1; i < size; i++){
            if(m_TileSet[i]->getFirstGit() > gid){
                set = m_TileSet[i-1];
                break;
            }
        }
        if(!set) set = m_TileSet[size-1];
        set->getImage()->draw(s, dest, radian, gid);
    }
    int TileSetManager::getLocalGid(int gid) const{
        int size = (int)m_TileSet.size();
        TileSet* set = 0;
        for(int i = 1; i < size; i++){
            if(m_TileSet[i]->getFirstGit() > gid){
                set = m_TileSet[i-1];
                break;
            }
        }
        if(!set) set = m_TileSet[size-1];
        return gid - set->getFirstGit();
    }
    
}