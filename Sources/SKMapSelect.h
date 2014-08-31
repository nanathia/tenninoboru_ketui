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
    class BackImage;
    class SelectObjManager;
    class SelectCarsor;
    class SceneState;
    
    // マップセレクトシーン
    class SKMapSelectScene: public SKPlayChild{
    public:
        enum texName{
            texName_BGI,
            texName_Tetorapeddora,
            texName_Hyururimyururi,
            texName_Gendoumurasaki,
            texName_Tentinoreiei,
            texName_Kaminoyasiro,
            texName_Uminodoukutu,
            texName_Carsor,
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
            scene_TetoraPeddora,
            scene_Gendoumurasaki,
            scene_Tentinoreiei,
            scene_Kaminoyasiro,
            scene_Hyururimyururi,
            scene_Uminodoukutu,
        };
    private:
        // テクスチャ管理
        SKTextureManager* m_TexMan;
        // BGM管理
        SKMusicManager* m_MusicMan;
        // 効果音
        SKSoundManager* m_SoundMan;
        // カメラは要らない
        // 時空亜空は喋る
        JASpeakWindow::Window* m_JaSpkWin;
        // バックイメージ
        BackImage* m_backImage;
        // エリア選択カーソル
        SelectCarsor* m_carsor;
        // 選択エリアオブジェクト
        SelectObjManager* m_selectAreaMan;
        // 状態
        SceneState* m_state;
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
        void ChangeSelect();
        void ChangeBaseAreaReady();
        BackImage* getBackImage();
        SelectCarsor* getCarsor();
        SelectObjManager* getSelectObjMan();
        bool isChangeAreaReady() const;
    };
    
};

#endif /* defined(__Karakuri2_Mac__SKMapSelect__) */
