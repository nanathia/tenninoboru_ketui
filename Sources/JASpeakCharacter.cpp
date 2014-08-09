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
    m_color(GMColor::White)
    {
        m_Orbit = new Orbit;
        double syutugenAngle = GMRandom::NextDouble()*2.0-1.0;
        syutugenAngle *= M_PI;
        double sin = std::sin(syutugenAngle);
        double cos = std::cos(syutugenAngle);
        m_startPos = GMVector2D(cos*400.0, sin*400.0);
        m_startPos += m_endPos;
        m_state = new CharacterFly(this);
    }
    Character::~Character(){
        delete m_Orbit;
        m_Orbit = 0;
    }
    void Character::update(GMInput *input, double deltaTime){
        CharacterState* nextState = m_state->update(input, deltaTime);
        if(nextState != m_state){
            delete m_state;
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
    
    CharacterState::CharacterState(Character* character):
    m_character(character){
    }
    CharacterState::~CharacterState(){
        m_character = 0;
    }
    
    CharacterFly::CharacterFly(Character* character):
    CharacterState(character),
    m_time(0){
    }
    CharacterFly::~CharacterFly(){
    }
    CharacterState* CharacterFly::update(GMInput* input, double deltaTime){
        CharacterState* next = this;
        if(m_time >= 1){
            next = new CharacterHold(m_character);
        }
        m_time += deltaTime/2;
        return next;
    }
    void CharacterFly::draw(GMSpriteBatch* s){
        GMColor c = m_character->getColor();
        c.a = this->m_time;
        sizurus_fonts::SKFont::drawCharacter
        (m_character->getCharacter().c_str(),
         s,
         GMRect2D(m_character->getOrbit()->getOrbit(m_character->getStartPos(), m_character->getEndPos(), m_time), 50),
         c,
         m_character->getAngle(),
         GMVector2D(0.5, 0.5));
    }
    
    CharacterHold::CharacterHold(Character* character):
    CharacterState(character){
    }
    CharacterHold::~CharacterHold(){
    }
    CharacterState* CharacterHold::update(GMInput* input, double deltaTime){
        CharacterState* next = this;
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
    
/////////////////////////////////////////////////////////////////////////////////////////////////
    
    OrbitChild::~OrbitChild(){
    }
    
    double OrbitEaseIn::getOrbit(double startPos, double endPos, double amount){
        return GMMath::EaseIn(startPos, endPos, amount);
    }
    
    double OrbitEaseOut::getOrbit(double startPos, double endPos, double amount){
        return GMMath::EaseInOut(startPos, endPos, amount);
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
        return GMVector2D
        (m_Orbit_x->getOrbit(startPos.x, endPos.x, amount),
         m_Orbit_y->getOrbit(startPos.y, endPos.y, amount));
    }

}