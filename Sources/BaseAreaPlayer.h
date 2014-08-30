//
//  BaseAreaPlayer.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/23.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaPlayer__
#define __Karakuri2_Mac__BaseAreaPlayer__

#include "Karakuri.h"

namespace baseArea{
    class PlayerAngleState;
    class PlayerMainState;
    class SKBaseAreaScene;
    class Player;
    class Murabito;
    
    class PlayerDraw{
        PlayerDraw();
        ~PlayerDraw();
        PlayerDraw(const PlayerDraw&);
    public:
        enum chipName{
            chipName_right2,
            chipName_up2,
            chipName_down2,
            chipName_right1,
            chipName_up1,
            chipName_down1,
            chipName_left1 = 99,
            chipName_left2,
        };
        static void draw(GMSpriteBatch* s, Player* player, int chipName);
    };
    
    class Player{
        GMRect2D m_Matrixrect;
        SKBaseAreaScene* m_parent;
        PlayerAngleState* m_state;
        PlayerMainState* m_secondState;
    public:
        Player(SKBaseAreaScene* parent);
        ~Player();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        SKBaseAreaScene* getBaseAreaScene();
        GMVector2D getPos() const;
        void setPos(const GMVector2D& pos);
        void setRect(const GMRect2D& rect);
        void speak(Murabito* mura);
        bool isSpeak() const;
        const GMRect2D& Rect() const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaPlayer__) */
