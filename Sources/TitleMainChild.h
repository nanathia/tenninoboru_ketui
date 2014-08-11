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
    namespace mainmenu{
        class MenuState;
    }

    class MainChild{
    protected:
        TitleMain* m_user;
        double m_animationTime;
    public:
        MainChild(TitleMain* user);
        virtual ~MainChild();
        virtual MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) = 0;
        virtual void draw(TitleMain* parent, GMSpriteBatch* s) = 0;
    };
    
    class MainInter: public MainChild{
    public:
        MainInter(TitleMain* user);
        ~MainInter();
        MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
    class MainMenu: public MainChild{
        mainmenu::MenuState* m_state;
    public:
        MainMenu(TitleMain* user);
        ~MainMenu();
        MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    public:
        TitleMain* getUser();
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
        MainOuter(TitleMain* user, OuterBranch branch);
        ~MainOuter();
        MainChild* update(TitleMain* parent, GMInput* input, double deltaTime) override;
        void draw(TitleMain* parent, GMSpriteBatch* s) override;
    };
    
}

#endif /* defined(__Karakuri2_Mac__MainChild__) */
