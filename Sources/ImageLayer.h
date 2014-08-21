//
//  ImageLayer.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ImageLayer__
#define __Karakuri2_Mac__ImageLayer__

#include "Karakuri.h"
#include <list>

namespace tinyxml2{
    class XMLElement;
}

namespace baseArea{
    class MapImage;
    
    class ImageLayer{
        std::list<MapImage*> m_Images;
    public:
        ImageLayer(tinyxml2::XMLElement* data);
        ~ImageLayer();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    };
    
}

#endif /* defined(__Karakuri2_Mac__ImageLayer__) */
