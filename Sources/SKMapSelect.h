//
//  SKMapSelect.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMapSelect__
#define __Karakuri2_Mac__SKMapSelect__


#include "Karakuri.h"
#include "SKPlayChild.h"
#include <string>

// ｘｍｌパーサー
namespace tinyxml2{
    class XMLElement;
}

// リソースマネージャー
class SKTextureManager;
class SKMusicManager;
class SKSoundManager;

// 時空亜空の言葉の窓
namespace JASpeakWindow{
    class Window;
}

// マップセレクト名前空間
namespace mapSelect{
    class BaseAreaMap;
    class CharacterManager;
    class Camera;
    
    // マップセレクトシーン
    class SKMapSelectScene: public SKPlayChild{
        // テクスチャ管理
        SKTextureManager* m_TexMan;
        // BGM管理
        SKMusicManager* m_MusicMan;
        // 効果音
        SKSoundManager* m_SoundMan;
        // カメラは要らない
        // 時空亜空は喋る
        JASpeakWindow::Window* m_JaSpkWin;
    public:
        // 画像名を記載
        enum texName{
            texName_player,
            texName_murabito,
        };
        // BGM名を記載
        enum musicName{
            musicName_back,
        };
        // 効果音名を記載
        enum soundName{
        };
        // 移動エリアを記載
        enum areaScenes{
            scene_tetorasyouzoku,
            scene_gendoumurasaki,
            scene_tentinoreiei,
            scene_kaminoyasiro,
            scene_hyururimyururi,
            scene_uminodoukutu,
        };
    public:
        // 初期化と終了
        // はじめにカーソルがあるべき場所を渡す移動前エリアを渡す
        SKMapSelectScene(areaScenes firstCarsor);
        ~SKMapSelectScene();
        // 描画と更新
        SKPlayChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        // リソース取得
        SKTextureManager* getTexMan();
        SKMusicManager* getMusicMan();
        SKSoundManager* getSoundMan();
    public:
        JASpeakWindow::Window* getJaSpkWin();
    };
    
};

#endif /* defined(__Karakuri2_Mac__SKMapSelect__) */
