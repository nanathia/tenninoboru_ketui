//
//  SKTextueManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKTextueManager__
#define __Karakuri2_Mac__SKTextueManager__

#include "Karakuri.h"
#include "GMTexture2D.h"
#include <map>

class SKTextureManager{
    std::map<int, GMTexture2D*> m_tex;
    
public:
    SKTextureManager();
    ~SKTextureManager();
    
    GMTexture2D* get(int name);
    void add(int name, const char* fileName);
    
private:
    
};

#endif /* defined(__Karakuri2_Mac__SKTextueManager__) */
