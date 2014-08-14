//
//  SKStartDemo.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKStartDemo__
#define __Karakuri2_Mac__SKStartDemo__

#include "Karakuri.h"

namespace startdemo{
    class StartDemoState;
}
class SKMusicManager;
class SKSoundManager;
class SKTextureManager;

class SKStartDemo: public GMScene{
    SKTextureManager* m_texMan;
    SKMusicManager* m_MusicMan;
    SKSoundManager* m_SoundMan;
    GMBasicEffect* m_BasicEffect;
    GMSpriteBatch* m_SpriteBatch;
    startdemo::StartDemoState* m_state;
public:
    enum musicName{
        musicName_MainBGM,
    };
    enum soundName{
        SoundName_,
    };
    enum texName{
        texName_Tetorapeddora,
        texName_sakuma,
        texName_sakuma_c,
        texName_jiikuuakuu,
    };
    void drawView(GMGraphics* g) override;
    void updateModel(GMInput* input, double deltaTime) override;
    void willAppear(GMGraphics* g) override;
    void didDisappear() override;
    SKStartDemo();
    ~SKStartDemo();
public:
    SKSoundManager* getSoundMan();
    SKMusicManager* getMusicMan();
    SKTextureManager* getTexMan();
};

extern SKStartDemo* gStartDemo;

#endif /* defined(__Karakuri2_Mac__SKStartDemo__) */
