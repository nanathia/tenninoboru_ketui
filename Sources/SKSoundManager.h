//
//  SKSoundManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKSoundManager__
#define __Karakuri2_Mac__SKSoundManager__

#include "Karakuri.h"
#include <map>

class SKSoundManager{
    std::map<int, GMSound*> m_sounds;
public:
    SKSoundManager();
    ~SKSoundManager();
    void add(int name, const std::string& fileName);
    GMSound* get(int name);
};

#endif /* defined(__Karakuri2_Mac__SKSoundManager__) */
