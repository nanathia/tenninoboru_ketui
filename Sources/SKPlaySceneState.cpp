//
//  SKPlaySceneState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKPlaySceneState.h"
#include "SKSceneChangeInters.h"
#include "SKSceneChangeOuters.h"
#include "SKDungeonScene.h"
#include "SKBaseAreaScene.h"
#include "SKMapSelect.h"
#include "SKPlayScene.h"

SKPlaySceneState::SKPlaySceneState(SKPlayScene* user):
m_child(0),
m_user(user){
    m_child = new SKPlaySceneGame(user);
}
SKPlaySceneState::~SKPlaySceneState(){
    delete m_child;
    m_child = 0;
}
void SKPlaySceneState::update(GMInput* input, double deltaTime){
    SKPlaySceneStateChild* nextChild = m_child->update(input, deltaTime);
    if(m_child != nextChild){
        delete m_child;
        m_child = nextChild;
    }
}
void SKPlaySceneState::draw(GMSpriteBatch* s){
    if(m_child) m_child->draw(s);
};

void SKPlaySceneState::changeScene(SKPlayChild *prevChild, SKPlayChild *nextChild){
    // シーン遷移中に呼ぶとバグる
    m_child->changeScene(prevChild, nextChild);
}
SKDungeonScene* SKPlaySceneState::getDungeonScene(){
    return m_child->getDungeonScene();
}
baseArea::SKBaseAreaScene* SKPlaySceneState::getBaseAreaScene(){
    return m_child->getBaseAreaScene();
}

SKPlaySceneStateChild::SKPlaySceneStateChild(SKPlayScene*user):
m_user(user){
}
SKPlaySceneStateChild::~SKPlaySceneStateChild(){
}
void SKPlaySceneStateChild::changeScene(SKPlayChild* prev, SKPlayChild* next){
    // Do nothing 遷移中に遷移命令が来た場合無視。デバッグ時のために、エラーを入れる。
    GMException("error: Already change Scene now");
}

SKPlaySceneGame::SKPlaySceneGame(SKPlayScene* user):
SKPlaySceneStateChild(user),
m_nextState(0){
}
SKPlaySceneGame::~SKPlaySceneGame(){
}
SKPlaySceneStateChild* SKPlaySceneGame::update(GMInput* input, double deltaTime){
    SKPlaySceneStateChild* next = this;
    //---------------------------------------------------------------------
    // メインゲームの遷移と更新する。ここはその為の状態なので。逆に、上では子を更新しない（この場所に移譲するため）
    SKPlayChild* nextChild = m_user->getChild()->update(input, deltaTime);
    if(nextChild != m_user->getChild()){
        delete m_user->getChild();
        m_user->setChild(nextChild);
        nextChild = 0;
    }
    //---------------------------------------------------------------------
    if(m_nextState){
        next = m_nextState;
        m_nextState = 0;
    }
    return next;
}
void SKPlaySceneGame::draw(GMSpriteBatch* s){
    m_user->getChild()->draw(s);
};
void SKPlaySceneGame::changeScene(SKPlayChild *prev, SKPlayChild *next){
    m_nextState = SKPlaySceneOuter::createOuter(prev, next, m_user);
}
SKDungeonScene* SKPlaySceneGame::getDungeonScene(){
#if IS_DEBUG
    if(!dynamic_cast<SKDungeonScene*>(m_user->getChild())) GMException("reference to no scene");
#endif
    return reinterpret_cast<SKDungeonScene*>(m_user->getChild());
}
baseArea::SKBaseAreaScene* SKPlaySceneGame::getBaseAreaScene(){
#if IS_DEBUG
    if(!dynamic_cast<baseArea::SKBaseAreaScene*>(m_user->getChild())) GMException("reference to no scene");
#endif
    return reinterpret_cast<baseArea::SKBaseAreaScene*>(m_user->getChild());
}

