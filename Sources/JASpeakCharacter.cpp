//
//  JASpeakCharacter.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "JASpeakCharacter.h"
#include "randam_dungeon.h"
#include "GMRandom.h"
#include "SKFont.h"
#include <cmath>

namespace JASpeakWindow{

    Character::Character(const char* character, const GMVector2D& endPos):
    m_myCharacter(character),
    m_Orbit(0),
    m_angle(0),
    m_startPos(0),
    m_endPos(endPos),
    m_state(0),
    m_color(GMColor::White),
    m_nextCharacter(0),
    m_prevCharacter(0),
    m_nextLunchInterval(0),
    m_completeTime(0)
    {
        this->setInter();
        m_state = new CharacterLeady(this);
    }
    Character::~Character(){
        delete m_Orbit;
        m_Orbit = 0;
        delete m_state;
        m_state = 0;
    }
    void Character::update(GMInput *input, double deltaTime){
        CharacterState* nextState = m_state->update(input, deltaTime);
        if(nextState != m_state){
            delete m_state;
            m_state = 0;
            m_state = nextState;
        }
    }
    void Character::draw(GMSpriteBatch *s){
        m_state->draw(s);
    }
    GMVector2D Character::getStartPos() const{
        return m_startPos;
    }
    GMVector2D Character::getEndPos() const{
        return m_endPos;
    }
    double Character::getAngle() const{
        return m_angle;
    }
    void Character::addAngle(double addAngle){
        m_angle += addAngle;
    }
    void Character::setAngle(double angle){
        m_angle = angle;
    }
    Orbit* Character::getOrbit(){
        return m_Orbit;
    }
    std::string Character::getCharacter() const{
        return m_myCharacter;
    }
    GMColor Character::getColor() const{
        return m_color;
    }
    void Character::setColor(GMColor color){
        m_color = color;
    }
    Character* Character::getNext(){
        return m_nextCharacter;
    }
    Character* Character::getPrev(){
        return m_prevCharacter;
    }
    void Character::setNext(Character* next){
        m_nextCharacter = next;
    }
    void Character::setPrev(Character* prev){
        m_prevCharacter = prev;
    }
    bool Character::isEnableNextLunchChar(){
        return m_state->isEnableLunchNextChar();
    }
    double Character::getNextLunchInterval(){
        return m_nextLunchInterval;
    }
    void Character::setNextLunchInterval(double interval){
        m_nextLunchInterval = interval;
    }
    double Character::getCompleteTime(){
        return m_completeTime;
    }
    void Character::setCompleteTime(double time){
        m_completeTime = time;
    }
    bool Character::isStill() const{
        return m_state->isStill();
    }
    void Character::setInter(){
        m_Orbit = new Orbit;
        double syutugenAngle = GMRandom::NextDouble()*2.0-1.0;
        syutugenAngle *= M_PI;
        double sin = std::sin(syutugenAngle);
        double cos = std::cos(syutugenAngle);
        double distance = GMRandom::NextDouble()*500;
        m_startPos = GMVector2D(cos*distance, sin*distance);
        m_startPos += m_endPos;
        m_startPos.x -= 500;
    }
    void Character::setOuter(){
        delete m_Orbit;
        m_Orbit = new Orbit;
        double syutugenAngle = GMRandom::NextDouble()*2.0-1.0;
        syutugenAngle *= M_PI;
        double sin = std::sin(syutugenAngle);
        double cos = std::cos(syutugenAngle);
        double distance = GMRandom::NextDouble()*500;
        m_startPos = GMVector2D(cos*distance, sin*distance);
        m_startPos += m_endPos;
        m_startPos.x += 500;
        swap(m_startPos, m_endPos);
    }
    void Character::ill_Be_Back(){
        m_state->ill_Be_Back();
    }
    bool Character::isVanished() const{
        return m_state->isVanish();
    }
    
    CharacterState::CharacterState(Character* character):
    m_character(character){
    }
    CharacterState::~CharacterState(){
        m_character = 0;
    }
    bool CharacterState::isVanish(){
        return false;
    }
    void CharacterState::ill_Be_Back(){
        // Do nothig
    }
    
