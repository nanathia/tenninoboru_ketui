//
//  Murabito.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__Murabito__
#define __Karakuri2_Mac__Murabito__

#include "Karakuri.h"
#include <deque>

namespace SKSpeakWindow{
    class Window;
}
namespace tinyxml2{
    class XMLElement;
}
namespace characterspeak{
    class SpeakStrManager;
}

namespace baseArea{
    
    class MurabitoManager;
    class BaseAreaMap;
    
    class Murabito{
    public:
        // タイプ
        enum obj_type{
            type_freeMove,
            type_left,
            type_right,
            type_top,
            type_bottom,
        };
    private:
        BaseAreaMap* m_parent;
        const obj_type m_type;
        const std::string m_Name;
        GMRect2D m_Rect;
        characterspeak::SpeakStrManager* m_speak;
    public:
        Murabito(tinyxml2::XMLElement* data, BaseAreaMap* parent);
        ~Murabito();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void setPos(const GMVector2D& pos);
        const std::string& Name() const;
        bool isCollision(const GMRect2D& rect) const;
        characterspeak::SpeakStrManager* getSpeak();
    };
    
}

#endif /* defined(__Karakuri2_Mac__Murabito__) */
