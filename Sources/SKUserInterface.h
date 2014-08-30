//
//  SKUserInterface.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/14.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKUserInterface__
#define __Karakuri2_Mac__SKUserInterface__

#include "Karakuri.h"
#include "MessageUI.h"
#include "SelectUI.h"
#include "StatusUI.h"
#include <string>

class SKDungeonScene;

class SKUserInterface{
    // 3D画面ゲーム画面と別に、2D描画を行うためのGMSpriteBatch
    GMSpriteBatch* mSpriteBatch;
    SKDungeonScene* m_scene;
    
    MessageUI* m_message;
    StatusUI* m_status;
    SelectUI* m_select;
    
public:
    // 画面に対してどのぐらいの割合を占めるかというのと、画面上の位置。いずれも、０〜１で渡す。
    // とりあえずデフォ値
    SKUserInterface(SKDungeonScene* scene);
    ~SKUserInterface();
    
public:
    // 外部から使用するメソッド
    
    static std::string convertNum2Str(int num);
    
    // 下のメッセージウインドウにテキストを出力する。
    void addText(const std::string& str);
    // メニューを表示しているかどうか。
    bool isMenuOpen();
    void uiOn();
    void uiOff();
    // 画面座標に変換する
    static GMRect2D convertRatioToPixel(const GMRect2D&);
    // 更新する
    
    /*ちょっとこのクラスについての構想考える
    あらゆるメッセージ出力命令を各所から（サクマ、敵、グローバルなメッセージ（時空亜空かどうかはまた後で決める））
    受け取る。受け取り方は、textInput()関数で。
    */
    
    // 描画情報の更新、取りまとめ。
    void updateUI(GMInput* input, double deltaTime);
    // 描画する
    void drawUI() const;
    
    // メッセージ出力をクラスにお願いする。ゲーム中の様々な場所から呼ばれる。
    void textInput(const std::string&);
    
protected:
//    内部関数
    
};

#endif /* defined(__Karakuri2_Mac__SKUserInterface__) */
