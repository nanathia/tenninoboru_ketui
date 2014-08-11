//
//  GameMain.cpp
//  Game Framework
//
//  Created by numata on Dec 27, 2010.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#include "GameMain.h"
#include "Globals.h"
#include "SKPlayScene.h"
#include "SKTitle.h"
#include "SKGameOver.h"
#include "SKMusicManager.h"
#include "SKSoundManager.h"


GameMain*   gGameInst = 0;


GameMain::GameMain():
m_sizuruFont(0),
m_sazamekiFont(0)
{
    gGameInst = this;
    
    ///// ゲームの初期化
    // TODO: ゲーム内で共通して利用する変数などがあれば、ここで準備してください。
    // TODO: GameMain クラスのインスタンスには、GameMain.h をインクルードして gGameInst 変数で参照します。
    m_MusicMan = new SKMusicManager;
    m_SoundMan = new SKSoundManager;
    m_SoundMan->add(SoundName_Return, "SKCommandSelectReturn.wav");
    m_SoundMan->add(SoundName_Carsor, "SKSelectChange.wav");
    
    ///// シーンの追加
    addScene("play", new SKPlayScene());
    addScene("title", new SKTitle());
    addScene("gameOver", new SKGameOver());

    ///// 最初のシーンの選択
    GMGame::ChangeScene( "title" );
    
    if(gGMHasGameStartError){
        GMException("なんかエラー");
    }
    
}

GameMain::~GameMain()
{
    ///// ゲームの解放
    // TODO: ゲーム内で共通して利用していた変数などがあれば、ここで解放してください。
    delete m_SoundMan;
    m_SoundMan = 0;
    delete m_MusicMan;
    m_MusicMan = 0;
    delete m_sizuruFont;
    m_sizuruFont = 0;
    delete m_sazamekiFont;
    m_sazamekiFont = 0;
}

GMTexture2D* GameMain::getFontTex() const{
    return m_sizuruFont;
}

void GameMain::setFont(GMTexture2D* sizuru){
    m_sizuruFont = sizuru;
    m_sazamekiFont = new GMFont("font-menlo-28x56.png", GMVector2D(28,56));
}

GMFont* GameMain::getFont(){
    return m_sazamekiFont;
}

SKMusicManager* GameMain::getMusicMan(){
    return m_MusicMan;
}

SKSoundManager* GameMain::getSoundMan(){
    return m_SoundMan;
}

