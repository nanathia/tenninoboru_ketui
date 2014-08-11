//
//  JASpeakWindow.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__JASpeakWindow__
#define __Karakuri2_Mac__JASpeakWindow__

#include "Karakuri.h"
#include <vector>
#include <deque>

// 時空亜空がプレイヤーに、言葉を発する為の窓。
namespace JASpeakWindow{
    class Character;
    class WindowState;

    class Window{
        std::deque<std::string> m_chargeStrs;
        GMRect2D m_WindowRect;
        std::vector<Character*>* m_characters;
        std::vector<Character*>* m_characters_2;
        GMColor m_color;
        WindowState* m_state;
    public:
        Window();
        ~Window();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        void setString(const std::string& str);
        std::vector<Character*>& getCharacters();
        GMColor getColor() const;
        void setColor(const GMColor& color);
        GMRect2D getRect() const;
        void setRect(const GMRect2D& rect);
        void addString(const std::string& str);
        std::deque<std::string>& getChargeStrs();
        void allCharacterGoUnderLava();
        std::vector<Character*>& getCharacters_2();
        void push();
    };
    
}

#endif /* defined(__Karakuri2_Mac__JASpeakWindow__) */