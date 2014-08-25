//
//  BaseAreaCharacterManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/21.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaCharacterManager__
#define __Karakuri2_Mac__BaseAreaCharacterManager__

#include "Karakuri.h"

namespace baseArea{
    class Player;
    class MurabitoManager;
    class SKBaseAreaScene;

    class CharacterManager{
        Player* m_Player;
        MurabitoManager* m_Murabitos;
        SKBaseAreaScene* m_parent;
    public:
        CharacterManager(SKBaseAreaScene* parent);
        ~CharacterManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        Player* getPlayer();
        MurabitoManager* getMurabitoMan();
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaCharacterManager__) */
