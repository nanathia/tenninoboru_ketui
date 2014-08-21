//
//  SKMassManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/28.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMassManager__
#define __Karakuri2_Mac__SKMassManager__

#include "Karakuri.h"
#include "SKMass.h"
#include "randam_dungeon.h"
#include <vector>

class randam_dungeon;

class SKMassManager{
    // 現在階層
    int m_kaisou;
    // マス配列
    SKMass** m_masses;
    // マス配列の、幅と高さ
    int m_stageWidth;
    int m_stageHeight;
    // プレイヤーを中心とした描画領域にゃんよ！にゃんにゃん！
    int m_drawAreaWidth;
    int m_drawAreaHeight;
    // ランダムダンジョン生成クラス。
    randam_dungeon* m_random_dungeonRenderer;
    
    void _nextFloor();
    bool m_nextFlag;
    
public:
    SKMassManager(int stageWidth, int stageHeight, int drawAreaWidth, int drawAreaHeight);
    ~SKMassManager();
    
    void update();
    int getKaisou();
    
    void nextFloor();
    
public:
    void allDraw_currentGameGraph();
    
public:
    // 部屋std::vectorを取得。
    std::vector<_room*>& getRooms();
    // 取得するマスのステージ位置を指定
    SKMass* get(int x, int y);
    // 移動させる。
    void move(SKObject* moveObj, int ofs_x, int ofs_y);
    void getStageSize(int& x, int& y) const;
    void load(GMVector2D size /*, ロードするファイル*/ );
    // 描画インデクスに変換
    void convertDrawIndex(const SKMass* mass, int& x, int& y) const;
    
    // デバッグ用。ダンジョンデータを書き出す。
    void fileDraw_dungeonData();
    // 全てのマスの探索フラグを下ろす
    void ClearSearhFlag();
};

#endif /* defined(__Karakuri2_Mac__SKMassManager__) */
