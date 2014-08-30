//
//  BaseAreaPlayerMainState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaPlayerMainState__
#define __Karakuri2_Mac__BaseAreaPlayerMainState__

#include "Karakuri.h"

#include "Karakuri.h"

namespace baseArea{
    
    class Player;
    class PlayerMainState;
    class Murabito;
    class PlayerMainStateChild{
    protected:
        Player* m_user;
    public:
        PlayerMainStateChild(Player* user);
        virtual ~PlayerMainStateChild();
        virtual PlayerMainStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
        virtual bool isSpeak() const;
    };
    
    class PlayerStateFreeMove: public PlayerMainStateChild{
    public:
        PlayerStateFreeMove(Player* user);
        ~PlayerStateFreeMove();
        PlayerMainStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class PlayerStateSpeakHuman: public PlayerMainStateChild{
        Murabito* m_speakPerson;
    public:
        PlayerStateSpeakHuman(Murabito* mura, Player* user);
        ~PlayerStateSpeakHuman();
        PlayerMainStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isSpeak() const override;
    };
    
    class PlayerStateSirabaruAny: public PlayerMainStateChild{
    public:
        PlayerStateSirabaruAny(Player* user);
        ~PlayerStateSirabaruAny();
        PlayerMainStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class PlayerMainState{
        PlayerMainStateChild* m_child;
        Player* m_user;
    public:
        PlayerMainState(Player* user);
        ~PlayerMainState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void speak(Murabito* mura);
        bool isSpeak() const;
    };
    
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaPlayerMainState__) */
