//
//  MapSelectSceneSelectObjManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneSelectObjManager__
#define __Karakuri2_Mac__MapSelectSceneSelectObjManager__

#include "Karakuri.h"
#include <list>

namespace mapSelect{
    class SelectObj;
    class SKMapSelectScene;
    
    class SelectObjManager{
        std::list<SelectObj*> m_data;
        SKMapSelectScene* m_parent;
    public:
        SelectObjManager(SKMapSelectScene* parent);
        ~SelectObjManager();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void add(SelectObj* obj);
    };
    
}

#endif /* defined(__Karakuri2_Mac__MapSelectSceneSelectObjManager__) */
