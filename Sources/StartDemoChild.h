//
//  StartDemoChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__StartDemoChild__
#define __Karakuri2_Mac__StartDemoChild__

#include "Karakuri.h"
#include "SKSelectWindow.h"
#include "JASpeakWindow.h"

class SKStartDemo;


namespace startdemo{
    
    namespace startdemomain{
        class StartDemoState;
    }
    
    class StartDemoState;
    class StartDemoChild{
    protected:
        SKStartDemo* m_user;
    public:
        StartDemoChild(SKStartDemo* user);
        virtual ~StartDemoChild();
        virtual StartDemoChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class StartDemoInter: public StartDemoChild{
        double m_time;
    public:
        StartDemoInter(SKStartDemo* user);
        ~StartDemoInter();
        StartDemoChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class StartDemoOuter: public StartDemoChild{
        double m_time;
    public:
        StartDemoOuter(SKStartDemo* user);
        ~StartDemoOuter();
        StartDemoChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class StartDemoMain: public StartDemoChild{
        selectWindow::Window* m_sel_win;
        JASpeakWindow::Window* m_spk_win;
        startdemomain::StartDemoState* m_state;
    public:
        enum sceneName{
            nextScene,
        };
        StartDemoMain(SKStartDemo* user);
        ~StartDemoMain();
        StartDemoChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    public:
        JASpeakWindow::Window* getSpkWin();
    };
    
    class StartDemoState{
        StartDemoChild* m_child;
    public:
        StartDemoState(SKStartDemo* user);
        ~StartDemoState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
    
}
#endif /* defined(__Karakuri2_Mac__StartDemoChild__) */
