//
//  SKEnemyMoveChild.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/04.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKEnemyMoveChild.h"
#include "SaKumas_includes.h"
#include "SKDungeonScene.h"
#include "randam_dungeon.h"

namespace enemyMove{

    MoveChild::MoveChild(SKEnemy* e):
    m_parent(e)
    {
    }
    MoveChild::~MoveChild(){
    }
    
    MoveLeady::MoveLeady(SKEnemy* e):
    MoveChild(e){
    }
    MoveLeady::~MoveLeady(){
    }
    MoveChild* MoveLeady::updateNext(SKMass*& nextMass){
        MoveChild* next = this;
        nextMass = 0;
        // プレイヤー見えるかい
        if(m_parent->isSameRoomWithPlayer() || m_parent->isOneStepAttackToPlayer()){
            // なら追いかけよう
            next = new MoveChace(m_parent);
            nextMass = m_parent->isNomalMoveMass(m_parent->getScene()->getPlayer()->getMass());
        }else{
            // プレイヤー見えねえ
            // なら適当に動くか
            // 部屋内か通路か
            if(m_parent->getMass()->getRoom()){
                // 部屋内だからまあどっかの出口を目指そう
                nextMass = m_parent->getRandomRoomExitMass();
                if(!nextMass){
                    // 出口はないようだ
                    // なら適当に動くわ
                    int rnd = randam_dungeon::rand(0, 7);
                    double rndRad = 0.25*rnd;
                    nextMass = m_parent->isNomalMoveMass(m_parent->getMassForRadian(rndRad));
                }else{
                    // 出口はあるようだ
                    next = new MoveRoom(m_parent, nextMass);
                    next->updateNext(nextMass);
                }
            }else{
                // 通路だからまあ普通に移動しよう
                nextMass = m_parent->isNomalMoveMass(m_parent->getMassForOffset(1, 0));
                if(nextMass){
                    next = new MovePassage(m_parent, nextMass);
                }else{
                    // 移動できない
                }
            }
        }
        return next;
    }
    
    MoveRoom::MoveRoom(SKEnemy* e, SKMass* target):
    MoveChild(e),
    m_exitMass(target){
    }
    MoveRoom::~MoveRoom(){
    }
    MoveChild* MoveRoom::updateNext(SKMass*& nextMass){
        MoveChild* next = this;
        if(m_parent->isSameRoomWithPlayer() || m_parent->isOneStepAttackToPlayer()){
            // プレイヤー見っけ
            next = new MoveChace(m_parent);
            next->updateNext(nextMass);
        }else if(m_exitMass == m_parent->getMass()){
            // ああもう出口だわ
            // じゃあ通路を探す
            nextMass = m_parent->getPassasgeInterMass();
            if(nextMass){
                // 次は通路を進行するのじゃ
                next = new MovePassage(m_parent, nextMass);
                nextMass = m_parent->isNomalMoveMass(nextMass);
            }else{
                // 通路が無い。もとい、通路に何かあって進めない。
                // じゃあ退くまで待とう。
                nextMass = m_parent->isNomalMoveMass(m_parent->getPassageInterMassOnMoveObject());
            }
        }else{
            // ああ出口まだだわ
            // じゃあまあ向かおう
            nextMass = m_parent->isNomalMoveMass(m_exitMass);
        }
        return next;
    }
    
    MoveChace::MoveChace(SKEnemy* e):
    MoveChild(e){
    }
    MoveChace::~MoveChace(){
    }
    MoveChild* MoveChace::updateNext(SKMass*& nextMass){
        MoveChild* next = this;
        if(m_parent->isSameRoomWithPlayer() || m_parent->isOneStepAttackToPlayer()){
            // まだプレイヤー見えるから追うわ
            nextMass = m_parent->isNomalMoveMass(m_parent->getScene()->getPlayer()->getMass());
        }else{
            // プレイヤー見えなくなったから適当に歩くわ
            MoveChild* leady = new MoveLeady(m_parent);
            next = leady->updateNext(nextMass);
            if(leady != next){
                delete leady;
            }
        }
        return next;
    }
    
    MovePassage::MovePassage(SKEnemy* e, SKMass*& angleMass):
    MoveChild(e),
    m_angle(e->getRadianForMass(angleMass)){
    }
    MovePassage::~MovePassage(){
    }
    MoveChild* MovePassage::updateNext(SKMass*& nextMass){
        MoveChild* next = this;
        if(m_parent->isSameRoomWithPlayer() || m_parent->isOneStepAttackToPlayer()){
            // プレイヤー見っけ
            next = new MoveChace(m_parent);
            next->updateNext(nextMass);
        }else if(m_parent->getMass()->getRoom()){
            // 部屋入ったわ
            // じゃあまあ切り替え
            MoveChild* room = new MoveRoom(m_parent, m_parent->getRandomRoomExitMass());
            // て、一回更新
            next = room->updateNext(nextMass);
            if(room != next){
                delete room;
            }
        }else{
            // まだ通路だわ
            // じゃあまあ直進
            if(SKMass* t = m_parent->getMassForRadian(m_angle)){
                if(m_parent->isEnableMoveMass(t)){
                    // 直進できるならそれでよし
                    nextMass = t;
                }else{
                    // 直進できねえ！ジーザス！
                    // じゃあ左だ！
                    if((t = m_parent->getMassForRadian(m_angle+0.5))){
                        if(m_parent->isEnableMoveMass(t)){
                            // 左行けるわー
                            m_angle += 0.5;
                            nextMass = t;
                        }else{
                            if((t = m_parent->getMassForRadian(m_angle-0.5))){
                                if(m_parent->isEnableMoveMass(t)){
                                    m_angle -= 0.5;
                                    nextMass = t;
                                }else{
                                    // じゃあもう後ろしか無くね
                                    if((t = m_parent->getMassForRadian(m_angle-1.0))){
                                        if(m_parent->isEnableMoveMass(t)){
                                            m_angle -= 1.0;
                                            nextMass = t;
                                        }else{
                                            // 移動を諦めた
                                            nextMass = 0;
                                            next = new MoveLeady(m_parent);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return next;
    }
    
}