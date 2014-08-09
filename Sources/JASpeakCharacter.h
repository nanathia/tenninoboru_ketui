//
//  JASpeakCharacter.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__JASpeakCharacter__
#define __Karakuri2_Mac__JASpeakCharacter__

#include "Karakuri.h"
#include <string>

namespace JASpeakWindow{
    class Character;

    // 時空亜空の言葉を集約する際の不確定な軌道を表す。
    class OrbitChild{
    public:
        virtual ~OrbitChild();
        virtual double getOrbit(double startPos, double endPos, double amount) = 0;
    };
    
    class OrbitEaseIn: public OrbitChild{
    public:
        double getOrbit(double startPos, double endPos, double amount) override;
    };
    
    class OrbitEaseOut: public OrbitChild{
    public:
        double getOrbit(double startPos, double endPos, double amount) override;
    };
    
    class OrbitLerp: public OrbitChild{
    public:
        double getOrbit(double startPos, double endPos, double amount) override;
    };
    
    class Orbit{
        OrbitChild* m_Orbit_x;
        OrbitChild* m_Orbit_y;
    public:
        Orbit();
        ~Orbit();
        GMVector2D getOrbit(const GMVector2D& startPos, const GMVector2D& endPos, double amount);
    };
    
    class CharacterState{
    protected:
        Character* m_character;
    public:
        CharacterState(Character* character);
        virtual ~CharacterState();
    public:
        virtual CharacterState* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class CharacterFly: public CharacterState{
        double m_time;
    public:
        CharacterFly(Character* character);
        ~CharacterFly();
    public:
        CharacterState* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class CharacterHold: public CharacterState{
    public:
        CharacterHold(Character* character);
        ~CharacterHold();
    public:
        CharacterState* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // 時空亜空が発する言葉の一文字。グラフィカルに表現するため、クラスで表す。
    class Character{
        // 表す１文字
        std::string m_myCharacter;
        // 軌道を移譲
        Orbit* m_Orbit;
        // 現在角度<Radian>
        double m_angle;
        // 始点位置
        GMVector2D m_startPos;
        // 終点位置
        GMVector2D m_endPos;
        // ステイト
        CharacterState* m_state;
        // 色
        GMColor m_color;
    public:
        Character(const char* character, const GMVector2D& characterPos);
        ~Character();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        GMVector2D getStartPos() const;
        GMVector2D getEndPos() const;
        double getAngle() const;
        void addAngle(double addAngle);
        void setAngle(double angle);
        Orbit* getOrbit();
        std::string getCharacter() const;
        GMColor getColor() const;
        void setColor(GMColor color);
    };
    
}

#endif /* defined(__Karakuri2_Mac__JASpeakCharacter__) */
