//
//  JASpeakWindowState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__JASpeakWindowState__
#define __Karakuri2_Mac__JASpeakWindowState__

#include "Karakuri.h"

namespace JASpeakWindow{
    
    class Window;
    class WindowState;
    class WindowStateChild{
    protected:
        Window* m_user;
    public:
        WindowStateChild(Window* user);
        virtual ~WindowStateChild();
        virtual WindowStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class WindowInter: public WindowStateChild{
        double m_time;
    public:
        WindowInter(Window* user);
        ~WindowInter();
        WindowStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class WindowVisible: public WindowStateChild{
        bool isAllCharacterStilled();
    public:
        WindowVisible(Window* user);
        ~WindowVisible();
        WindowStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class WindowOuter: public WindowStateChild{
        double m_time;
    public:
        WindowOuter(Window* user);
        ~WindowOuter();
        WindowStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class WindowState{
        WindowStateChild* m_child;
    public:
        WindowState(Window* user);
        ~WindowState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
    
}

#endif /* defined(__Karakuri2_Mac__JASpeakWindowState__) */
