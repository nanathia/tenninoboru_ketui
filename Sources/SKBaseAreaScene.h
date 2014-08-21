//
//  SKBaseAreaScene.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKBaseAreaScene__
#define __Karakuri2_Mac__SKBaseAreaScene__

#include "Karakuri.h"
#include "SKPlayChild.h"
#include <string>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class BaseAreaMap;
    class CharacterManager;
    
    class SKBaseAreaScene: public SKPlayChild{
        BaseAreaMap* m_Map;
        CharacterManager* m_CharacterMan;
    public:
        SKBaseAreaScene(const std::string& areaName);
        ~SKBaseAreaScene();
        SKPlayChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
};

#endif /* defined(__Karakuri2_Mac__SKBaseAreaScene__) */
