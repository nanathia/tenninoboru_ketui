//
//  SKMass.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMass__
#define __Karakuri2_Mac__SKMass__

#include "Karakuri.h"
#include "SKItemContainar.h"
#include "randam_dungeon.h"

class SKObject;
class SKItem;
class SKBlock;
class SKDungeonScene;

// 更新作業について
// まずメインループから、プレイヤー、敵の順に更新。
// あれ、ブロックとアイテム更新する必要ねえ・・・
// プレイヤーと敵だけで！

// アイテム格納場所の一つである
class SKMass: SKItemContainer{
    SKDungeonScene* m_scene;
public:
    SKMass(SKDungeonScene* scene, int x, int y);
    ~SKMass();
    
public:
    // 探索済み
    bool isSearhed();
    // 探索
    void seached();
    // クリア
    void seachClear();
    
    // マス上のインデックスを取得
    void getPos(int& x, int& y) const;
    SKMass* getMassForOffset(int x, int y);
    
    // マス上のSKObjectをセット
    SKObject* getMovingObject();
    SKItem* getItem();
    SKBlock* getBlock();
    
    // マス上のSKObjectをセット
    void setItem(SKItem* item);
    void setBlock(SKBlock* block);
    void setMovingObject(SKObject* movingObj);
    
    // 現在いる部屋を取得、セット
    _room* getRoom();
    // 部屋の出入口かどうか
    bool isInterOuterMass();
    
    void setRoom(_room* room);
    // 今いる部屋を検索して格納
    void seachRoom();
    
public:
    void clean();
    
    // デバッグ用描画。薄く四角を描画する。
    static void draw_debugRect(int drawStartIndex_x, int drawStartIndex_y, GMSpriteBatch* s);
    // デバッグ用描画。薄く四角を描画する。色指定ver。
    static void draw_debugRect(int drawStartIndex_x, int drawStartIndex_y, GMSpriteBatch* s, GMColor color);
    // ステージ範囲外描画用。絶対に壊れないブロックを描画する。
    static void draw_outOfStageBlock(int drawStartIndex_x, int drawStartIndex_y);
    // このマス内の物体全てにおける更新
    void updateAllObject_atTheThisMass(GMInput* input, double deltaTime);
    // このマス内の床、その上に乗っている物体全てにおける描画。int の引数は、どの場所から描画するか。
    void drawAllObject_atTheThisMass(int drawStartIndex_x, int drawStartIndex_y) const;
    // 差分取得
    void getOffset(SKMass* tar, int& x, int& y);
    
    void getDrawPoint(int& dx, int& dy) const;
    
private:
    // ステージのどのマスか
    int m_xIndex;
    int m_yIndex;
    
    // どの部屋にいるか。
    _room* m_room;
    
    // 探索用のフラグ
    bool m_sarchFlag;
    
    // 各、置かれる可能性のあるステージ上物体。同時に３つまで存在できるということ。
    SKObject* m_movingObject;
    SKBlock* m_block;
    SKItem* m_item;
    
};

#endif /* defined(__Karakuri2_Mac__SKMass__) */
