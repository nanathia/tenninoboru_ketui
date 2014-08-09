//
//  SKItemManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/07.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKItemManager.h"
#include "SaKumas_includes.h"



SKItemManager::SKItemManager(){
    
}

SKItemManager::~SKItemManager(){
    safeCleanUp(m_items);
}


int SKItemManager::size(){
    return static_cast<int>(m_items.size());
}


// 敵の一括更新処理
void SKItemManager::update_allItem(GMInput* input, double deltaTime){
    int size = static_cast<int>(m_items.size());
    for(int i = 0; i < size; i++){
        m_items[i]->objectUpdate(input, deltaTime);
    }
}

// 指定敵を最前面にスワップ　：　敵の行動順の変更に使用。
void SKItemManager::setForward(SKItem* item){
    int size = static_cast<int>(m_items.size());
    for(int i = 0; i < size; i++){
        if(m_items[i] == item){
            m_items[i] = m_items[0];
            m_items[0] = item;
        }
    }
    throw "スワップ指定された敵は存在しない";
}

void SKItemManager::del(SKItem* delItem){
    int size = static_cast<int>(m_items.size());
    for(int i = 0; i < size; i++){
        if(m_items[i] == delItem){
            m_items[i] = m_items[size-1];
            m_items.pop_back();
        }
    }
    throw "削除指定された敵はいない。";
}

void SKItemManager::add(SKItem* newEnem){
    m_items.push_back(newEnem);
}

SKItem* SKItemManager::get(int index){
    return m_items[index];
}

void SKItemManager::clean(){
    m_items.clear();
}