    CharacterFly::CharacterFly(Character* character):
    CharacterState(character),
    m_time(0),
    m_deltaTime(0){
    }
    CharacterFly::~CharacterFly(){
    }
    CharacterState* CharacterFly::update(GMInput* input, double deltaTime){
        CharacterState* next = this;
        if(input->isKeyDown(GMKeyMaskX)){
            m_time += deltaTime/m_character->getCompleteTime()*5;
        }else {
            m_time += deltaTime/m_character->getCompleteTime();
        }
        if(m_time >= 1){
            next = new CharacterHold(m_character);
        }
        return next;
    }
    void CharacterFly::draw(GMSpriteBatch* s){
        GMColor c = m_character->getColor();
        c.a = this->m_time;
        sizurus_fonts::SKFont::drawCharacter
        (m_character->getCharacter().c_str(),
         s,
         GMRect2D(m_character->getOrbit()->getOrbit(m_character->getStartPos(), m_character->getEndPos(), m_time), GMMath::Lerp(0, 50, m_time)),
         c,
         m_character->getAngle(),
         GMVector2D(0.5, 0.5));
    }
    bool CharacterFly::isEnableLunchNextChar(){
        return m_time >= m_character->getNextLunchInterval() ? true: false;
    }
    bool CharacterFly::isStill() const{
        return false;
    }
    
    CharacterHold::CharacterHold(Character* character):
    CharacterState(character),
    m_isGoUnderLava(false){
    }
    CharacterHold::~CharacterHold(){
    }
    CharacterState* CharacterHold::update(GMInput* input, double deltaTime){
        CharacterState* next = this;
        if(m_isGoUnderLava){
            next = new CharacterRetireLeady(m_character);
        }
        return next;
    }
    void CharacterHold::draw(GMSpriteBatch* s){
        sizurus_fonts::SKFont::drawCharacter
        (m_character->getCharacter().c_str(),
         s,
         GMRect2D(m_character->getEndPos(), 50),
         m_character->getColor(),
         0,
         GMVector2D(0.5, 0.5));
    }
    bool CharacterHold::isEnableLunchNextChar(){
        return true;
    }
    bool CharacterHold::isStill() const{
        return true;
    }
    void CharacterHold::ill_Be_Back(){
        m_isGoUnderLava = true;
    }

    CharacterLeady::CharacterLeady(Character* character):
    CharacterState(character){
    }
    CharacterLeady::~CharacterLeady(){
    }
    CharacterState* CharacterLeady::update(GMInput* input, double deltaTime){
        CharacterState* next = this;
        if(m_character->getPrev()){
            if(m_character->getPrev()->isEnableNextLunchChar()){
                next = new CharacterFly(m_character);
            }
        }else{
            next = new CharacterFly(m_character);
            next->update(input, deltaTime);
        }
        return next;
    }
    void CharacterLeady::draw(GMSpriteBatch* s){
        // Do nothing
    }
    bool CharacterLeady::isEnableLunchNextChar(){
        return false;
    }
    bool CharacterLeady::isStill() const{
        return true;
    }
    
    CharacterRetire::CharacterRetire(Character* character):
    CharacterState(character),
    m_time(0),
    m_deltaTime(0){
        m_character->setOuter();
    }
    CharacterRetire::~CharacterRetire(){
    }
    CharacterState* CharacterRetire::update(GMInput* input, double deltaTime){
        CharacterState* next = this;
        if(input->isKeyDown(GMKeyMaskX)){
            m_time += deltaTime/m_character->getCompleteTime()*5;
        }else {
           m_time += deltaTime/m_character->getCompleteTime();
        }
        if(m_time >= 1){
            next = new CharacterVanished(m_character);
        }
        return next;
    }
    void CharacterRetire::draw(GMSpriteBatch* s){
        GMColor c = m_character->getColor();
        c.a = 1-this->m_time;
        sizurus_fonts::SKFont::drawCharacter
        (m_character->getCharacter().c_str(),
         s,
         GMRect2D(m_character->getOrbit()->getOrbit(m_character->getStartPos(), m_character->getEndPos(), m_time), GMMath::Lerp(50, 0, m_time)),
         c,
         m_character->getAngle(),
         GMVector2D(0.5, 0.5));
    }
    bool CharacterRetire::isEnableLunchNextChar(){
        return m_time >= m_character->getNextLunchInterval() ? true: false;
    }
    bool CharacterRetire::isStill() const{
        return true;
    }
    
