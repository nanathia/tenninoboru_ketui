//
//  BaseAreaPlayer.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/23.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKTextureManager.h"
#include "BaseAreaSouces.h"

namespace baseArea{
    
    Player::Player(SKBaseAreaScene* parent):
    m_Matrixrect(GMVector2D(80, -100), 0.7/*タイルの0.7倍の当たり判定*/),
    // 描画範囲は１タイル分で固定
    m_parent(parent)
    {
        m_state = new PlayerAngleState(this);
    }
    Player::~Player(){
        delete m_state;
    }
    void Player::update(GMInput *input, double deltaTime){
        m_state->update(input, deltaTime);
        // 一秒間で、何マス動くかをここで指定
        double speed = deltaTime*4;
        GMRect2D tempRect(m_Matrixrect);
        if(input->isKeyDown(GMKeyMaskUp)){
            tempRect.y += speed;
        }
        if(input->isKeyDown(GMKeyMaskDown)){
            tempRect.y -= speed;
        }
        if(input->isKeyDown(GMKeyMaskDown)^input->isKeyDown(GMKeyMaskUp)){
            if(m_parent->getMap()->getTileLayerMan()->isCollision(tempRect)){
                tempRect.y = m_Matrixrect.y;
            }
        }
        if(input->isKeyDown(GMKeyMaskRight)){
            tempRect.x += speed;
        }
        if(input->isKeyDown(GMKeyMaskLeft)){
            tempRect.x -= speed;
        }
        if(input->isKeyDown(GMKeyMaskLeft)^input->isKeyDown(GMKeyMaskRight)){
            if(m_parent->getMap()->getTileLayerMan()->isCollision(tempRect)){
                tempRect.x = m_Matrixrect.x;
            }
        }
        m_Matrixrect.x = tempRect.x;
        m_Matrixrect.y = tempRect.y;
    }
    void Player::draw(GMSpriteBatch *s){
        m_state->draw(s);
    }
    SKBaseAreaScene* Player::getBaseAreaScene(){
        return m_parent;
    }
    GMVector2D Player::getPos() const{
        return GMVector2D(m_Matrixrect.x, m_Matrixrect.y);
    }
    
    
#pragma mark ---描画用メソッド---
    void PlayerDraw::draw(GMSpriteBatch* s, Player* player, int chipName){
        // 描画座標に変換
        GMRect2D src(0, 0, 32, 32);
        GMRect2D dest(GMRect2D(SKBaseAreaScene::convertMat2Draw(player->getPos()), SKBaseAreaScene::getTileDestSize()));
        if(chipName==chipName_left1 || chipName==chipName_left2){
            if(chipName == chipName_left1){
                src.x = chipName_right2;
                src.y = 1;
            }else{
                src.x = chipName_right2;
                src.y = 0;
            }
            dest.x += SKBaseAreaScene::getTileDestSize().x;
            dest.width *= -1;
        }else{
            src.x = chipName%3;
            src.y = chipName/3;
        }
        src.x *= 32;
        src.y *= 32;
        s->draw(player->getBaseAreaScene()->getTexMan()->get(SKBaseAreaScene::texName_player), dest, src);
    }
    
}