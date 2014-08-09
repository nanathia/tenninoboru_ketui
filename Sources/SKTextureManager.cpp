//
//  SKTextueMan.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKTextureManager.h"


SKTextureManager::SKTextureManager(){
    
}

SKTextureManager::~SKTextureManager(){
    std::map<int, GMTexture2D*>::iterator it;
    if(m_tex.empty()){
        return;
    }
    for(it = m_tex.begin(); it != m_tex.end(); it++){
        delete it->second;
        it->second = 0;
    }
    m_tex.clear();
}

GMTexture2D* SKTextureManager::get(int name){
    return m_tex[name];
}

void SKTextureManager::add(int name, const char* fileName){
    GMTexture2D* tex = new GMTexture2D(fileName);
    m_tex.insert(std::map<int, GMTexture2D*>::value_type(name, tex));
    // std::map<std::string, CEnemy>::iterator itr = eneMap.begin();
}