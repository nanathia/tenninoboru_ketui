//
//  TitleMainChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/07.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__TitleMainChild__
#define __Karakuri2_Mac__TitleMainChild__

#include "Karakuri.h"

namespace titleScene{
    class TitleMain;

    class TitleMainChild{
        double m_animationTime;
    public:
        TitleMainChild();
        virtual ~TitleMainChild();
        virtual TitleMainChild* update(TitleMain* parent, GMInput* input, double deltaTime) = 0;
        virtual void draw(TitleMain* parent, GMSpriteBatch* s) = 0;
    };
    
    class MainInter: public TitleMainChild{
    public:
        MainInter();
        ~MainInter();
        TitleMainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
    class MainMenu: public TitleMainChild{
    public:
        MainMenu();
        ~MainMenu();
        TitleMainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
    class MainOuter: public TitleMainChild{
    public:
        MainOuter();
        ~MainOuter();
        TitleMainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
}

#endif /* defined(__Karakuri2_Mac__TitleMainChild__) */
