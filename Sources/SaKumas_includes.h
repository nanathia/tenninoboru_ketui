//
//  SaKumas_includes.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/03.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef Karakuri2_Mac_SaKumas_includes_h
#define Karakuri2_Mac_SaKumas_includes_h

#include "SKPlayScene.h"
#include "SKEffectMan.h"
#include "SKMassManager.h"
#include "SKMass.h"
#include "SKSoundMan.h"
#include "SKPlayer.h"
#include "SKObject.h"
#include "SKEnemyMan.h"
#include "SKEnemy.h"
#include "SKBlockManager.h"
#include "SKBlock.h"
#include "SKItemManager.h"
#include "SKItem.h"
#include "SKTextureManager.h"
#include "SKKeyHandler.h"
#include "SKItemContainar.h"
#include "SKUserInterface.h"

#include "Globals.h"

#define mass_size (32)
// 秒で
#define player_moving_time (0.2)

template<typename T> void safeCleanUp(std::vector<T*>& p){
    std::vector<T*>(p).swap(p);
}

static const int width_num = static_cast<int>(SCREEN_SIZE.x)/mass_size+1;
static const int height_num = static_cast<int>(SCREEN_SIZE.y)/mass_size+1;
static const int massDrawOffset_x = static_cast<int>(SCREEN_SIZE.x)%mass_size ? mass_size/4+mass_size/2 : mass_size/2;
static const int massDrawOffset_y = static_cast<int>(SCREEN_SIZE.y)%mass_size ? mass_size/4+mass_size/2 : mass_size/2;

#endif
