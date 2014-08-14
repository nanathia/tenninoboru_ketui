//
//  StartDemoMainState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/14.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__StartDemoMainState__
#define __Karakuri2_Mac__StartDemoMainState__

#include "Karakuri.h"

namespace startdemo{
    class StartDemoMain;
namespace startdemomain{
    class State;
    class StateChild{
    protected:
        StartDemoMain* m_user;
        bool m_isNext;
    public:
        StateChild(StartDemoMain* user);
        virtual ~StateChild();
        virtual StateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    public:
        virtual void goNext();
        virtual bool isVisible();
    };
    
    class TextOnly: public StateChild{
    public:
        TextOnly(StartDemoMain* user);
        ~TextOnly();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    public:
    };
    
    class JikuakuuInter: public StateChild{
        double m_time;
    public:
        JikuakuuInter(StartDemoMain* user);
        ~JikuakuuInter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class JikuakuuImage: public StateChild{
    public:
        JikuakuuImage(StartDemoMain* user);
        ~JikuakuuImage();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class JikuuakuuOuter: public StateChild{
        double m_time;
    public:
        JikuuakuuOuter(StartDemoMain* user);
        ~JikuuakuuOuter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class TextOnly2: public StateChild{
    public:
        TextOnly2(StartDemoMain* user);
        ~TextOnly2();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    public:
    };
    
    class TetoraInter: public StateChild{
        double m_time;
    public:
        TetoraInter(StartDemoMain* user);
        ~TetoraInter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class TetoraVisible: public StateChild{
    public:
        TetoraVisible(StartDemoMain* user);
        ~TetoraVisible();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class TetoraOuter: public StateChild{
        double m_time;
    public:
        TetoraOuter(StartDemoMain* user);
        ~TetoraOuter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class TextOnly3: public StateChild{
    public:
        TextOnly3(StartDemoMain* user);
        ~TextOnly3();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class SakumaInter: public StateChild{
        double m_time;
    public:
        SakumaInter(StartDemoMain* user);
        ~SakumaInter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class SakumaVisible: public StateChild{
    public:
        SakumaVisible(StartDemoMain* user);
        ~SakumaVisible();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class SakumaInter2: public StateChild{
        double m_time;
    public:
        SakumaInter2(StartDemoMain* user);
        ~SakumaInter2();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class SakumaSakumaVisible2: public StateChild{
        double m_time;
    public:
        SakumaSakumaVisible2(StartDemoMain* user);
        ~SakumaSakumaVisible2();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class SakumaOuter: public StateChild{
        double m_time;
    public:
        SakumaOuter(StartDemoMain* user);
        ~SakumaOuter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class TextOnly4: public StateChild{
    public:
        TextOnly4(StartDemoMain* user);
        ~TextOnly4();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    public:
    };
    
    class AllOuter: public StateChild{
        double m_time;
    public:
        AllOuter(StartDemoMain* user);
        ~AllOuter();
        StateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        bool isVisible();
    };
    
    class StartDemoState{
        StateChild* m_child;
    public:
        StartDemoState(StartDemoMain* user);
        ~StartDemoState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        void goNext();
    };
    
    
}
}

#endif /* defined(__Karakuri2_Mac__StartDemoMainState__) */
