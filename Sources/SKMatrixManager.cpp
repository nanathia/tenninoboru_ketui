//
//  SKMatrixManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKMatrixManager.h"



SKMatrixManager::SKMatrixManager(){
    
}

SKMatrixManager::~SKMatrixManager(){
    int size = (int)(m_matrix.size());
    for(int i = 0; i < size; i++){
        delete m_matrix[i];
        m_matrix[i] = 0;
    }
    
}

GMMatrix* get();
void add(GMMatrix* newMatrix);