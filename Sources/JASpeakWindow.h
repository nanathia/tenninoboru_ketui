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

// 時空亜空がプレイヤーに、言葉を発する為の窓。
namespace JASpeakWindow{
    class Character;
    
    class Window{
        GMRect2D m_WindowRect;
        std::vector<Character*> m_characters;
    public:
        Window();
        ~Window();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
}

#endif /* defined(__Karakuri2_Mac__JASpeakWindow__) */