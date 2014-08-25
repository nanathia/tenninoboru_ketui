//
//  BaseAreaPlayerAngleState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/23.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaPlayerAngleState__
#define __Karakuri2_Mac__BaseAreaPlayerAngleState__

#include "Karakuri.h"

namespace baseArea{
    
    class Player;
    class PlayerAngleState;
    class PlayerAngleStateChild{
    protected:
        Player* m_user;
        double m_time;
    public:
        PlayerAngleStateChild(Player* user, double time = 0.0);
        virtual ~PlayerAngleStateChild();
        virtual PlayerAngleStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class PlayerLeftAngle: public PlayerAngleStateChild{
    public:
        PlayerLeftAngle(Player* user);
        ~PlayerLeftAngle();
        PlayerAngleStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class PlayerRightAngle: public PlayerAngleStateChild{
    public:
        PlayerRightAngle(Player* user);
        ~PlayerRightAngle();
        PlayerAngleStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class PlayerTopAngle: public PlayerAngleStateChild{
    public:
        PlayerTopAngle(Player* user);
        ~PlayerTopAngle();
        PlayerAngleStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class PlayerBottomAngle: public PlayerAngleStateChild{
    public:
        PlayerBottomAngle(Player* user);
        ~PlayerBottomAngle();
        PlayerAngleStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class PlayerAngleState{
        PlayerAngleStateChild* m_child;
    public:
        PlayerAngleState(Player* user);
        ~PlayerAngleState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaPlayerAngleState__) */
