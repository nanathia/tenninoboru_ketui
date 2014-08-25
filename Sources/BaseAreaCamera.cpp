//
//  BaseAreaCamera.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/24.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaCamera.h"
#include "BaseAreaSouces.h"
#include "Globals.h"

namespace baseArea{
    
    Camera::Camera(SKBaseAreaScene* parent):
    m_parent(parent),
    m_eye(0, 0, 1),
    m_tar(0, 0, 0),
    m_up(0, 1, 0){
        
    }
    Camera::~Camera(){
        
    }
    void Camera::update(GMInput *input, double deltaTime){
        GMVector2D p_pos(SKBaseAreaScene::convertMat2Draw(m_parent->getCharMan()->getPlayer()->getPos())-SCREEN_SIZE/2);
        m_eye.x = p_pos.x;
        m_eye.y = p_pos.y;
        m_tar.x = p_pos.x;
        m_tar.y = p_pos.y;
    }
    void Camera::draw(GMSpriteBatch *s){
        
    }
    GMMatrix Camera::createViewMatrix() const{
        return GMMatrix::CreateLookAt(m_eye, m_tar, m_up);
    }
    GMMatrix Camera::createRevirthMatrix() const{
        GMVector3D revirthEye(m_eye);
        GMVector3D revirthTar(m_tar);
        revirthEye.y *= -1;
        revirthTar.y *= -1;
        return GMMatrix::CreateLookAt(revirthEye, revirthTar, m_up);
    }
    
}