SKPlaySceneInter::SKPlaySceneInter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
SKPlaySceneStateChild(user),
m_nextChild(nextChild),
m_prevChild(prevChild),
m_time(0){
}
SKPlaySceneInter::~SKPlaySceneInter(){
    delete m_prevChild;
    m_prevChild = 0;
    m_user->setChild(m_nextChild);
    m_nextChild = 0;
}
SKPlaySceneStateChild* SKPlaySceneInter::update(GMInput* input, double deltaTime){
    SKPlaySceneStateChild* next = this;
    // Do nothing
    return next;
}
void SKPlaySceneInter::draw(GMSpriteBatch* s){
};
// どれを作るべきか、勝手に判断して作るメソッド
SKPlaySceneInter* SKPlaySceneInter::createInter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user){
    SKPlaySceneInter* ret = 0;
    if(dynamic_cast<SKDungeonScene*>(nextChild)){
        ret = new playsceneinter::Dungeon(prevChild, nextChild, user);
    }else if(dynamic_cast<mapSelect::SKMapSelectScene*>(nextChild)){
        ret = new playsceneinter::MapSelect(prevChild, nextChild, user);
    }else if(dynamic_cast<baseArea::SKBaseAreaScene*>(nextChild)){
        ret = new playsceneinter::BaseArea(prevChild, nextChild, user);
    }else{
        GMException("error: missing playScene");
        ret = 0;
    }
    return ret;
}
SKDungeonScene* SKPlaySceneInter::getDungeonScene(){
    SKDungeonScene* ret = 0;
    if((ret = dynamic_cast<SKDungeonScene*>(m_prevChild))){
        return ret;
    }else if((ret = dynamic_cast<SKDungeonScene*>(m_nextChild))){
        return ret;
    }else{
        GMException("nothing to reference");
        return 0;
    }
}
baseArea::SKBaseAreaScene* SKPlaySceneInter::getBaseAreaScene(){
    baseArea::SKBaseAreaScene* ret = 0;
    if((ret = dynamic_cast<baseArea::SKBaseAreaScene*>(m_prevChild))){
        return ret;
    }else if((ret = dynamic_cast<baseArea::SKBaseAreaScene*>(m_nextChild))){
        return ret;
    }else{
        GMException("nothing to reference");
        return 0;
    }
}

SKPlaySceneOuter::SKPlaySceneOuter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user):
SKPlaySceneStateChild(user),
m_prevChild(prevChild),
m_nextChild(nextChild),
m_time(0){
}
SKPlaySceneOuter::~SKPlaySceneOuter(){
}
SKPlaySceneStateChild* SKPlaySceneOuter::update(GMInput* input, double deltaTime){
    SKPlaySceneStateChild* next = this;
    return next;
}
void SKPlaySceneOuter::draw(GMSpriteBatch* s){
}
// どれを作るべきか、勝手に判断して作るメソッド
SKPlaySceneOuter* SKPlaySceneOuter::createOuter(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user){
    SKPlaySceneOuter* ret = 0;
    if(dynamic_cast<SKDungeonScene*>(prevChild)){
        ret = new playsceneouter::Dungeon(prevChild, nextChild, user);
    }else if(dynamic_cast<mapSelect::SKMapSelectScene*>(prevChild)){
        ret = new playsceneouter::MapSelect(prevChild, nextChild, user);
    }else if(dynamic_cast<baseArea::SKBaseAreaScene*>(prevChild)){
        ret = new playsceneouter::BaseArea(prevChild, nextChild, user);
    }else{
        GMException("error: missing playScene");
        ret = 0;
    }
    return ret;
}
SKDungeonScene* SKPlaySceneOuter::getDungeonScene(){
    SKDungeonScene* ret = 0;
    if((ret = dynamic_cast<SKDungeonScene*>(m_prevChild))){
        return ret;
    }else if((ret = dynamic_cast<SKDungeonScene*>(m_nextChild))){
        return ret;
    }else{
        GMException("nothing to reference");
        return 0;
    }
}
baseArea::SKBaseAreaScene* SKPlaySceneOuter::getBaseAreaScene(){
    baseArea::SKBaseAreaScene* ret = 0;
    if((ret = dynamic_cast<baseArea::SKBaseAreaScene*>(m_prevChild))){
        return ret;
    }else if((ret = dynamic_cast<baseArea::SKBaseAreaScene*>(m_nextChild))){
        return ret;
    }else{
        GMException("nothing to reference");
        return 0;
    }
}

