//
//  MapSelectSceneState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/30.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneState__
#define __Karakuri2_Mac__MapSelectSceneState__

#include "Karakuri.h"

namespace mapSelect{
    
    class MapSelectScene;
    class SceneState;
    class SceneStateChild{
    protected:
        MapSelectScene* m_user;
    public:
        SceneStateChild(MapSelectScene* user);
        virtual ~SceneStateChild();
        virtual SceneStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class CarsorMove: public SceneStateChild{
    public:
        CarsorMove(MapSelectScene* user);
        ~CarsorMove();
        SceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class CarsorBehind: public SceneStateChild{
    public:
        CarsorBehind(MapSelectScene* user);
        ~CarsorBehind();
        SceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class MapInterYesOrNo: public SceneStateChild{
    public:
        MapInterYesOrNo(MapSelectScene* user);
        ~MapInterYesOrNo();
        SceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class SceneState{
        SceneStateChild* m_child;
    public:
        SceneState(MapSelectScene* user);
        ~SceneState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
    
}


#endif /* defined(__Karakuri2_Mac__MapSelectSceneState__) */
