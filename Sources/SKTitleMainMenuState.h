//
//  SKTitleMainMenuState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKTitleMainMenuState__
#define __Karakuri2_Mac__SKTitleMainMenuState__

#include "Karakuri.h"

namespace titleScene{
    class MainMenu;
    namespace mainmenu{
        class MenuState;
        class StateChild{
        protected:
            MainMenu* m_user;
        public:
            StateChild(MainMenu* user);
            virtual ~StateChild();
            virtual StateChild* update(GMInput* input, double deltaTime) = 0;
            virtual void draw(GMSpriteBatch* s) = 0;
        };
        
        class MainCommandSelect: public StateChild{
        public:
            MainCommandSelect(MainMenu* user);
            ~MainCommandSelect();
            StateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class Hajimekara: public StateChild{
        public:
            Hajimekara(MainMenu* user);
            ~Hajimekara();
            StateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class Tudukikara: public StateChild{
        public:
            Tudukikara(MainMenu* user);
            ~Tudukikara();
            StateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class Settei: public StateChild{
        public:
            Settei(MainMenu* user);
            ~Settei();
            StateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class Omake: public StateChild{
        public:
            Omake(MainMenu* user);
            ~Omake();
            StateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class Chancel: public StateChild{
        public:
            Chancel(MainMenu* user);
            ~Chancel();
            StateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class MenuState{
            StateChild* m_child;
        public:
            MenuState(MainMenu* user);
            ~MenuState();
            void update(GMInput* input, double deltaTime);
            void draw(GMSpriteBatch* s);
        };
    }
}

#endif /* defined(__Karakuri2_Mac__SKTitleMainMenuState__) */
