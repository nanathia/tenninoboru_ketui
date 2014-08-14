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

class SKMusicManager;
class SKSoundManager;
class SKTextureManager;

enum SKSoundName{
    SoundName_Carsor,
    SoundName_Return,
    SoundName_JACharHalt,
};

enum SKMusicName{
};

enum SKTextureName{
    TextureName_Fill,
};

// このクラスのインスタンスには、gGameInst 変数でアクセスできます。

class GameMain : public GMGame {
    GMTexture2D* m_sizuruFont;
    GMFont* m_sazamekiFont;
    SKMusicManager* m_MusicMan;
    SKSoundManager* m_SoundMan;
    SKTextureManager* m_texMan;

public:
    
    GameMain();
    virtual ~GameMain();
    
    GMTexture2D* getFontTex() const;
    void setFont(GMTexture2D* sizuru);
    GMFont* getFont();
    SKMusicManager* getMusicMan();
    SKSoundManager* getSoundMan();
    SKTextureManager* getTexMan();
    
};


extern GameMain *gGameInst;


#endif  //#ifndef __GAMEMAIN_H__

