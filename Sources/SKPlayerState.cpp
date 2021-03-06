//
//  SKPlayerState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/13.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKPlayerState.h"
#include "SaKumas_includes.h"
#include "Spriter/ScmlFunctions.h"
#include "PlayerPorch.h"
#include <string>

SKPlayerState::SKPlayerState(SKPlayer* user):
m_user(user),
m_time(0),
m_animationTime(0)
{
    
}
GMVector2D SKPlayerState::getCameraPos(int dx, int dy){
    return GMVector2D(dx, dy);
}

PlayerWait::PlayerWait(SKPlayer* user):
SKPlayerState(user){
    
}
SKPlayerState* PlayerWait::update(GMInput* input, double deltaTime){
    SKPlayerState* next = this;
    
    return next;
}
void PlayerWait::draw(int dx, int dy){
    
}

PlayerMoving::PlayerMoving(SKPlayer* user, SKMass* begin, SKMass* end):
m_startMass(begin),
m_endMass(end),
SKPlayerState(user)
{
    begin->setMovingObject(0);
    end->setMovingObject(m_user->getScene()->getPlayer());
    m_user->getScene()->getPlayer()->setPreviousMass(begin);
    m_user->getScene()->getPlayer()->doAct();
}
PlayerMoving::~PlayerMoving(){
    m_startMass = 0;
    m_endMass = 0;
}
SKPlayerState* PlayerMoving::update(GMInput *input, double deltaTime){
    SKPlayer* p = m_user->getScene()->getPlayer();
    SKPlayerState* next = this;
    m_time += deltaTime*3;
    if(m_time >= 1.0){
        m_user->getScene()->getPlayer()->doEnd();
        p->getPorch()->getItem_myMass();
        if(!p->getTurn()->m_actionEnemys.empty()){
            SKPlayerState* wait = new PlayerWaitingEnemyAction(m_user);
            next = wait->update(input, deltaTime);
            if(next != wait){
                delete wait;
                wait = 0;
            }
        }else{
            SKPlayerState* leady = new PlayerLeady(m_user);
            next = leady->update(input, deltaTime);
            if(next != leady){
                delete leady;
            }
            next->update(input, deltaTime);
            leady = 0;
        }
    }
    return next;
}
void PlayerMoving::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d = SKObject::getLarpPoint(m_startMass, m_endMass, dx, dy, m_time);
    spriter::ScmlFunctions::setAnimation(p->characterName.c_str(), "move");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_time);
}
GMVector2D PlayerMoving::getCameraPos(int dx, int dy){
    return SKObject::getLarpPoint(m_endMass, m_startMass, dx, dy, m_time);
}

PlayerLeady::PlayerLeady(SKPlayer* user):
SKPlayerState(user){
    user->actionReset();
    auto it = user->getDungeonScene()->getEnemMan()->m_enemys.begin();
    while(it != user->getDungeonScene()->getEnemMan()->m_enemys.end()){
        (*it)->actionReset();
        it++;
    }
}
SKPlayerState* PlayerLeady::update(GMInput* input, double deltaTime){
    SKPlayer* p = m_user->getScene()->getPlayer();
    SKPlayerState* next = this;
    
    int ofsx = 0;
    int ofsy = 0;
    
    if(input->isKeyDown(GMKeyMaskUp)){
        ofsy += 1;
    }
    if(input->isKeyDown(GMKeyMaskDown)){
        ofsy -= 1;
    }
    if(input->isKeyDown(GMKeyMaskLeft)){
        ofsx -= 1;
    }
    if(input->isKeyDown(GMKeyMaskRight)){
        ofsx += 1;
    }
    
    if(!m_user->getScene()->getEnemMan()->isAllActionEnded()){
    }else if(ofsx || ofsy){
        p->setRadian(atan2(ofsy, ofsx)/M_PI);
        SKMass* nextMass = p->getMassForOffset(ofsx, ofsy);
        if(p->isEnableMoveMass(nextMass)){
            next = new PlayerMoving(m_user, p->getMass(), nextMass);
            p->m_turnControl->actionCreate();
            p->m_turnControl->move();
        }
    }else if(input->isKeyDown(GMKeyMaskZ)){
        p->actionCount();
        next = new PlayerAttack(m_user);
    }else if(input->isKeyDownTriggered(GMKeyMaskSpace|GMKeyMaskI)){
        m_user->getScene()->getUI()->uiOn();
        next = new PlayerOpenMenu(m_user);
    }
    
    if(m_animationTime >= 1){
        m_animationTime = 0;
    }
    m_animationTime += deltaTime;
    
    return next;
}
void PlayerLeady::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d(dx, dy);
    spriter::ScmlFunctions::setAnimation(p->characterName.c_str(), "stop");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
}


