//
//  BaseAreaPlayer.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/23.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKTextureManager.h"
#include "BaseAreaSouces.h"
#include "BaseAreaPlayerMainState.h"

namespace baseArea{
    
    Player::Player(SKBaseAreaScene* parent):
    m_Matrixrect(GMVector2D(80, -100), 0.7/*タイルの0.7倍の当たり判定*/),
    // 描画範囲は１タイル分で固定
    m_parent(parent),
    m_state(0),
    m_secondState(0)
    {
        m_state = new PlayerAngleState(this);
        m_secondState = new PlayerMainState(this);
    }
    Player::~Player(){
        delete m_state;
        m_state = 0;
        delete m_secondState;
        m_secondState = 0;
    }
    void Player::update(GMInput *input, double deltaTime){
        m_state->update(input, deltaTime);
        m_secondState->update(input, deltaTime);
    }
    void Player::draw(GMSpriteBatch *s){
        m_state->draw(s);
        m_secondState->draw(s);
    }
    SKBaseAreaScene* Player::getBaseAreaScene(){
        return m_parent;
    }
    GMVector2D Player::getPos() const{
        return GMVector2D(m_Matrixrect.x, m_Matrixrect.y);
    }
    const GMRect2D& Player::Rect() const{
        return m_Matrixrect;
    }
    void Player::setPos(const GMVector2D& pos){
        m_Matrixrect.x = pos.x;
        m_Matrixrect.y = pos.y;
    }
    void Player::setRect(const GMRect2D& rect){
        m_Matrixrect = rect;
    }
    void Player::speak(baseArea::Murabito *mura){
        m_secondState->speak(mura);
    }
    bool Player::isSpeak() const{
        return m_secondState->isSpeak();
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