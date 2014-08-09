//
//  SKMatrixManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMatrixManager__
#define __Karakuri2_Mac__SKMatrixManager__

#include "Karakuri.h"
#include <vector>

class SKMatrixManager{
    std::vector<GMMatrix*> m_matrix;
    
    SKMatrixManager();
    ~SKMatrixManager();
    
public:
    GMMatrix* get();
    void add(GMMatrix* newMatrix);
    
};

#endif /* defined(__Karakuri2_Mac__SKMatrixManager__) */
