//
//  SKBlockManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKBlockManager__
#define __Karakuri2_Mac__SKBlockManager__

#include "Karakuri.h"
#include "SKBlock.h"
#include <vector>

class SKBlockManager{
    std::vector<SKBlock*> m_block;
    
public:
    SKBlockManager();
    ~SKBlockManager();
    // ブロックの一括更新処理
    void update_allBlock(GMInput* input, double deltaTime);
    // 指定アイテムを最前面にスワップ　：　アイテムの行動順の変更に使用。
    void setForward(SKBlock* block);
    // 指定アイテムを削除
    void del(SKBlock* delBlock);
    // 指定アイテムを追加
    void add(SKBlock* newBlock);
    // 指定インデクスのアイテムを取得。
    SKBlock* get(int index) const;
    void clean();
};


#endif /* defined(__Karakuri2_Mac__SKBlockManager__) */
