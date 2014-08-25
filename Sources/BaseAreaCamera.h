//
//  BaseAreaCamera.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/24.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__BaseAreaCamera__
#define __Karakuri2_Mac__BaseAreaCamera__

#include "Karakuri.h"

namespace baseArea{
    class SKBaseAreaScene;
    
    // 内部座標は、１マスを１とした座標。
    // カメラ側で、これを画面座標に変換。
    class Camera{
        GMVector3D m_eye;
        GMVector3D m_tar;
        GMVector3D m_up;
        SKBaseAreaScene* m_parent;
    public:
        Camera(SKBaseAreaScene* parent);
        ~Camera();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        GMMatrix createViewMatrix() const;
        GMMatrix createRevirthMatrix() const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__BaseAreaCamera__) */
