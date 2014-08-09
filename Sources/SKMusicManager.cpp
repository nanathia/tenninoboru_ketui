//
//  SKMusicManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKMusicManager.h"

SKMusicManager::SKMusicManager(){
}
SKMusicManager::~SKMusicManager(){
    if(m_Musics.empty()){
        return;
    }
    auto it = m_Musics.begin();
    for(; it != m_Musics.end(); it++){
        delete it->second;
        it->second = 0;
    }
    m_Musics.clear();
}
void SKMusicManager::add(int name, const std::string& fileName){
    GMMusic* Music = new GMMusic(fileName);
    m_Musics.insert(std::map<int, GMMusic*>::value_type(name, Music));
}
GMMusic* SKMusicManager::get(int name){
    return m_Musics[name];
}