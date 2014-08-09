//
//  SKKeyHandler.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKKeyHandler__
#define __Karakuri2_Mac__SKKeyHandler__

#include "Karakuri.h"

class State_Key;

class SKKeyHandle{
    // ステイトパターン実装クラス
    friend class State_W_Key;
    friend class State_Nomal_Key;
    friend class State_Skip_Key;
    friend class State_Menu_Key;
    
    static unsigned m_flags;
    static unsigned m_preFlags;
    // 前回の行動キー入力からの時間。０〜１で補間を取るので、１になると終了。
    // SakumasIncludeに、移動時間を明記し計算。
    static double m_time;
    // ステイト
    static State_Key* m_state;
public:
    static bool isUpdate();
    static bool isReturn();
    static bool isChancel();
    static bool isMenu();
    static bool isRight();
    static bool isLeft();
    static bool isUp();
    static bool isDown();
    static bool isMoveEnd();
    // 移動中等、入力不可状態。
    static bool isKeyInputLocked();
    
    static void KeyFlag_update(GMInput* input, double deltaTime);
    
    enum keyNames{
        key_right = (1<<0),
        key_right_once = (1<<1),
        key_left = (1<<2),
        key_left_once = (1<<3),
        key_up = (1<<4),
        key_up_once = (1<<5),
        key_down = (1<<6),
        key_down_once = (1<<7),
        key_return = (1<<8),
        key_return_once = (1<<8),
        key_chancel = (1<<9),
        key_chancel_once = (1<<10),
        key_menu = (1<<11),
        key_menu_once = (1<<12),
        key_playerAction = (1<<13),
        key_right_up = (1<<14),
        key_left_up = (1<<15),
        key_right_down = (1<<16),
        key_left_down = (1<<17),
        key_moveEnd = (1<<18),
    };
    
    static void set(unsigned keyFlag);
    static void down(unsigned keyFlag);
    
public:
    static void create();
    static void destroy();

private:
    SKKeyHandle();
    ~SKKeyHandle();
    
    static SKKeyHandle* m_instance;
};

#endif /* defined(__Karakuri2_Mac__SKKeyHandler__) */