PlayerChoiceAngle::PlayerChoiceAngle(SKPlayer* user):
SKPlayerState(user){
}
SKPlayerState* PlayerChoiceAngle::update(GMInput* input, double deltaTime){
    return this;
}
void PlayerChoiceAngle::draw(int dx, int dy){
    
}

PlayerNanameInput::PlayerNanameInput(SKPlayer* user):
SKPlayerState(user){
    
}
SKPlayerState* PlayerNanameInput::update(GMInput* input, double deltaTime){
    return this;
}
void PlayerNanameInput::draw(int dx, int dy){
    
}

PlayerAttack::PlayerAttack(SKPlayer* user):
SKPlayerState(user),
m_isAttacked(false){
    m_user->getScene()->getPlayer()->doAct();
}
PlayerAttack::~PlayerAttack(){
}
SKPlayerState* PlayerAttack::update(GMInput* input, double deltaTime){
    SKPlayerState* next = this;
    SKPlayer* p = m_user->getScene()->getPlayer();
    if(m_time >= 1){
        m_user->getScene()->getPlayer()->doEnd();
        p->getTurn()->actionCreate();
        p->getTurn()->move();
        SKPlayerState* wait = new PlayerWaitingEnemyMove(m_user);
        next = wait->update(input, deltaTime);
        if(wait != next){
            delete wait;
        }
        wait = 0;
    }else if(m_time>=0.5 && !m_isAttacked){
        SKMass* tm = p->getMassForRadian(p->getRadian());
        if(tm->getMovingObject()){
            SKEnemy* enem = dynamic_cast<SKEnemy*>(tm->getMovingObject());
            if(enem) enem->damage(200, p);
            enem->doAct();
        }
        m_isAttacked = true;
    }
    m_time += deltaTime*5;
    m_animationTime += deltaTime*5;
    return next;
}
void PlayerAttack::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d(dx, dy);
    spriter::ScmlFunctions::setAnimation("sakuma", "attack");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
}

PlayerOpenMenu::PlayerOpenMenu(SKPlayer* user):
SKPlayerState(user){
}
SKPlayerState* PlayerOpenMenu::update(GMInput *input, double deltaTime){
    SKPlayerState* next = this;
    if(input->isKeyDownTriggered(GMKeyMaskI) || m_user->getScene()->getPlayer()->m_isItemSelectEnd){
        next = new PlayerLeady(m_user);
        m_user->getScene()->getUI()->uiOff();
        m_user->getScene()->getPlayer()->m_isItemSelectEnd = false;
    }
    m_animationTime += deltaTime;
    if(m_animationTime >= 1) m_animationTime = 0;;
    return next;
}
void PlayerOpenMenu::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d(dx, dy);
    spriter::ScmlFunctions::setAnimation("sakuma", "stop");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
}

