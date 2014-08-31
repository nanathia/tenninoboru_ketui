//
//  MapSelectSceneCarsor.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneCarsor__
#define __Karakuri2_Mac__MapSelectSceneCarsor__

#include "Karakuri.h"

namespace mapSelect{
    class SKMapSelectScene;
    class SelectObj;
    class SelectCarsorState;
    
    class SelectCarsor{
        // 親
        SKMapSelectScene* m_parent;
        // 状態
        SelectCarsorState* m_state;
    public:
        SelectCarsor(SelectObj* firstSelect, SKMapSelectScene* parent);
        ~SelectCarsor();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        SKMapSelectScene* getScene();
        SelectObj* getCurrentObj();
    };
    
}

#endif /* defined(__Karakuri2_Mac__MapSelectSceneCarsor__) */
