//
//  SKMass.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SaKumas_includes.h"
#include <vector>
#include <sstream>

SKMass::SKMass(SKDungeonScene* scene, int x, int y):
m_scene(scene),
m_xIndex(x),
m_yIndex(y),
m_movingObject(0),
m_block(0),
m_item(0),
m_room(0)
{
    
}

SKMass::~SKMass(){
    
}

void SKMass::clean(){
    if(m_item){
        delete m_item;
        m_item = 0;
    }
    if(m_block){
        delete m_block;
        m_block = 0;
    }
    if(m_movingObject && m_scene->getPlayer()!=m_movingObject){
        delete m_movingObject;
        m_movingObject = 0;
    }else if(m_movingObject){
        m_movingObject = 0;
    }
}


void SKMass::getPos(int& x, int& y) const{
    x = m_xIndex;
    y = m_yIndex;
}

SKObject* SKMass::getMovingObject(){
    return m_movingObject;
}

SKItem* SKMass::getItem(){
    return m_item;
}

SKBlock* SKMass::getBlock(){
    return m_block;
}

void SKMass::setItem(SKItem* item){
    m_item = item;
    if(item){
        item->setMass(this);
    }
}

void SKMass::setBlock(SKBlock* block){
    m_block = block;
    if(block){
        block->setMass(this);
    }
}

void SKMass::setMovingObject(SKObject* movingObj){
    m_movingObject = movingObj;
    if(movingObj){
        movingObj->setMass(this);
    }
}

void SKMass::updateAllObject_atTheThisMass(GMInput* input, double deltaTime){
    
    SKObject* massObjes[] = {m_movingObject, m_item, m_block};
    for(int i = 0; i < 3; i++){
        if(massObjes[i] == 0){
            continue;
        }
        massObjes[i]->objectUpdate(input, deltaTime);
    }
}

void SKMass::draw_debugRect(int index_x, int index_y, GMSpriteBatch* s, GMColor color){
    
    // ピクセル単位描画位置を計算
    int drawPos_x = index_x*mass_size-massDrawOffset_x;
    int drawPos_y = index_y*mass_size-massDrawOffset_y;
    color.a = 0.25;
    s->draw(0, GMRect2D(drawPos_x, drawPos_y, mass_size, mass_size), GMRect2D(0, 0, 64, 64), color, 0.1);
    
}

void SKMass::draw_debugRect(int index_x, int index_y, GMSpriteBatch* s){
    
    // ピクセル単位描画位置を計算
    int drawPos_x = index_x*mass_size-massDrawOffset_x;
    int drawPos_y = index_y*mass_size-massDrawOffset_y;
    // 床を描画
    //    s->draw(tex->get(Texture_floorName), GMRect2D(drawPos_x, drawPos_y, mass_size, mass_size), GMRect2D(0, 0, 64, 64), GMColor::SeaGreen, 0.0);
    // 絶対に壊れない壁を描画
    GMColor c = GMColor::Orange;
    c.a = 0.25;
    s->draw(0, GMRect2D(drawPos_x, drawPos_y, mass_size, mass_size), GMRect2D(0, 0, 64, 64), c, 0.1);
    
}

void SKMass::draw_outOfStageBlock(int index_x, int  index_y/*, GMSpriteBatch* s*/){
//    SKTextureManager* tex = m_scene->getTexMan();
//    // ピクセル単位描画位置を計算
//    int drawPos_x = index_x*mass_size-massDrawOffset_x;
//    int drawPos_y = index_y*mass_size-massDrawOffset_y;
    // 床を描画
    
    // TODO:床の描画の実装
    //s->draw(tex->get(Texture_floorName), GMRect2D(drawPos_x, drawPos_y, mass_size, mass_size), GMRect2D(0, 0, 64, 64), GMColor::SeaGreen, 0.0);
    
    // 絶対に壊れない壁を描画
    // TODO:壁の描画の実装
    //s->draw(tex->get(Texture_blockName), GMRect2D(drawPos_x, drawPos_y, mass_size, mass_size), GMRect2D(0, 0, 64, 64), GMColor::White, 0.1);
}


