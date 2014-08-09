//
//  SyokutyuuState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/02.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SyokutyuuState.h"
#include "Spriter/ScmlFunctions.h"
#include "SaKumas_includes.h"
#include "SKEnemyMoveState.h"

namespace enemyState{

    SyokutyuuLeady::SyokutyuuLeady():
    SKEnemyState()
    {
    }
    SyokutyuuLeady::~SyokutyuuLeady(){
    }
    SKEnemyState* SyokutyuuLeady::update(GMInput* input, double deltaTime, SKEnemy* enem){
        SKEnemyState* next = this;
        if(enem->isMove() && !enem->isMeetingPlayer()){
            // 移動する場合
            // 行動をカウント
            enem->actionCount();
            // 移動先を決定
            SKMass* start = enem->getMass();
            SKMass* end = enem->getMove()->getNext();
            // 移動処理
            if(start && end){
                enem->setPreviousMass(start);
                enem->setSKObjectAngle(end);
                start->setMovingObject(0);
                end->setMovingObject(enem);
                next = new SyokutyuuMove(start, end);
                enem->doAct();
                next->update(input, deltaTime, enem);
                enem->resetMoveOrAction();
            }
        }else if(enem->isAction() && enem->isMeetingPlayer()){
            enem->setSKObjectAngle(gPlayScene->getPlayer());
            SKEnemyState* attack = new SyokutyuuAttack();
            next = attack->update(input, deltaTime, enem);
            if(next != attack){
                delete attack;
                attack = 0;
            }else{
                enem->doAct();
            }
        }else if(enem->isDamaged()){
            next = new SyokutyuuDamage();
            enem->damaged();
        }else if(enem->isMeetingPlayer()){
            
        }
        enem->resetMoveOrAction();
        if(m_animationTime >= 1){
            m_animationTime = 0;
        }
        m_animationTime += deltaTime*2;
        return next;
    }
    void SyokutyuuLeady::draw(int dx, int dy, SKEnemy* enem){
        GMVector2D d(dx, dy);
        spriter::ScmlFunctions::setAnimation("syokutyuu", "stop");
        spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 0), 0.20, GMVector3D(0, enem->getRadian(), 0), m_animationTime);
    }
    
    SyokutyuuMove::SyokutyuuMove(SKMass* start, SKMass* end):
    SKEnemyState(),
    m_start(start),
    m_end(end)
    {
    }
    SyokutyuuMove::~SyokutyuuMove(){
    }
    SKEnemyState* SyokutyuuMove::update(GMInput* input, double deltaTime, SKEnemy* enem){
        SKEnemyState* next = this;
        m_time += deltaTime*4;
        m_animationTime += deltaTime*4;
        if(m_time >= 1){
            enem->doEnd();
            SKEnemyState* leady = new SyokutyuuLeady();
            next = leady->update(input, deltaTime, enem);
            if(leady != next){
                delete leady;
                leady = 0;
            }
        }
        return next;
    }
    void SyokutyuuMove::draw(int dx, int dy, SKEnemy* enem){
        GMVector2D d = SKObject::getLarpPoint(m_start, m_end, dx, dy, m_time);
        spriter::ScmlFunctions::setAnimation("syokutyuu", "move");
        spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 0), 0.20, GMVector3D(0, enem->getRadian(), 0), m_animationTime);
    }
    
    SyokutyuuAttack::SyokutyuuAttack():
    SKEnemyState(){
    }
    SyokutyuuAttack::~SyokutyuuAttack(){
    }
    SKEnemyState* SyokutyuuAttack::update(GMInput* input, double deltaTime, SKEnemy* enem){
        SKEnemyState* next = this;
        if(m_time >= 1){
            enem->doEnd();
            SKEnemyState* leady = new SyokutyuuLeady();
            next = leady->update(input, deltaTime, enem);
            if(next != leady){
                delete leady;
                leady = 0;
            }
            if(SKObject* mo = enem->getMassForRadian(enem->getRadian())->getMovingObject()){
                if(mo->getName() == "サクマ"){
                    gPlayScene->getPlayer()->damage(10, enem);
                }
            }
        }
        m_time += deltaTime*5;
        m_animationTime += deltaTime*5;
        return next;
    }
    void SyokutyuuAttack::draw(int dx, int dy, SKEnemy* enem){
        GMVector2D d(dx, dy);
        spriter::ScmlFunctions::setAnimation("syokutyuu", "attack");
        spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 0), 0.20, GMVector3D(0, enem->getRadian(), 0), m_animationTime);
    }
    
    SyokutyuuDamage::SyokutyuuDamage():
    SKEnemyState()
    {
    }
    SyokutyuuDamage::~SyokutyuuDamage(){
    }
    SKEnemyState* SyokutyuuDamage::update(GMInput* input, double deltaTime, SKEnemy* enem){
        SKEnemyState* next = this;
        if(m_time >= 1){
            if(enem->getHp() <= 0){
                if(m_time >= 2){
                    enem->upFlag(SKEnemy::state_dead);
                    enem->doEnd();
                }
                m_animationTime += deltaTime*10;
            }else{
                enem->doEnd();
                SKEnemyState* leady = new SyokutyuuLeady();
                next = leady->update(input, deltaTime, enem);
                if(leady != next){
                    delete leady;
                    leady = 0;
                }
            }
        }
        m_time += deltaTime*5;
        m_animationTime += deltaTime*5;
        return next;
    }
    void SyokutyuuDamage::draw(int dx, int dy, SKEnemy* enem){
        GMVector2D d(dx, dy);
        spriter::ScmlFunctions::setAnimation("syokutyuu", "damage");
        spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 0), 0.20, GMVector3D(0, enem->getRadian(), 0), m_animationTime);
    }

}