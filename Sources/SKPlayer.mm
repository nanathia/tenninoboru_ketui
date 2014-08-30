//
//  SKPlayer.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKPlayer.h"
#include "SaKumas_includes.h"
#include "PlayerPorch.h"
#include "GameMain.h"
#include <cmath>
#include <cstdio>
#include "spriterFiles.h"
#include "CallBack.h"
#include "SKItemInclude.h"
#include "SKDungeonScene.h"
#include <sstream>

SKPlayer::SKPlayer(SKDungeonScene* scene):
SKMoveObject(scene),
m_exitMass(0),
m_animation(0),
m_porch(0),
m_turnControl(0),
m_isItemSelectEnd(false),
m_equipmentShield(0),
m_equipmentUdewa_1(0),
m_equipmentUdewa_2(0),
m_equipmentSword(0),
m_state(0),
m_isAct(0)
{
    // アプリケーション・バンドル内のリソース位置を取得
    NSURL *fileURL = [[NSBundle mainBundle] URLForResource:@"sakuma" withExtension:@"scml"];
    if (!fileURL) {
        NSLog(@"Error: Failed to locate sakuma.scml file!!");
        exit(1);
    }

    // OSX内部でのパス表現はUTF-8のC言語文字列
    m_animation = new spriter::ScmlObject(fileURL.path.UTF8String);
    spriter::ScmlFunctions::SetScml(m_animation);
    this->animeName = "stop";
    this->characterName = "sakuma";
    this->m_porch = new PlayerPorch(m_scene);
    this->m_objectName = "サクマ";
    this->m_turnControl = new _turnControl(this);
    this->m_state = new PlayerLeady(this);
    m_objHeight = 40;
}

SKPlayer::~SKPlayer(){
    delete m_animation;
    m_animation = 0;
    safeCleanUp(m_walked_way);
}

bool SKPlayer::objectUpdate(GMInput* input, double deltaTime){
    
    SKPlayerState* child = m_state->update(input, deltaTime);
    if(m_state != child){
        delete m_state;
        m_state = child;
        child = 0;
    }
    
    SKMoveObject::objectUpdate(input, deltaTime);
    if(this->getHp() <= 0){
        //FIXME ゲームオーバーの復帰
//        gGameInst->ChangeScene("gameOver");
    }
    
    return true;
}

void SKPlayer::objectDraw(int d_x, int d_y){
    this->m_state->draw(d_x, d_y);
}

void SKPlayer::objectInit(GMGraphics* g){
    
}

// 移動元を取得
SKMass* SKPlayer::getPreviousMass() const{
    return m_previousMass;
}

void SKPlayer::extendFloor(){
    m_walked_way.clear();
}

// 部屋を出たマスを取得
SKMass* SKPlayer::getExitEntrance() const{
    return m_exitMass;
}

_turnControl::_turnControl(SKPlayer* parent):
m_parent(parent){
    
}

void _turnControl::actionCreate(){
    std::list<SKEnemy*>& em = m_parent->getScene()->getEnemMan()->m_enemys;
    auto it = em.begin();
    while(it != em.end()){
        (*it)->actionReset();
        it++;
    }
    it = em.begin();
    while(it != em.end()){
        m_actionEnemys.push_back(*it);
        it++;
    }
    
}

bool _turnControl::move(){
    auto em = m_parent->getScene()->getEnemMan()->m_enemys;
    auto it = em.begin();
    while(it != em.end()){
        (*it)->setMove();
        it++;
    }
    return true;
}

bool _turnControl::isAction(){
    return m_actionEnemys.empty() ? false: true;
}

bool _turnControl::action(){
    if(m_actionEnemys.empty()){
        GMException("アクションが空");
    }
    bool returnKey = false;
    if((*m_actionEnemys.begin())->isActionEnabled()){
        (*m_actionEnemys.begin())->setAction();
        (*m_actionEnemys.begin())->actionCount();
        returnKey = true;
    }else{
        returnKey = false;
    }
    *m_actionEnemys.begin() = 0;
    m_actionEnemys.erase(m_actionEnemys.begin());
    return returnKey;
}

PlayerPorch* SKPlayer::getPorch(){
    return m_porch;
}

void SKPlayer::endItemSelect(){
    m_isItemSelectEnd = true;
}

void SKPlayer::soubiSword(SwordItem* sword){
    if(!sword){
        std::ostringstream oss;
        oss << m_equipmentSword->getName() << "　を外した。";
        m_scene->getUI()->textInput(oss.str());
        m_equipmentSword = 0;
    }else{
        m_equipmentSword = sword;
        std::ostringstream oss;
        oss << sword->getName() << "　を装備した。";
        m_scene->getUI()->textInput(oss.str());
    }
}

void SKPlayer::soubiShiled(ShieldItem* shield){
    if(!shield){
        std::ostringstream oss;
        oss << m_equipmentShield->getName() << "　を外した。";
        m_scene->getUI()->textInput(oss.str());
        m_equipmentSword = 0;
    }else{
        m_equipmentShield = shield;
        std::ostringstream oss;
        oss << shield->getName() << "　を装備した。";
        m_scene->getUI()->textInput(oss.str());
    }
}

void SKPlayer::soubiUdewa_1(UdewaItem* udewa){
    if(!udewa){
        std::ostringstream oss;
        oss << m_equipmentUdewa_1->getName() << "　を外した。";
        m_scene->getUI()->textInput(oss.str());
        m_equipmentSword = 0;
    }else{
        m_equipmentUdewa_1 = udewa;
        std::ostringstream oss;
        oss << udewa->getName() << "　を装備した。";
        m_scene->getUI()->textInput(oss.str());
    }
}

void SKPlayer::soubiUdewa_2(UdewaItem* udewa){
    if(!udewa){
        std::ostringstream oss;
        oss << m_equipmentUdewa_2->getName() << "　を外した。";
        m_scene->getUI()->textInput(oss.str());
        m_equipmentSword = 0;
    }else{
        m_equipmentUdewa_2 = udewa;
        std::ostringstream oss;
        oss << udewa->getName() << "　を装備した。";
        m_scene->getUI()->textInput(oss.str());
    }
}

SwordItem* SKPlayer::getSword(){
    return m_equipmentSword;
}

ShieldItem* SKPlayer::getShield(){
    return m_equipmentShield;
}

UdewaItem* SKPlayer::getUdewa_1(){
    return m_equipmentUdewa_1;
}

UdewaItem* SKPlayer::getUdewa_2(){
    return m_equipmentUdewa_2;
}

GMVector2D SKPlayer::getCameraPos(int dx, int dy){
    return m_state->getCameraPos(dx, dy);
}

bool SKPlayer::isAct(){
    return m_isAct;
}

void SKPlayer::doAct(){
    m_isAct = true;
}

void SKPlayer::doEnd(){
    m_isAct = false;
}

SKDungeonScene* SKPlayer::getDungeonScene(){
    return m_scene;
}

