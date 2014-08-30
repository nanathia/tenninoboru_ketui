//
//  SKBaseAreaScene.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKBaseAreaScene__
#define __Karakuri2_Mac__SKBaseAreaScene__

#include "Karakuri.h"
#include "SKPlayChild.h"
#include <string>

namespace tinyxml2{
    class XMLElement;
}
class SKTextureManager;
class SKMusicManager;
class SKSoundManager;
namespace SKSpeakWindow{
    class Window;
}

namespace baseArea{
    class BaseAreaMap;
    class CharacterManager;
    class Camera;
    
    class SKBaseAreaScene: public SKPlayChild{
        SKTextureManager* m_TexMan;
        SKMusicManager* m_MusicMan;
        SKSoundManager* m_SoundMan;
        BaseAreaMap* m_Map;
        CharacterManager* m_CharacterMan;
        GMMatrix m_ViewMatrix;
        Camera* m_Camera;
        SKSpeakWindow::Window* m_nomalSpeakWindow;
    public:
        enum texName{
            texName_player,
            texName_murabito,
        };
        enum musicName{
            musicName_back,
        };
        enum soundName{
        };
    public:
        SKBaseAreaScene(const std::string& areaName);
        ~SKBaseAreaScene();
        SKPlayChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        CharacterManager* getCharMan();
        BaseAreaMap* getMap();
        SKTextureManager* getTexMan();
        SKMusicManager* getMusicMan();
        SKSoundManager* getSoundMan();
        void setViewMatrix(const GMMatrix& view);
    public:
        // 描画座標を取得
        static GMVector2D convertMat2Draw(const GMVector2D& matrixVector);
        static const GMVector2D& getTileDestSize();
        SKSpeakWindow::Window* getNomalSpeakWin();
    };
    
};

#endif /* defined(__Karakuri2_Mac__SKBaseAreaScene__) */
