//
//  SKSceneChangeInters.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKSceneChangeInters__
#define __Karakuri2_Mac__SKSceneChangeInters__


#include "Karakuri.h"
#include "SKPlaySceneState.h"

namespace playsceneinter{
    
    class Dungeon: public SKPlaySceneInter{
    public:
        Dungeon(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
        ~Dungeon();
        SKPlaySceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class MapSelect: public SKPlaySceneInter{
    public:
        MapSelect(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
        ~MapSelect();
        SKPlaySceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class BaseArea: public SKPlaySceneInter{
    public:
        BaseArea(SKPlayChild* prevChild, SKPlayChild* nextChild, SKPlayScene* user);
        ~BaseArea();
        SKPlaySceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
}


#endif /* defined(__Karakuri2_Mac__SKSceneChangeInters__) */
