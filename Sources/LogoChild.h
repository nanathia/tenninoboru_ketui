//
//  LogoChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__LogoChild__
#define __Karakuri2_Mac__LogoChild__

#include "Karakuri.h"

namespace titleScene{
    class TitleLogo;

    class LogoChild{
    public:
        LogoChild();
        virtual ~LogoChild();
        virtual LogoChild* update(TitleLogo* parent, GMInput* input, double deltaTime) = 0;
        virtual void draw(TitleLogo* parent, GMSpriteBatch* s) = 0;
    };
    
    class LogoInter: public LogoChild{
    public:
        LogoInter();
        ~LogoInter();
        LogoChild* update(TitleLogo* parent, GMInput* input, double deltaTime) override;
        void draw(TitleLogo* parent, GMSpriteBatch* s) override;
    };
    
    class LogoInterval: public LogoChild{
        double m_interval;
    public:
        LogoInterval();
        ~LogoInterval();
        LogoChild* update(TitleLogo* parent, GMInput* input, double deltaTime) override;
        void draw(TitleLogo* parent, GMSpriteBatch* s) override;
    };
    
    class LogoOuter: public LogoChild{
    public:
        LogoOuter();
        ~LogoOuter();
        LogoChild* update(TitleLogo* parent, GMInput* input, double deltaTime) override;
        void draw(TitleLogo* parent, GMSpriteBatch* s) override;
    };
    
}

    
#endif /* defined(__Karakuri2_Mac__LogoChild__) */
