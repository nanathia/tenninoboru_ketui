//
//  GameMain.h
//  Game Framework
//
//  Created by numata on Dec 27, 2010.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__


#include "Karakuri.h"
#include "Globals.h"


// このクラスのインスタンスには、gGameInst 変数でアクセスできます。

class GameMain : public GMGame {
    GMTexture2D* m_sizuruFont;
    GMFont* m_sazamekiFont;

public:
    
    GameMain();
    virtual ~GameMain();
    
    GMTexture2D* getFontTex() const;
    void setFont(GMTexture2D* sizuru);
    GMFont* getFont();
    
};


extern GameMain *gGameInst;


#endif  //#ifndef __GAMEMAIN_H__

