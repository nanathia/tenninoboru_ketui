//
//  SKMusicManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/10.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMusicManager__
#define __Karakuri2_Mac__SKMusicManager__

#include "Karakuri.h"
#include <map>

class SKMusicManager{
    std::map<int, GMMusic*> m_Musics;
public:
    SKMusicManager();
    ~SKMusicManager();
    void add(int name, const std::string& fileName);
    GMMusic* get(int name);
};

#endif /* defined(__Karakuri2_Mac__SKMusicManager__) */
