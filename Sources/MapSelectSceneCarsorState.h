//
//  MapSelectSceneCarsorState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneCarsorState__
#define __Karakuri2_Mac__MapSelectSceneCarsorState__

#include "Karakuri.h"

namespace mapSelect{
    
    class SelectCarsor;
    class SelectCarsorState;
    class SelectObj;
    class SKMapSelectScene;
    class SelectCarsorStateChild{
    protected:
        SelectCarsor* m_user;
    public:
        SelectCarsorStateChild(SelectCarsor* user);
        virtual ~SelectCarsorStateChild();
        virtual SelectCarsorStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
        SelectCarsor* getCarsor();
        virtual SelectObj* getSelectObj() = 0;
    };
    
    // カーソル停滞
    class SelectCarsorBehind;
    namespace selectcarsorbehind{
        class SelectCarsorBehindState;
        class SelectCarsorBehindStateChild{
        protected:
            SelectCarsorBehind* m_user;
        public:
            SelectCarsorBehindStateChild(SelectCarsorBehind* user);
            virtual ~SelectCarsorBehindStateChild();
            virtual SelectCarsorBehindStateChild* update(GMInput* input, double deltaTime) = 0;
            virtual void draw(GMSpriteBatch* s) = 0;
        };
        class SelectCarsorBehindEnableInput: public SelectCarsorBehindStateChild{
        public:
            SelectCarsorBehindEnableInput(SelectCarsorBehind* user);
            ~SelectCarsorBehindEnableInput();
            SelectCarsorBehindStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class SelectCarsorBehindDisableInput: public SelectCarsorBehindStateChild{
        public:
            SelectCarsorBehindDisableInput(SelectCarsorBehind* user);
            ~SelectCarsorBehindDisableInput();
            SelectCarsorBehindStateChild* update(GMInput* input, double deltaTime) override;
            void draw(GMSpriteBatch* s) override;
        };
        
        class SelectCarsorBehindState{
            SelectCarsorBehindStateChild* m_child;
        public:
            SelectCarsorBehindState(SelectCarsorBehind* user);
            ~SelectCarsorBehindState();
            void update(GMInput* input, double deltaTime);
            void draw(GMSpriteBatch* s);
        };
    }
    class SelectCarsorBehind: public SelectCarsorStateChild{
        SelectObj* m_obj;
        selectcarsorbehind::SelectCarsorBehindState* m_state;
        SelectCarsorStateChild* m_nextState;
    public:
        SelectCarsorBehind(SelectObj* obj, SelectCarsor* user);
        ~SelectCarsorBehind();
        SelectCarsorStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        SelectObj* getObj();
        void changeState(SelectCarsorStateChild* next);
        SelectObj* getSelectObj() override;
    };
    
    // カーソル移動
    class SelectCarsorMove: public SelectCarsorStateChild{
        double m_time;
        SelectObj* m_prevObj;
        SelectObj* m_nextObj;
    public:
        SelectCarsorMove(SelectObj* prev, SelectObj* next, SelectCarsor* user);
        ~SelectCarsorMove();
        SelectCarsorStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        SelectObj* getSelectObj() override;
    };
    
    class SelectCarsorState{
        SelectCarsorStateChild* m_child;
    public:
        SelectCarsorState(SelectObj* firstObj, SelectCarsor* user);
        ~SelectCarsorState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        SelectObj* getCurrentObj();
    };
    
}

#endif /* defined(__Karakuri2_Mac__MapSelectSceneCarsorState__) */
