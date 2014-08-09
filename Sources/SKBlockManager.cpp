//
//  SKBlockManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKBlockManager.h"
#include "SaKumas_includes.h"

SKBlockManager::SKBlockManager(){
    
}

SKBlockManager::~SKBlockManager(){
    safeCleanUp(m_block);
}

// ブロックの一括更新処理
void SKBlockManager::update_allBlock(GMInput* input, double deltaTime){
    int size = (int)this->m_block.size();
    for(int i = 0; i < size; i++){
        m_block[i]->objectUpdate(input, deltaTime);
    }
}

SKBlock* SKBlockManager::get(int arrayIndex) const{
    return m_block[arrayIndex];
}

void SKBlockManager::add(SKBlock* block){
    m_block.push_back(block);
}

void SKBlockManager::clean(){
    m_block.clear();
}