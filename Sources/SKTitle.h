//
//  SKTitle.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKTitle__
#define __Karakuri2_Mac__SKTitle__

#include "Karakuri.h"

class SKMusicManager;
class SKSoundManager;
namespace titleScene{
    class SceneChild;
}
enum TitleMusicName{
    MusicName_Main
};
enum TitleSoundName{
    SoundName_Logo
};

class SKTitle : public GMScene{
    GMBasicEffect* m_BasicEffect;
    GMSpriteBatch* m_SpriteBatch;
    titleScene::SceneChild* m_child;
    SKMusicManager* m_MusicMan;
    SKSoundManager* m_SoundMan;
public:
    void drawView(GMGraphics* g) override;
    void updateModel(GMInput* input, double deltaTime) override;
    void willAppear(GMGraphics* g) override;
    void didDisappear() override;
    SKTitle();
    ~SKTitle();
    SKSoundManager* getSoundMan();
    SKMusicManager* getMusicMan();
};

extern SKTitle* gTitleScene;

#endif /* defined(__Karakuri2_Mac__SKTitle__) */

