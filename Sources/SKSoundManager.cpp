//
//  SKSoundManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSoundManager.h"

SKSoundManager::SKSoundManager(){
}
SKSoundManager::~SKSoundManager(){
    if(m_sounds.empty()){
        return;
    }
    auto it = m_sounds.begin();
    for(; it != m_sounds.end(); it++){
        delete it->second;
        it->second = 0;
    }
    m_sounds.clear();
}
void SKSoundManager::add(int name, const std::string& fileName){
    GMSound* sound = new GMSound(fileName);
    m_sounds.insert(std::map<int, GMSound*>::value_type(name, sound));
}
GMSound* SKSoundManager::get(int name){
    return m_sounds[name];
}