PlayerDamage::PlayerDamage(SKPlayer* user):
SKPlayerState(user){
    m_user->getScene()->getPlayer()->doAct();
}
PlayerDamage::~PlayerDamage(){
}
SKPlayerState* PlayerDamage::update(GMInput *input, double deltaTime){
    SKPlayerState* next = this;
    if(m_time >= 1){
        m_user->getScene()->getPlayer()->doEnd();
        SKPlayerState* wait = new PlayerWaitingEnemyAction(m_user);
        next = wait->update(input, deltaTime);
        if(next != wait){
            delete wait;
            wait = 0;
        }
    }
    m_time += deltaTime*5;
    m_animationTime += deltaTime*5;
    return next;
}
void PlayerDamage::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d(dx, dy);
    spriter::ScmlFunctions::setAnimation("sakuma", "damage");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
}

PlayerWaitingEnemyMove::PlayerWaitingEnemyMove(SKPlayer* user):
SKPlayerState(user){
}
SKPlayerState* PlayerWaitingEnemyMove::update(GMInput *input, double deltaTime){
    SKPlayerState* next = this;
    if(m_user->getScene()->getEnemMan()->isAllActionEnded()){
        if(m_user->getScene()->getPlayer()->getTurn()->m_actionEnemys.empty()){
            SKPlayerState* leady = new PlayerLeady(m_user);
            next = leady->update(input, deltaTime);
            if(next != leady){
                delete leady;
            }
            next->update(input, deltaTime);
            leady = 0;
        }else{
            next = new PlayerWaitingEnemyAction(m_user);
        }
    }
    m_animationTime += deltaTime*2;
    return next;
}
void PlayerWaitingEnemyMove::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d(dx, dy);
    spriter::ScmlFunctions::setAnimation("sakuma", "stop");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
}

PlayerWaitingEnemyAction::PlayerWaitingEnemyAction(SKPlayer* user):
SKPlayerState(user){
}
SKPlayerState* PlayerWaitingEnemyAction::update(GMInput *input, double deltaTime){
    SKPlayerState* next = this;
    SKPlayer* p = m_user->getScene()->getPlayer();
    bool isNextAction = m_user->getScene()->getEnemMan()->isAllActionEnded();
    if(isNextAction && !p->getTurn()->m_actionEnemys.empty()){
        if(p->isDamaged()){
            p->damaged();
            next = new PlayerDamage(m_user);
            next->update(input, deltaTime);
        }else{
            while(true){
                if(p->getTurn()->m_actionEnemys.empty()) break;
                if(p->getTurn()->action()) break;
            }
        }
    }
    if(p->getTurn()->m_actionEnemys.empty() && isNextAction){
        SKPlayerState* leady = new PlayerLeady(m_user);
        next = leady->update(input, deltaTime);
        if(next != leady){
            delete leady;
        }
        next->update(input, deltaTime);
        leady = 0;
    }
    if(m_animationTime >= 1){
        m_animationTime = 0;
    }
    m_animationTime += deltaTime*2;
    return next;
}
void PlayerWaitingEnemyAction::draw(int dx, int dy){
    SKPlayer* p = m_user->getScene()->getPlayer();
    GMVector2D d(dx, dy);
    spriter::ScmlFunctions::setAnimation("sakuma", "stop");
    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
}


// テンプレ
//Player::Player():
//SKPlayerState(){
//}
//SKPlayerState* Player::update(GMInput *input, double deltaTime){
//    SKPlayerState* next = this;
//    if(m_time >= 1){
//        SKPlayerState* leady = new PlayerLeady();
//        next = leady->update(input, deltaTime);
//        if(next != leady){
//            delete leady;
//        }
//        next->update(input, deltaTime);
//        leady = 0;
//    }
//    m_time += deltaTime;
//    return next;
//}
//void Player::draw(int dx, int dy){
//    SKPlayer* p = m_user->getScene()->getPlayer();
//    GMVector2D d(dx, dy);
//    spriter::ScmlFunctions::setAnimation("sakuma", "damage");
//    spriter::ScmlFunctions::draw(GMVector3D(d.x+mass_size/2, d.y+mass_size/2, 40), 0.20, GMVector3D(0, p->getRadian(), 0), m_animationTime);
//}



