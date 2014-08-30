//
//  SKSpeakWindow.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKSpeakWindow__
#define __Karakuri2_Mac__SKSpeakWindow__

#include "Karakuri.h"
#include "SKSpeakCharManager.h"
#include <vector>
#include <deque>

// 時空亜空がプレイヤーに、言葉を発する為の窓。
namespace SKSpeakWindow{
    class Character;
    class WindowState;

    // 文字列更新時に、引数として返す"キー"を表すクラス。
    class StrQuotation{
        std::string m_string;
        int m_quota;
    public:
        StrQuotation(const std::string& str, int quota);
        StrQuotation(const std::string&);
        int getQuota() const;
        const std::string& getStr() const;
    };
    

    class Window{
        std::deque<StrQuotation> m_chargeStrs;
        GMRect2D m_WindowRect;
        std::deque<CharacterManager*> m_Strs;
        GMColor m_color;
        WindowState* m_state;
        int m_returnKey;
        int m_nextReturnKey;
        bool m_isLockInput;
    public:
        Window();
        ~Window();
        int update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        void setString(const std::string& str);
        CharacterManager* getCharacters();
        GMColor getColor() const;
        void setColor(const GMColor& color);
        GMRect2D getRect() const;
        void setRect(const GMRect2D& rect);
        void addString(const std::string& str);
        std::deque<StrQuotation>& getChargeStrs();
        void allCharacterGoUnderLava();
        void push();
        bool isAllCharacterStilled();
        void addString(const std::string& str, int key);
        void setNextReturnKey(int key);
        void setReturnKey();
        int getKey();
        void setKey(int key);
        void DisableInput();
        void EnableInput();
        bool isAllEnd() const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__SKSpeakWindow__) */