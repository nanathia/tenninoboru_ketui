//
//  SKDrawManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKDrawManager__
#define __Karakuri2_Mac__SKDrawManager__

#include "Karakuri.h"
#include "SKTextureManager.h"
#include "SKMatrixManager.h"

class SKTextureMan;
class SKMatrixManager;


class SKDrawManager{
    SKTextureMan* m_texture;
    SKMatrixManager* m_matrix;
    
    SKDrawManager();
    ~SKDrawManager();
    
public:
    void add(int imageNum, GMMatrix* matrix);
    void draw(GMMatrix* projectionMatrix) const;
};

#endif /* defined(__Karakuri2_Mac__SKDrawManager__) */
