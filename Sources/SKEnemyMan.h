//
//  SKEnemyMan.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKEnemyMan__
#define __Karakuri2_Mac__SKEnemyMan__

#include "Karakuri.h"
#include <list>

class SKEnemy;

class SKEnemyMan{
public:
    std::list< SKEnemy* > m_enemys;
    
public:
    SKEnemyMan();
    ~SKEnemyMan();
    // 敵の一括更新処理
    void update_allEnemy(GMInput* input, double deltaTime);
    // 指定敵を最前面にスワップ　：　敵の行動順の変更に使用。
    void setForward(SKEnemy* enem);
    // 指定敵を削除
    void del(SKEnemy* delEnem);
    // 指定敵を追加
    void add(SKEnemy* newEnem);
    // プレイヤーを中心にソート
    void sort_pivotForPlayer(std::vector<SKEnemy*>& ret);
    // 全て行動終了
    bool isAllActionEnded();
    // 指定インデクスの敵を取得。
//    SKEnemy* get(int index);
    // 敵の数を取得
    int size();
    
    void clean();
};

#endif /* defined(__Karakuri2_Mac__SKEnemyMan__) */