void SKMass::drawAllObject_atTheThisMass(int index_x, int index_y) const{
    SKTextureManager* tex = m_scene->getTexMan();
    
    // ピクセル単位描画位置を計算
    int drawPos_x = index_x*mass_size-massDrawOffset_x;
    int drawPos_y = index_y*mass_size-massDrawOffset_y;
    
    // 床を描画
    GMDraw::Begin();
    gPlayScene->getCurrentEffect()->enableTexture(true);
    gPlayScene->getCurrentEffect()->setTexture(tex->get(Texture_floorName));
    GMDraw::FillQuad(GMVector3D(drawPos_x, drawPos_y, 0), GMVector3D(drawPos_x+mass_size+1, drawPos_y, 0),
                     GMVector3D(drawPos_x+mass_size+1, drawPos_y+mass_size+1, 0), GMVector3D(drawPos_x, drawPos_y+mass_size+1, 0),
                     GMVector3D(0, 0, -1), GMVector3D(0, 0, -1),
                     GMVector3D(0, 0, -1), GMVector3D(0, 0, -1),
                     GMVector2D(1.0/8*3, 0), GMVector2D(1.0/8*4, 0),
                     GMVector2D(1.0/8*4, 1), GMVector2D(1.0/8*3, 1));
    GMDraw::End();
    
//    デバッグ用。部屋番号を描画。
//    if(m_room){
//        ostringstream oss;
//        oss << m_room->getRoomNumber();
//        GMColor color = GMColor::PaleVioletRed;
//        color.a = 0.7;
//        
//        // TODO: 部屋番号の描画の実装
//        // m_scene->getFont()->drawString(s, oss.str().c_str(), GMVector2D(drawPos_x, drawPos_y), color, 0.9);
//    }
    // マス上の　サクマ、　敵、　アイテム、　ブロック（水面等を含む）　の描画。
    // for 文で纏めるために、描画する可能性のある SKObject ポインタを配列にする。
    
    SKObject* massObjects[3];
    massObjects[0] = m_movingObject;
    massObjects[1] = m_item;
    massObjects[2] = m_block;
    // 配列の回数分描画。ポインタがNULLの場合はその SKObject は現時点マス上に無いので、描画しない。
    for(int i = 0; i < 3; i++){
        if(massObjects[i]){
            massObjects[i]->objectDraw(drawPos_x, drawPos_y);
        }
    }
}

SKMass* SKMass::getMassForOffset(int x, int y){
    int px, py;
    getPos(px, py);
    px += x;
    py += y;
    return m_scene->getMassMan()->get(px, py);
}

bool SKMass::isInterOuterMass(){
    int size = (int)getRoom()->getEntranceMasses()->size();
    for(int i = 0; i < size; i++){
        if(this == (*getRoom()->getEntranceMasses())[i]){
            return true;
        }
    }
    return false;
}

// 現在いる部屋を取得
_room* SKMass::getRoom(){
    return m_room;
}

void SKMass::setRoom(_room* room){
    m_room = room;
}


// 今いる部屋を検索して格納
void SKMass::seachRoom(){
    vector<_room*> rooms = m_scene->getMassMan()->getRooms();
    int size = (int)rooms.size();
    for(int i = 0; i < size; i++){
        if(rooms[i]->isInRoom(this)){
            this->setRoom(rooms[i]);
            return;
        }
    }
}

void SKMass::getDrawPoint(int& dx, int& dy) const{
    m_scene->getMassMan()->convertDrawIndex(this, dx, dx);
    
    dx = dx*mass_size-massDrawOffset_x;
    dy = dy*mass_size-massDrawOffset_y;
}

// 探索済み
bool SKMass::isSearhed(){
    return m_sarchFlag;
}
// 探索
void SKMass::seached(){
    this->m_sarchFlag = true;
}
// クリア
void SKMass::seachClear(){
    this->m_sarchFlag = false;
}

void SKMass::getOffset(SKMass* tar, int& x, int& y){
    tar->getPos(x, y);
    x -= this->m_xIndex;
    y -= this->m_yIndex;
}
