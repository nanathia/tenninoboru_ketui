//
//  SKMoveObject.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/13.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKMoveObject.h"
#include "SaKumas_includes.h"
#include "ScmlFunctions.h"
#include "SKEnemyState.h"
#include "SKDungeonScene.h"
#include <sstream>

SKMoveObject::SKMoveObject():
SKObject(),
m_hp(100),
m_time(0),
spin(false),
m_turnActionCounter(0),
m_objHeight(0),
m_isDamaged(0)
{
}

SKMoveObject::~SKMoveObject(){
    
}

void SKMoveObject::attack(){
    
    if(this->getName() == "サクマ"){
    }else{
        reinterpret_cast<SKEnemy*>(this)->resetMoveOrAction();
    }
    m_time = 0;
    this->animeName = "attack";
    SKObject* o = this->getForwordObject();
    if(o) dynamic_cast<SKMoveObject*>(o)->damage(10, this);
    
}

bool SKMoveObject::objectUpdate(GMInput* input, double deltaTime){
    this->m_time += deltaTime * 1.3;
    if(m_time >= 1){
        SKEnemy* e = dynamic_cast<SKEnemy*>(this);
        m_time = 0.0;
        animeName = "stop";
        if(e && getHp() <= 0) return true;
    }
    
    return false;
}

int SKMoveObject::getHp() const{
    return m_hp;
}

void SKMoveObject::actionCount(){
    if(m_turnActionCounter <= 0){
        GMException("行動限界の突破");
    }
    m_turnActionCounter--;
}

void SKMoveObject::actionReset(){
    m_turnActionCounter = 1;
}

bool SKMoveObject::isActionEnabled(){
    return m_turnActionCounter > 0 ? true: false;
}

const std::string& SKMoveObject::getAnimeName(){
    return animeName;
}

// 移動可能なマスかどうか
bool SKMoveObject::isEnableMoveMass(SKMass *mass){
    int px, py, tx, ty;
    this->getMass()->getPos(px, py);
    mass->getPos(tx, ty);
    tx -= px;
    ty -= py;
    if(tx && !ty){
        if(!mass->getBlock() && !mass->getMovingObject()) return true;
    }else if(!tx && ty){
        if(!mass->getBlock() && !mass->getMovingObject()) return true;
    }else if(tx && ty){
        if(!mass->getBlock() && !mass->getMovingObject()){
            SKMass* xmass = this->getMassForOffset(tx, 0);
            SKMass* ymass = this->getMassForOffset(0, ty);
            if(!xmass->getBlock() && !ymass->getBlock()){
                return true;
            }
        }
    }
    return false;
}

bool SKMoveObject::isEnableAttackMass(SKMass *mass){
    int px, py, tx, ty;
    this->getMass()->getPos(px, py);
    mass->getPos(tx, ty);
    tx -= px;
    ty -= py;
    if(tx && !ty){
        if(!mass->getBlock()) return true;
    }else if(!tx && ty){
        if(!mass->getBlock()) return true;
    }else if(tx && ty){
        if(!mass->getBlock()){
            SKMass* xmass = this->getMassForOffset(tx, 0);
            SKMass* ymass = this->getMassForOffset(0, ty);
            if(!xmass->getBlock() && !ymass->getBlock()){
                return true;
            }
        }
    }
    return false;
}

// ダメージを受けたか
bool SKMoveObject::isDamaged(){
    return m_isDamaged;
}

void SKMoveObject::damage(int point, SKMoveObject* obj){
    m_isDamaged = true;
    m_hp -= point;
    this->setSKObjectAngle(obj);
    std::ostringstream oss;
    if(obj->getName() != "サクマ"){
        oss << obj->getName() << "から、" << SKUserInterface::convertNum2Str(point) << "のダメージを受けた！";
    }else{
        oss << this->getName() << "に" << SKUserInterface::convertNum2Str(point) << "のダメージを与えた。";
    }
    gPlayScene->getDungeonScene()->getUI()->textInput(oss.str());
}

void SKMoveObject::damaged(){
    m_isDamaged = false;
}

void SKMoveObject::getLocalizeOffset(SKMass* mass, int& x, int& y){
    this->getMass()->getOffset(mass, x, y);
    localize(x, y);
}

SKMass* SKMoveObject::getMassForAngle(SKMass* mass){
    int x, y;
    getLocalizeOffset(mass, x, y);
    return this->getMassForOffset(x, y);
}



