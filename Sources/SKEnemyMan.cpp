//
//  SKEnemyMan.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKEnemyMan.h"
#include "SaKumas_includes.h"



//namespace{
//    // クイックソートを使用。
//    int gd(SKEnemy* e){
//        int x, y, ex, ey;
//        gPlayScene->getPlayer()->getMass()->getPos(x, y);
//        e->getMass()->getPos(ex, ey);
//        ex -= x;
//        ey -= y;
//        return abs(ex) + abs(ey);
//    }
//    
//    int partition(vector<SKEnemy*>& v, int low, int high)
//    {
//        
//        SKEnemy* pivot = v[high];
//        
//        int left = low - 1;
//        int right = high;
//        
//        while (true) {
//            do {
//                left++;
//            } while (left < right && gd(v[left]) < gd(pivot));
//            
//            do {
//                right--;
//            } while (left < right && gd(v[right]) > gd(pivot));
//            
//            if (left >= right) {
//                pivot = left;
//                break;
//            }
//            
//            swap(v[left], v[right]);
//        }
//        
//        if (pivot != high) {
//            swap(v[pivot], v[high]);
//        }
//        
//        return pivot;
//    }
//    
//    void quick_sort(vector<int>& v, int low, int high)
//    {
//        if (low >= high) {
//            return;
//        }
//        int pivot = partition(v, low, high);
//        
//        quick_sort(v, low, pivot-1);
//        quick_sort(v, pivot+1, high);
//    }
//
//}

SKEnemyMan::SKEnemyMan(){
    
}

SKEnemyMan::~SKEnemyMan(){
    m_enemys.clear();
}

// 敵の一括更新処理
void SKEnemyMan::update_allEnemy(GMInput* input, double deltaTime){
    auto it = m_enemys.begin();
    while(it != m_enemys.end()){
        if(m_enemys.empty()) break;
        if((*it)->objectUpdate(input, deltaTime)){
            (*it)->getMass()->setMovingObject(0);
            SKEnemy* e = *it;
            delete e;
            e = 0;
            it = m_enemys.erase(it);
            continue;
        }
        it++;
    }
}

// 指定敵を最前面にスワップ　：　敵の行動順の変更に使用。
void SKEnemyMan::setForward(SKEnemy* enem){
//    int size = m_enemys.size();
//    for(int i = 0; i < size; i++){
//        if(m_enemys[i] == enem){
//            m_enemys[i] = m_enemys[0];
//            m_enemys[0] = enem;
//        }
//    }
    throw "スワップ指定された敵は存在しない";
}

void SKEnemyMan::del(SKEnemy* delEnem){
    auto it = m_enemys.begin();
    while(it != m_enemys.end()){
        if((*it) == delEnem){
            delete *it;
            *it = 0;
            it = m_enemys.erase(it);
            break;
        }
        it++;
    }
    throw "削除指定された敵はいない。";
}

void SKEnemyMan::add(SKEnemy* newEnem){
    m_enemys.push_back(newEnem);
}

int SKEnemyMan::size(){
    return (int)m_enemys.size();
}

void SKEnemyMan::clean(){
    m_enemys.clear();
}

// プレイヤーを中心にソート
void SKEnemyMan::sort_pivotForPlayer(std::vector<SKEnemy*>& ret){
//    auto it = m_enemys.begin();
//    while(it != m_enemys.end()){
//        ret.push_back(*it);
//    }
//    
//    TODO: 敵のソートの実装
}

bool SKEnemyMan::isAllActionEnded(){
    if(gPlayScene->getPlayer()->isAct()){
        return false;
    }
    auto it = m_enemys.begin();
    while(it != m_enemys.end()){
        if((*it)->isDoing()){
            return false;
        }
        it++;
    }
    return true;
}