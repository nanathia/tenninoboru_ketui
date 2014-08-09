//
//  PlayerPorch.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/30.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


#ifndef __Karakuri2_Mac__PlayerPorch__
#define __Karakuri2_Mac__PlayerPorch__

#include "Karakuri.h"
#include "EpuipmentItem.h"
#include "SKItemContainar.h"
#include <list>

// このクラスは、プレイヤー（サクマ）のポーチであり、持ち物が最大２０個まで格納されるクラス。
// 取得、破棄、使用、等のメソッドがここに全て格納されてあり、

class SKItem;
class SKMass;

class SKItem;
class SKSword;
class SKShield;
class SKRing;

// このクラスにおける関数の戻り値は、０で成功、−１で失敗。

// アイテム格納場所の一つである。
class PlayerPorch: SKItemContainer{
    std::list<SKItem*> m_items;

public:
    PlayerPorch();
    ~PlayerPorch();
    
    std::list<SKItem*>& getItems();
    
    // 入手系メソッド
    
    // プレイヤーの足元を見て、アイテムがあれば取得
    int getItem_myMass();
    
    // 使用系メソッド
    int useItem(SKItem* item);
    
    // 装備系メソッド
    // 盾を装備。そのアイテムが盾でない場合は実装がおかしいので、プログラムを停止する。
    int setEquipment(EpuipmentItem* equip);
    
    // 放棄系メソッド。
    // 正面に投げる
    int throw_flont(int index);
    // 地面に置く。
    int putting_myMass(int index);
    // 纏めて置く。
    int putting_myMass(std::vector<int>& indexes);
    // 捨てる。
    int throwAway(int index);
    // 纏めて捨てる。
    int throwAway(std::vector<int>& indexes);
    
    // 影響系メソッド
    // 装備を錆びさせる
    int sabi();
    // 持ち物を腐らせる
    int kusari();
    // 持ち物を全て祝福する
    int syukuhuku();
    // 持ち物をランダムで呪う。引数に呪う数。
    int noroi(int num);
    // 剣を弾く。
    int flickSword();
    // 盾を弾く。
    int flickShield();
    // 腕輪を弾く
    int flickShiled();
    // 何かを弾く
    int flickAny();
};

#endif /* defined(__Karakuri2_Mac__PlayerPorch__) */
