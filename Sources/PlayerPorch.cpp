//
//  PlayerPorch.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/30.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "PlayerPorch.h"
#include "SKUserInterface.h"
#include "SaKumas_includes.h"
#include "SKDungeonScene.h"
#include <sstream>

// 入手系メソッド
// プレイヤーの足元を見て、アイテムがあれば取得
int PlayerPorch::getItem_myMass(){
    SKItem* item = m_scene->getPlayer()->getMass()->getItem();
    if(!item) return 0;
    if(item->getName() == "階段"){
        m_scene->getMassMan()->nextFloor();
        return 1;
        return 0;
    }
    if(this->getItems().size() >= 20){
        m_scene->getUI()->textInput("これ以上は持てない。");
        return 0;
    }
    std::string str;
    str = "サクマは、";
    str += item->getName();
    str += "を拾った。";
    m_scene->getUI()->textInput(str);
    
    item->getMass()->setItem(0);
    this->m_items.push_back(item);
    
    return 0;
}

PlayerPorch::PlayerPorch(SKDungeonScene* scene):
m_scene(scene){
    
}

PlayerPorch::~PlayerPorch(){
    auto it = m_items.begin();
    while(it != m_items.end()){
        delete *it;
        *it = 0;
        it++;
    }
    m_items.clear();
}

// 使用系メソッド
int PlayerPorch::useItem(SKItem* item){
    if(item->isDel()){
        if(item->getMass()){
            item->getMass()->setItem(0);
        }
        m_items.remove(item);
        delete item;
        item = 0;
    }
    return 0;
}

// 装備系メソッド
// 盾を装備。そのアイテムが盾でない場合は実装がおかしいので、プログラムを停止する。
int PlayerPorch::setEquipment(EpuipmentItem *equip){
    // アイテム装備の実装
    return 0;
}

// 放棄系メソッド。
// 正面に投げる
int PlayerPorch::throw_flont(int index){
    // TODO:
    return 0;

}

// 地面に置く。
int PlayerPorch::putting_myMass(int index){
    // TODO:
  return 0;

}

// 纏めて置く。
int PlayerPorch::putting_myMass(std::vector<int>& indexes){
    // TODO:
   return 0;

}

// 捨てる。
int PlayerPorch::throwAway(int index){
    // TODO:
   return 0;

}

// 纏めて捨てる。
int PlayerPorch::throwAway(std::vector<int>& indexes){
    // TODO:
    return 0;

}

// 影響系メソッド
// 装備を錆びさせる
int PlayerPorch::sabi(){
    // TODO:
    return 0;

}

// 持ち物を腐らせる
int PlayerPorch::kusari(){
    // TODO:
    return 0;

}

// 持ち物を全て祝福する
int PlayerPorch::syukuhuku(){
    // TODO:
   return 0;

}

// 持ち物をランダムで呪う。引数に呪う数。
int PlayerPorch::noroi(int num){
    // TODO:
   return 0;

}

// 剣を弾く。
int PlayerPorch::flickSword(){
    // TODO:
   return 0;

}

// 盾を弾く。
int PlayerPorch::flickShield(){
    // TODO:
   return 0;

}

// 腕輪を弾く
int PlayerPorch::flickShiled(){
    // TODO:
   return 0;

}

// 何かを弾く
int PlayerPorch::flickAny(){
    // TODO:
  return 0;

}

std::list<SKItem*>& PlayerPorch::getItems(){
    return m_items;
}

