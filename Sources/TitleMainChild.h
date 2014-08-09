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

namespace selectWindow{
    class Window;
    class Element;
    class Carsor;
}
namespace JASpeakWindow{
    class Window;
}

namespace titleScene{
    class TitleMain;

    class MainChild{
    protected:
        double m_animationTime;
    public:
        MainChild();
        virtual ~MainChild();
        virtual MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) = 0;
        virtual void draw(TitleMain* parent, GMSpriteBatch* s) = 0;
    };
    
    class MainInter: public MainChild{
    public:
        MainInter();
        ~MainInter();
        MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
    class MainMenu: public MainChild{
        selectWindow::Window* m_slectWindow;
        JASpeakWindow::Window* m_speakWindow;
    public:
        MainMenu();
        ~MainMenu();
        MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
    class MainOuter: public MainChild{
    public:
        enum OuterBranch{
            branch_newGame,
            branch_continue2Data_1,
            branch_continue2Data_2,
            branch_continue2Data_3,
        };
    private:
        OuterBranch m_branch;
    public:
        MainOuter(OuterBranch branch);
        ~MainOuter();
        MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
}

#endif /* defined(__Karakuri2_Mac__MainChild__) */
