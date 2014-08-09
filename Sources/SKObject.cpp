//
//  SKObject.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKObject.h"
#include "SaKumas_includes.h"
#include "randam_dungeon.h"
#include "SKMassManager.h"
#include <string>
#include <vector>
#include <cmath>


SKObject::SKObject():
m_myLocations_mass(0),
m_previousMass(0),
m_myRadian(-0.5),
m_roomInterMass(0),
m_roomExitMass(0),
m_objectName("")
{
}

SKObject::~SKObject()
{
    m_myLocations_mass = 0;
    m_previousMass = 0;
    m_myRadian = 0;
    m_roomExitMass = 0;
    m_roomInterMass = 0;
    m_objectName = "";
}

void SKObject::setMass(SKMass* mass){
    m_myLocations_mass = mass;
}

SKMass* SKObject::getMass(){
    return m_myLocations_mass;
}

bool SKObject::objectUpdate(GMInput* input, double deltaTime){
    
    return true;
}

bool SKObject::positionUpdate(int x_offset, int y_offset){
    if(abs(x_offset)>1 || abs(y_offset) > 1){
        throw "移動例外なう";
    }
    int x = 0;
    int y = 0;
    m_myLocations_mass->getPos(x, y);
    int s_x, s_y;
    gPlayScene->getMassMan()->getStageSize(s_x, s_y);
    //
    if(x_offset < 0){
        if(x == 0){
            x_offset = 0;
        }
    }else if(x_offset > 0){
        if(x == s_x){
            x_offset = 0;
        }
    }
    if(y_offset < 0){
        if(y == 0){
            y_offset = 0;
        }
    }else if(y_offset > 0){
        if(y == s_y){
            y_offset = 0;
        }
    }
    
    this->setPreviousMass(gPlayScene->getMassMan()->get(x, y));
    
    int new_x = x + x_offset;
    int new_y = y + y_offset;
    SKMass* nextMass = gPlayScene->getMassMan()->get(new_x, new_y);
    if(nextMass->getBlock() || nextMass->getMovingObject()){
        return false;
    }
    gPlayScene->getMassMan()->get(x, y)->setMovingObject(0);
    gPlayScene->getMassMan()->get(new_x, new_y)->setMovingObject(this);
    return true;
}

bool SKObject::positionUpdate(){
    // TODO: SKObject::positionUpdate()のリターン値の検証
    return true;
}

// Radianで向きを返す。
double SKObject::getRadian() const{
    return m_myRadian;
}

// 向きを変更する。
void SKObject::setSKObjectAngle(SKObject* obj){
    int tx, ty, px, py;
    obj->getMass()->getPos(tx, ty);
    this->getMass()->getPos(px, py);
    int dx = tx - px;
    int dy = ty - py;
    m_myRadian = atan2(static_cast<double>(dy), static_cast<double>(dx))/M_PI;
}

// SKMass版
void SKObject::setSKObjectAngle(SKMass* mass){
    int tx, ty, px, py;
    mass->getPos(tx, ty);
    this->getMass()->getPos(px, py);
    int dx = tx - px;
    int dy = ty - py;
    m_myRadian = atan2(static_cast<double>(dy), static_cast<double>(dx))/M_PI;
}

void SKObject::setSKObjectAngle(double radian){
    m_myRadian = radian;
}

// デバッグ用。現在位置に、矢印を描画する。
void SKObject::drawDirectionEffect(int d_x, int d_y, GMSpriteBatch* s, double radian){
    //    s->draw(<#GMTexture2D *tex#>, <#const GMVector2D &pos#>, <#const GMRect2D &srcRect#>, <#const GMColor &color#>, <#double rotation#>, <#const GMVector2D &origin#>, <#const GMVector2D &scale#>, <#GMSpriteFlip flip#>)
    s->draw(gPlayScene->getTexMan()->get(Texture_directionName), GMVector2D(d_x+mass_size/2, d_y+mass_size/2), GMRect2D(0,0,64,64), GMColor::White, radian*M_PI, GMVector2D(0,32), GMVector2D(0.5, 0.5), GMSpriteFlip(GMSpriteFlipHorizontally), 0.9 );
}


// 部屋内かどうか
_room* SKObject::isInRoom() const{
    return this->m_myLocations_mass->getRoom();
}


// ラジアンをセット
void SKObject::setRadian(double radian){
    if(radian > 1.0){
        radian -= 2.0;
    }else if(radian < -1.0){
        radian += 2.0;
    }
    m_myRadian = radian;
}


