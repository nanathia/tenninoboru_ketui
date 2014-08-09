//
//  SKItemManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/07.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKItemManager__
#define __Karakuri2_Mac__SKItemManager__

#include <vector>
#include "SKItem.h"
#include "Karakuri.h"
#include "SKItemContainar.h"

// アイテム格納場所の一つである。
class SKItemManager: SKItemContainer{
    std::vector<SKItem*> m_items;
    
public:
    SKItemManager();
    ~SKItemManager();
    // アイテムの一括更新処理
    void update_allItem(GMInput* input, double deltaTime);
    // 指定アイテムを最前面にスワップ　：　アイテムの行動順の変更に使用。
    void setForward(SKItem* item);
    // 指定アイテムを削除
    void del(SKItem* delEnem);
    // 指定アイテムを追加
    void add(SKItem* newEnem);
    // 指定インデクスのアイテムを取得。
    SKItem* get(int index);
    // アイテムの数を取得
    int size();
    void clean();
    
};

#endif /* defined(__Karakuri2_Mac__SKItemManager__) */
