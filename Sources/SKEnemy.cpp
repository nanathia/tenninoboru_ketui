
#include "SKEnemy.h"
#include "SaKumas_includes.h"
#include "EnemyStrategys.h"
#include "ScmlFunctions.h"
#include "SKEnemyState.h"
#include "SyokutyuuState.h"
#include "SKEnemyState.h"
#include "SKEnemyChild.h"
#include "SKEnemyMoveState.h"
#include <string>

void SKEnemy::objectInit(GMGraphics* g){
}

SKEnemy::SKEnemy():
SKMoveObject(),
m_flags(0),
m_isAction(0),
m_state(0),
m_isSameAct(0),
m_move(0)
{
    m_state = new enemyState::SyokutyuuLeady();
    m_move = new enemyMove::SKEnemyMoveState(this);
}

SKEnemy::~SKEnemy(){
    delete m_state;
    m_state = 0;
}

// フラグが立っているか
bool SKEnemy::isFlag(enemy_flags flag) const{
    return m_flags&flag ? true: false;
}

// フラグを立てる
void SKEnemy::upFlag(unsigned flag){
    m_flags |= flag;
}

// フラグを下げる
void SKEnemy::downFlag(unsigned flag){
    m_flags &= ~flag;
}

// フラグを全て下げる。
void SKEnemy::clearFlag(){
    m_flags = 0;
}

// プレイヤーに隣接しているか
bool SKEnemy::isMeetingPlayer(){
    int px, py, tx, ty;
    gPlayScene->getDungeonScene()->getPlayer()->getMass()->getPos(tx, ty);
    m_myLocations_mass->getPos(px, py);
    tx -= px;
    ty -= py;
    if(abs(tx) <= 1 && abs(ty) <= 1){
        if(this->isEnableAttackMass(gPlayScene->getDungeonScene()->getPlayer()->getMass())){
            return true;
        }
    }
    return false;
}

// プレイヤーが視界範囲にいるか
bool SKEnemy::isSeeingPlayer(){
    return m_myLocations_mass->getRoom() == gPlayScene->getDungeonScene()->getPlayer()->getMass()->getRoom() ? true: false;
}

void SKEnemy::setMove(){
    m_isAction = 1;
}

void SKEnemy::setAction(){
    m_isAction = 2;
}

bool SKEnemy::isMove(){
    return m_isAction == 1 ? true: false;
}

bool SKEnemy::isAction(){
    return m_isAction == 2 ? true: false;
}

void SKEnemy::resetMoveOrAction(){
    m_isAction = 0;
}

void SKEnemy::setEnt(const char* name){
    std::string s = name;
    if(s == "食虫植物"){
        this->characterName = "syokutyuu";
        spin = 0;
    }
    this->setName(name);
}



SKMass* SKEnemy::isNomalMoveMass(SKMass* mass){
    SKMass* nomalizeMass = this->getMassForAngle(mass);
    if(this->isEnableMoveMass(nomalizeMass)){
        // 普通に進行できるなら普通に進行
        return nomalizeMass;
    }else{
        double radian = this->getRadianForMass(mass);
        // どうやら普通には行けないようだな。
        SKMass* t = 0;
        // 左前方に躱せるか？
        if(isEnableMoveMass(t = this->getMassForRadian(radian+0.25))){
            return t;
        }
        // ならば右前方に躱せるか？
        else if(isEnableMoveMass(t = this->getMassForRadian(radian-0.25))){
            return t;
        }
        // 次。左に躱せるか？
        else if(isEnableMoveMass(t = this->getMassForRadian(radian+0.5))){
            return t;
        }
        // 右に躱せるか？
        else if(isEnableMoveMass(t = this->getMassForRadian(radian-0.5))){
            return t;
        }
        // 左後方に躱せるか？
        else if(isEnableMoveMass(t = this->getMassForRadian(radian+0.75))){
            return t;
        }
        // 右後方に躱せるか？
        else if(isEnableMoveMass(t = this->getMassForRadian(radian-0.75))){
            return t;
        }
        // 最後。後方へ下がれるか？
        else if(isEnableMoveMass(t = this->getMassForRadian(radian+1.0))){
            return t;
        }
        else{
            // 八方全て移動不可なようだ。
            // Do nothing
        }
    }
    return 0;
}

// プレイヤーと同じ部屋かどうか
bool SKEnemy::isSameRoomWithPlayer(){
    return this->getMass()->getRoom() == gPlayScene->getDungeonScene()->getPlayer()->getMass()->getRoom();
}

// 一足飛びの位置にプレイヤーが居るかどうか
SKMass* SKEnemy::isOneStepAttackToPlayer(){
    int x, y;
    getDistances(gPlayScene->getDungeonScene()->getPlayer(), x, y);
    if(abs(x)>2 || abs(y)>2) return 0;
    return gPlayScene->getDungeonScene()->getPlayer()->getMass();
}

// 障害物を考えずに、どの方向がプレイヤーに近いか
SKMass* SKEnemy::isNearestPlayerMass(){
    int x, y;
    getDistances(gPlayScene->getDungeonScene()->getPlayer(), x, y);
    localize(x, y);
    return getMassForOffset(x, y);
}


SKEnemy* SKEnemy::createRandomEnemy(){
    return new enemyChild::syokutyuu();
}

// 行動中フラグに関して
void SKEnemy::doAct(){
    m_isSameAct = true;
}

bool SKEnemy::isDoing(){
    return m_isSameAct;
}

void SKEnemy::doEnd(){
    m_isSameAct = false;
}

double SKEnemy::getRadianForMass(SKMass* mass){
    int tx, ty;
    this->getMass()->getOffset(mass, tx, ty);
    localize(tx, ty);
    return atan2(ty, tx)/M_PI;
}

enemyMove::SKEnemyMoveState* SKEnemy::getMove(){
    return m_move;
}

// 進行できる通路を取得
SKMass* SKEnemy::getPassasgeInterMass(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(!(i-1) && !(j-1)){
                continue;
            }
            SKMass* t = 0;
            if(!(t = this->getMassForOffset(j-1, i-1))->getRoom()){
                if(this->isEnableMoveMass(t)){
                    return t;
                }
            }
        }
    }
    return 0;
}

SKMass* SKEnemy::getPassageInterMassOnMoveObject(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(!(i-1) && !(j-1)){
                continue;
            }
            SKMass* t = 0;
            if(!(t = this->getMassForOffset(j-1, i-1))->getRoom()){
                if(t->getMovingObject() && !t->getBlock()){
                    return t;
                }
            }
        }
    }
    return 0;
}