void SKObject::setPreviousMass(SKMass* previous){
    m_previousMass = previous;
}


// 描画位置を取得
GMVector2D SKObject::getDrawPoint(int sx, int sy) const{
    GMVector2D d;
    if(m_previousMass){
        int px, py, tx, ty;
        m_previousMass->getPos(tx, ty);
        this->m_myLocations_mass->getPos(px, py);
        GMVector2D t(tx, ty);
        GMVector2D p(px, py);
        t -= p;
        
        d *= mass_size;
        d.x += sx;
        d.y += sy;
    }else{
        d = GMVector2D(sx, sy);
    }
    
    return d;
//    return 0;
}

GMVector2D SKObject::getLarpPoint(SKMass* start, SKMass* end, int dx, int dy, double time){
    int px, py, tx, ty;
    start->getPos(tx, ty);
    end->getPos(px, py);
    GMVector2D t(tx, ty);
    GMVector2D p(px, py);
    t -= p;
    GMVector2D d = GMVector2D::Lerp(t, GMVector2D::Zero, time);
    d *= mass_size;
    d.x += dx;
    d.y += dy;
    return d;
}

// 隣接している。
bool SKObject::isAdjoining(SKMass* mass) const{
    int px, py, tx, ty;
    mass->getPos(tx, ty);
    m_myLocations_mass->getPos(px, py);
    tx -= px;
    ty -= py;
    if(abs(tx) <= 1 && abs(ty) <= 1) return true;
    return false;
}

//移動
void SKObject::move(int x_offset, int y_offset){
    if(abs(x_offset)>1 || abs(y_offset) > 1){
        throw "移動例外なう";
    }
    int x = 0;
    int y = 0;
    m_myLocations_mass->getPos(x, y);
    int s_x, s_y;
    gPlayScene->getMassMan()->getStageSize(s_x, s_y);
    //
    if(x_offset < 0){
        if(x == 0){
            x_offset = 0;
        }
    }else if(x_offset > 0){
        if(x == s_x){
            x_offset = 0;
        }
    }
    if(y_offset < 0){
        if(y == 0){
            y_offset = 0;
        }
    }else if(y_offset > 0){
        if(y == s_y){
            y_offset = 0;
        }
    }
    
    this->setPreviousMass(gPlayScene->getMassMan()->get(x, y));
    
    int new_x = x + x_offset;
    int new_y = y + y_offset;
    SKMass* nextMass = gPlayScene->getMassMan()->get(new_x, new_y);
    if(nextMass->getBlock() || nextMass->getMovingObject()) return;
    
    gPlayScene->getMassMan()->get(x, y)->setMovingObject(0);
    gPlayScene->getMassMan()->get(new_x, new_y)->setMovingObject(this);
    this->setRadian(atan2(y_offset, x_offset)/M_PI);
    return;
}

void SKObject::move(SKMass* target){
    int dx, dy;
    this->getDistances(target, dx, dy);
    this->convertDistance_one(dx, dy);
    this->move(dx, dy);
}

void SKObject::move(SKObject* target){
    this->move(target->getMass());
}

void SKObject::move(){
    int x, y;
    this->convertRadianToOffset(this->m_myRadian, x, y);
    this->move(x, y);
}

// 〜マス以内を検索。
vector<SKObject*> SKObject::serchObject(int distance){
    vector<SKObject*> objects;
    int size = distance*2+1;
    int px, py;
    this->getMass()->getPos(px, py);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            SKMass* mass = gPlayScene->getMassMan()->get(i-distance, j-distance);
            if(mass){
                if(mass->getMovingObject()){
                    objects.push_back(mass->getMovingObject());
                }
                if(mass->getItem()){
                    objects.push_back(mass->getItem());
                }
                if(mass->getBlock()){
                    objects.push_back(mass->getBlock());
                }
            }
        }
    }
    return objects;
}

bool SKObject::serchObject(SKObject* obj, int distance){
    int size = distance*2+1;
    int px, py;
    this->getMass()->getPos(px, py);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            SKMass* mass = gPlayScene->getMassMan()->get(i-distance, j-distance);
            if(mass){
                if(mass->getMovingObject() == obj){
                    return true;
                }
                if(mass->getItem() == obj){
                    return true;
                }
                if(mass->getBlock() == obj){
                    return true;
                }
            }
        }
    }
    return false;
}

