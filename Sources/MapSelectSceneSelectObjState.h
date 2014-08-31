//
//  MapSelectSceneSelectObjState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/09/01.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneSelectObjState__
#define __Karakuri2_Mac__MapSelectSceneSelectObjState__

#include "Karakuri.h"

namespace mapSelect{
    
    class SelectObj;
    class SelectObjState;
    class SelectObjStateChild{
    protected:
        SelectObj* m_user;
    public:
        SelectObjStateChild(SelectObj* user);
        virtual ~SelectObjStateChild();
        virtual SelectObjStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class SelectObjSelecting: public SelectObjStateChild{
        double m_time;
        double m_time2;
    public:
        SelectObjSelecting(SelectObj* user);
        ~SelectObjSelecting();
        SelectObjStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class SelectObjNoneSelecting: public SelectObjStateChild{
    public:
        SelectObjNoneSelecting(SelectObj* user);
        ~SelectObjNoneSelecting();
        SelectObjStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class SelectObjState{
        SelectObjStateChild* m_child;
    public:
        SelectObjState(SelectObj* user);
        ~SelectObjState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
    
}


#endif /* defined(__Karakuri2_Mac__MapSelectSceneSelectObjState__) */
