//
//  SKTitleChild.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/06.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKTitleChild__
#define __Karakuri2_Mac__SKTitleChild__

#include "Karakuri.h"

namespace selectWindow{
    class Window;
    class Element;
    class Carsor;
}

namespace titleScene{
    class LogoChild;
    class MainChild;
    class SceneChild{
    public:
        GMMusic* m_BGMusic;
        double m_time;
        double m_animationTime;
    public:
        SceneChild();
        virtual ~SceneChild();
        virtual SceneChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
    };
    
    class TitleLogo: public SceneChild{
        LogoChild* m_child;
    public:
        GMTexture2D* m_LogoImage;
        TitleLogo();
        ~TitleLogo();
        SceneChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    class TitleMain: public SceneChild{
        MainChild* m_child;
    public:
        GMTexture2D* m_BGImage;
    public:
        TitleMain();
        ~TitleMain();
        SceneChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
}

#endif /* defined(__Karakuri2_Mac__SKTitleChild__) */