// 同じ部屋かどうか
bool SKObject::isSameRoom(SKObject* obj){
    return this->isSameRoom(obj->getMass());
}

bool SKObject::isSameRoom(SKMass* obj){
    return obj->getRoom() == this->getMass()->getRoom();
}

// 相手までの距離
int SKObject::getDistance(SKObject* obj){
    return this->getDistance(obj->getMass());
}

int SKObject::getDistance(SKMass* obj){
    int px, py, tx, ty;
    this->getMass()->getPos(px, py);
    obj->getPos(tx, ty);
    tx -= px;
    ty -= py;
    return abs(tx)+abs(ty);
}

// 最も近いオブジェクト。
SKObject* SKObject::getNearestSkobject(){
    // 未実装
    // TODO: SKObject::getNearestSkobject()のリターン値の検証
    return NULL;
}

SKEnemy* SKObject::getNearestEnemy(){
    // TODO: SKObject::getNearestEnemy()のリターン値の検証
    return NULL;
}

SKItem* SKObject::getNearestItem(){
    // TODO: SKObject::getNearestItem()のリターン値の検証
    return NULL;
}

SKObject* SKObject::getVectorObject(){
    int ofsx, ofsy;
    this->convertRadianToOffset(this->m_myRadian, ofsx, ofsy);
    int px, py;
    this->getMass()->getPos(px, py);
    while(true){
        px += ofsx;
        py += ofsy;
        SKMass* mass = gPlayScene->getMassMan()->get(px, py);
        if(mass){
            if(mass->getMovingObject()){
                return mass->getMovingObject();
            }else if(mass->getItem()){
                return mass->getItem();
            }else if(mass->getBlock()){
                return mass->getBlock();
            }
        }else{
            break;
        }
    }
    
    // 直線上には床以外に何もなかった。
    return 0;
}

vector<SKObject*> SKObject::getVectorObjects(){
    vector<SKObject*> objects;
    int ofsx, ofsy;
    this->convertRadianToOffset(this->m_myRadian, ofsx, ofsy);
    int px, py;
    this->getMass()->getPos(px, py);
    while(true){
        px += ofsx;
        py += ofsy;
        SKMass* mass = gPlayScene->getMassMan()->get(px, py);
        if(mass){
            if(mass->getMovingObject()){
                objects.push_back(mass->getMovingObject());
            }else if(mass->getItem()){
                objects.push_back(mass->getItem());
            }else if(mass->getBlock()){
                objects.push_back(mass->getBlock());
            }
        }else{
            break;
        }
    }
    
    // 直線上には床以外に何もなかった。
    return objects;
}

// コンバート。
void SKObject::convertRadianToOffset(double radian, int& ofs_x, int& ofs_y) const{
    ofs_x = ofs_y = 0;
    
    while(true){
        if(radian < -1){
            radian += 2.0;
        }else if(radian > 1){
            radian -= 2.0;
        }else{
            break;
        }
    }
    
    if(radian == 0){
        // 右
        ofs_x = 1;
    }else if(radian == 0.25){
        // 右上
        ofs_x = 1;
        ofs_y = 1;
    }else if(radian == 0.5){
        // 上
        ofs_y = 1;
    }else if(radian == 0.75){
        // 左上
        ofs_x = -1;
        ofs_y = 1;
    }else if(radian == 1.0 || radian == -1.0){
        // 左
        ofs_x = -1;
    }else if(radian == -0.75){
        // 左下
        ofs_x = -1;
        ofs_y = -1;
    }else if(radian == -0.5){
        // 下
        ofs_y = -1;
    }else if(radian == -0.25){
        // 右下
        ofs_x = 1;
        ofs_y = -1;
    }else{
        throw "どの方向にも一致しない";
    }
}

// 出口のランダム取得
SKMass* SKObject::getRandomRoomExitMass(){
    vector<SKMass*> entrances = *this->getMass()->getRoom()->getEntranceMasses();
    int size = (int)entrances.size();
    if(size == 1){
        return entrances[0];
    }else if(!size){
        return 0;
    }
    
    for(int i = 0; i < size; i++){
        if(entrances[i]->getMovingObject() == this){
            entrances[i] = entrances[size-1];
            entrances.pop_back();
            break;
        }
    }
    size = (int)entrances.size();
    int rnd = (int)randam_dungeon::rand(0, (int)entrances.size()-1);
    return entrances[rnd];
}

