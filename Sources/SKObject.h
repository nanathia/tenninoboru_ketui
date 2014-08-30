//
//  SKObject.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKObject__
#define __Karakuri2_Mac__SKObject__

#include "Karakuri.h"
#include "SKTextureManager.h"
#include "SKMass.h"
#include <list>

// ”サクマの不思議のダンジョン”における全てのオブジェクトの基底クラス
// 何か行動するときは、勝手に動いては行かず、必ず order 関数を呼び出して団体行動を乱さない。

class _room;
class SKEnemy;
class SKItem;
class SKOrder;
class SKDungeonScene;

class SKObject{
    
protected:
    
    // ここから、サブクラスで直接操作が可能な変数。
    SKMass* m_myLocations_mass;
    SKMass* m_previousMass;
    double m_myRadian;
    
    SKMass* m_roomInterMass;
    SKMass* m_roomExitMass;
    
    // オブジェクト固有の名前。壁ならもう壁。
    std::string m_objectName;
    
    SKDungeonScene* m_scene;
        
public:
    // どんなゲームでも共通する、基本的なメソッドの宣言。描画、更新、初期化。
    virtual void objectDraw(int startDrawPoint_x, int startDrawPoint_y) = 0;
    virtual bool objectUpdate(GMInput* input, double deltaTime) = 0;
    virtual void objectInit(GMGraphics* g) = 0;
    
public:
    
    // 他の場所から呼び出すべき、SKObjectを操作するのメソッドの宣言。
    int size();

    void setInter(SKMass*);
    void setExit(SKMass*);
    SKMass* getInter();
    SKMass* getExit();
    void setMass(SKMass* mass);
    SKMass* getMass();
    void setPreviousMass(SKMass* target);
    // 描画位置を取得
    GMVector2D getDrawPoint(int massPointOfScreen_x, int massPointOfScreen_y) const;
    static GMVector2D getLarpPoint(SKMass* startMass, SKMass* endMass, int dx, int dy, double time);
    
public:
    
    // ローカライズ
    static void localize(int& x, int& y);
    // デバッグ用。現在位置に、矢印を描画する。
    static void drawDirectionEffect(int s_draw_x, int s_draw_y, GMSpriteBatch* s, double radian);
    // ラジアンで向きを返す。
    double getRadian() const;
    double getRadian(SKObject*);
    // ラジアンをセット
    void setRadian(double radian);
    // コンバート。
    void convertRadianToOffset(double radian, int& x, int& y) const;
    // 部屋内かどうか
    _room* isInRoom() const;
    // 移動する
    bool positionUpdate(int x_offset, int y_offset);
    bool positionUpdate();
    // 向きを変更する。
    // 引数のSKObjectへ向く。
    void setSKObjectAngle(SKObject* obj);
    // SKMass版
    void setSKObjectAngle(SKMass* mass);
    // 直でセットする。
    void setSKObjectAngle(double radian);
    // 隣接している。
    bool isAdjoining(SKMass* mass) const;
    //移動
    void move(int x_ofs, int y_ofs);
    void move(SKMass* target);
    void move(SKObject* target);
    void move();
    // 〜マス以内を検索。
    vector<SKObject*> serchObject(int distance);
    bool serchObject(SKObject*, int distance);
    // 同じ部屋かどうか
    bool isSameRoom(SKObject*);
    bool isSameRoom(SKMass*);
    // 相手までの距離
    int getDistance(SKObject*);
    int getDistance(SKMass*);
    void getDistances(SKObject*, int& x, int& y);
    void getDistances(SKMass*, int& x, int& y);
    // 距離を１まで縮める
    void convertDistance_one(int& x, int& y) const;
    // 最も近いオブジェクト。
    SKObject* getNearestSkobject();
    SKEnemy* getNearestEnemy();
    SKItem* getNearestItem();
    // 直線上のオブジェクトを取得
    SKObject* getVectorObject();
    vector<SKObject*> getVectorObjects();
    // 出口のランダム取得
    SKMass* getRandomRoomExitMass();
    // その方向に進行できるかどうか
    bool isCanMoving(int x, int y);
    bool isCanMoving(double radian);
    // ラジアンからマスを取得
    SKMass* getMassForRadian(double radian, int distance = 1);
    // 差分からマスを取得
    SKMass* getMassForOffset(int ofx_x, int ofs_y);
    // 現在位置と向きから、通常で最も移動すべきマスを取得
    SKMass* getBestTargetMass();
    SKObject* getForwordObject();
    // 名前をセットする
    void setName(std::string name);
    // 名前を取得する
    const string& getName();
    // ベースエリアの取得
    SKDungeonScene* getScene();

protected:
    
public:
    SKObject(SKDungeonScene* parent);
    virtual ~SKObject();
    
};

#endif /* defined(__Karakuri2_Mac__SKObject__) */