    CharacterVanished::CharacterVanished(Character* character):
    CharacterState(character){
    }
    CharacterVanished::~CharacterVanished(){
    }
    CharacterState* CharacterVanished::update(GMInput *input, double deltaTime){
        return this;
    }
    void CharacterVanished::draw(GMSpriteBatch *s){
        // Do nothing
    }
    bool CharacterVanished::isEnableLunchNextChar(){
        return true;
    }
    bool CharacterVanished::isStill() const{
        return true;
    }
    bool CharacterVanished::isVanish(){
        return true;
    }
    
    CharacterRetireLeady::CharacterRetireLeady(Character* character):
    CharacterState(character){
    }
    CharacterRetireLeady::~CharacterRetireLeady(){
    }
    CharacterState* CharacterRetireLeady::update(GMInput *input, double deltaTime){
        CharacterState* next = this;
        if(m_character->getPrev()){
            if(m_character->getPrev()->isEnableNextLunchChar()){
                next = new CharacterRetire(m_character);
            }
        }else{
            next = new CharacterRetire(m_character);
        }
        return next;
    }
    void CharacterRetireLeady::draw(GMSpriteBatch *s){
        sizurus_fonts::SKFont::drawCharacter
        (m_character->getCharacter().c_str(),
         s,
         GMRect2D(m_character->getEndPos(), 50),
         m_character->getColor(),
         0,
         GMVector2D(0.5, 0.5));
    }
    bool CharacterRetireLeady::isEnableLunchNextChar(){
        return false;
    }
    bool CharacterRetireLeady::isStill() const{
        return true;
    }
    
/////////////////////////////////////////////////////////////////////////////////////////////////
    
    OrbitChild::~OrbitChild(){
    }
    
    double OrbitEaseIn::getOrbit(double startPos, double endPos, double amount){
        return GMMath::EaseIn(startPos, endPos, amount);
    }
    
    double OrbitEaseOut::getOrbit(double startPos, double endPos, double amount){
        return GMMath::EaseOut(startPos, endPos, amount);
    }
    
    double OrbitLerp::getOrbit(double startPos, double endPos, double amount){
        return GMMath::Lerp(startPos, endPos, amount);
    }
    
    Orbit::Orbit():
    m_Orbit_x(0),
    m_Orbit_y(0){
        int xRand = randam_dungeon::rand(0, 2);
        int yRand = randam_dungeon::rand(0, 2);
        if(xRand == 0){
            m_Orbit_x = new OrbitEaseIn;
        }else if(xRand == 1){
            m_Orbit_x = new OrbitEaseOut;
        }else if(xRand == 2){
            m_Orbit_x = new OrbitLerp;
        }
        if(yRand == 0){
            m_Orbit_y = new OrbitEaseIn;
        }else if(yRand == 1){
            m_Orbit_y = new OrbitEaseOut;
        }else if(yRand == 2){
            m_Orbit_y = new OrbitLerp;
        }
    }
    Orbit::~Orbit(){
        delete m_Orbit_y;
        m_Orbit_y = 0;
        delete m_Orbit_x;
        m_Orbit_x = 0;
    }
    GMVector2D Orbit::getOrbit(const GMVector2D& startPos, const GMVector2D& endPos, double amount){
        amount = GMMath::EaseOut(0, 1, amount);
        return GMVector2D
        (m_Orbit_x->getOrbit(startPos.x, endPos.x, amount),
         m_Orbit_y->getOrbit(startPos.y, endPos.y, amount));
    }

}