void SKObject::getDistances(SKObject* obj, int& x, int& y){
    this->getDistances(obj->getMass(), x, y);
}

void SKObject::getDistances(SKMass* mass, int& dx, int& dy){
    int tx, ty, px, py;
    mass->getPos(tx, ty);
    this->getMass()->getPos(px, py);
    dx = tx - px;
    dy = ty - py;
}

// 距離を１まで縮める
void SKObject::convertDistance_one(int& x, int& y) const{
    if(x < 0){
        x = -1;
    }else if(x > 0){
        x = 1;
    }
    if(y < 0){
        y = -1;
    }else if(y > 0){
        y = 1;
    }
}

void SKObject::setInter(SKMass* mass){
    this->m_roomInterMass = mass;
}

void SKObject::setExit(SKMass* mass){
    this->m_roomExitMass = mass;
}

SKMass* SKObject::getInter(){
    return this->m_roomInterMass;
}

SKMass* SKObject::getExit(){
    return this->m_roomExitMass;
}

// その方向に進行できるかどうか。
bool SKObject::isCanMoving(int x, int y){
    if(abs(x) > 1 || abs(y) > 1) GMException("それはない");
    SKMass* targetMass = this->getMassForOffset(x, y);
    
    if(abs(x) == 1 && abs(y) == 1){
        // 斜め移動の場合
        // 移動先に何か障害物がある場合
        if(targetMass->getBlock() || targetMass->getMovingObject()){
            return false;
        }
        // 進行方向を挟む２つのマスのどちらかが壁の場合は進行不能
        SKMass* mass1 = this->getMassForOffset(x, 0);
        SKMass* mass2 = this->getMassForOffset(0, y);
        if(mass1->getBlock() || mass2->getBlock()){
            return false;
        }
        // それ以外は移動できる。
        return true;
    }
    
    // 通常の、縦横移動の場合。
    // 移動先に何か障害物がある場合
    if(targetMass->getBlock() || targetMass->getMovingObject()){
        return false;
    }
    // それ以外はおｋ
    return true;
}

bool SKObject::isCanMoving(double radian){
    int ox, oy;
    this->convertRadianToOffset(radian, ox, oy);
    return this->isCanMoving(ox, oy);
}

// ラジアンからマスを取得
SKMass* SKObject::getMassForRadian(double radian, int distance){
    int px, py;
    this->getMass()->getPos(px, py);
    int ox, oy;
    this->convertRadianToOffset(radian, ox, oy);
    px += ox;
    py += oy;
    px *= distance;
    py *= distance;
    return gPlayScene->getMassMan()->get(px, py);
}

// 差分からマスを取得
SKMass* SKObject::getMassForOffset(int ofs_x, int ofs_y){
    int px, py;
    this->getMass()->getPos(px, py);
    px += ofs_x;
    py += ofs_y;
    return gPlayScene->getMassMan()->get(px, py);
}

// 現在位置と向きから、通常で最も移動すべきマスを取得
SKMass* SKObject::getBestTargetMass(){
    for(int i = 0; i < 8; i++){
        double radian = this->getRadian();
        if(i == 0){
            radian += 0.25;
        }else if(i == 1){
            radian += -0.25;
        }else if(i == 2){
            radian += 0.5;
        }else if(i == 3){
            radian += -0.5;
        }else if(i == 4){
            radian += 0.75;
        }else if(i == 5){
            radian += -0.75;
        }else if(i == 6){
        }else if(i == 7){
            radian += 1;
        }
        if(this->isCanMoving(radian)){
            return this->getMassForRadian(radian);
        }
    }
    
    // 壁に囲まれて移動できない状態。
    return 0;
}

// 名前をセットする
void SKObject::setName(std::string name){
    m_objectName = name;
}

// 名前を取得する
const string& SKObject::getName(){
    return m_objectName;
}

SKObject* SKObject::getForwordObject(){
    int x, y;
    convertRadianToOffset(this->getRadian(), x, y);
    int px, py;
    this->getMass()->getPos(px, py);
    px += x;
    py += y;
    return gPlayScene->getMassMan()->get(px, py)->getMovingObject();
}

double SKObject::getRadian(SKObject* t){
    return -1;
}

void SKObject::localize(int &x, int &y){
    if(x > 0){
        x = 1;
    }else if(x < 0){
        x = -1;
    }
    if(y > 0){
        y = 1;
    }else if(y < 0){
        y = -1;
    }
}
