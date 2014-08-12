//
//  TitleHajimekara.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__TitleHajimekara__
#define __Karakuri2_Mac__TitleHajimekara__

#include "Karakuri.h"

namespace titleScene{
    namespace mainmenu{
        
        class Hajimekara;
        class HajimekaraState;
        class HajimekaraStateChild{
        protected:
            Hajimekara* m_user;
        public:
            HajimekaraStateChild(Hajimekara* user);
            virtual ~HajimekaraStateChild();
            virtual HajimekaraStateChild* update(GMInput* input, double deltaTime) = 0;
            virtual void draw(GMSpriteBatch* s) = 0;
        };
        
        class HajimekaraLeady: public HajimekaraStateChild{
        public:
            HajimekaraLeady(Hajimekara* user);
            ~HajimekaraLeady();
            HajimekaraStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class HajimekaraYes: public HajimekaraStateChild{
        public:
            HajimekaraYes(Hajimekara* user);
            ~HajimekaraYes();
            HajimekaraStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class HajimekaraNone: public HajimekaraStateChild{
        public:
            HajimekaraNone(Hajimekara* user);
            ~HajimekaraNone();
            HajimekaraStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class HajimekaraDare: public HajimekaraStateChild{
        public:
            HajimekaraDare(Hajimekara* user);
            ~HajimekaraDare();
            HajimekaraStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class HajimekaraOuter: public HajimekaraStateChild{
        public:
            HajimekaraOuter(Hajimekara* user);
            ~HajimekaraOuter();
            HajimekaraStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class HajimekaraState{
            HajimekaraStateChild* m_child;
        public:
            HajimekaraState(Hajimekara* user);
            ~HajimekaraState();
            void update(GMInput* input, double deltaTime);
            void draw(GMSpriteBatch* s);
        };
        
    }
}
#endif /* defined(__Karakuri2_Mac__TitleHajimekara__) */
