//
//  JASpeakCharManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__JASpeakCharManager__
#define __Karakuri2_Mac__JASpeakCharManager__

#include "Karakuri.h"
#include <list>
#include <string>


namespace JASpeakWindow{
    class Character;

    class CharacterManager{
        std::list<Character*> m_Characters;
        CharacterManager* m_next;
        CharacterManager* m_prev;
    public:
        CharacterManager(const std::string& str);
        ~CharacterManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        void goUnderLava();
        bool isHolded();
        bool isVanished() const;
        void setNext(CharacterManager* next);
        void setPrev(CharacterManager* prev);
    };
    
}

#endif /* defined(__Karakuri2_Mac__JASpeakCharManager__) */
