//
//  SKMapSelectSceneState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/30.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMapSelectSceneState__
#define __Karakuri2_Mac__SKMapSelectSceneState__

#include "Karakuri.h"

namespace selectWindow{
    class Window;
}

namespace mapSelect{
    
    class SKMapSelectScene;
    class SceneState;
    class SceneStateChild{
    protected:
        SKMapSelectScene* m_user;
    public:
        SceneStateChild(SKMapSelectScene* user);
        virtual ~SceneStateChild();
        virtual SceneStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
        virtual void changeBaseAreaReady() = 0;
        virtual void changeSelect() = 0;
        virtual bool isChangeAreaReady() const;
    };
    
    class CarsorMove: public SceneStateChild{
        bool m_is2BaseAreaReady;
    public:
        CarsorMove(SKMapSelectScene* user);
        ~CarsorMove();
        SceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        void changeBaseAreaReady() override;
        void changeSelect() override;
    };
    
    class MapInterYesOrNo: public SceneStateChild{
        enum selectName{
            select_backAreaSelect,
            select_ChangeArea,
            select_BackCarsorSelect,
        };
        double m_time;
        bool m_is2Select;
        selectWindow::Window* m_questionWin;
    public:
        MapInterYesOrNo(SKMapSelectScene* user);
        ~MapInterYesOrNo();
        SceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        void changeBaseAreaReady() override;
        void changeSelect() override;
        bool isChangeAreaReady() const override;
    };
    
    class SceneState{
        SceneStateChild* m_child;
    public:
        SceneState(SKMapSelectScene* user);
        ~SceneState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void changeSelect();
        void changeBaseAreaReady();
        bool isChangeAreaReady() const;
    };
    
    
}


#endif /* defined(__Karakuri2_Mac__SKMapSelectSceneState__) */
