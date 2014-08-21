//
//  SKItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKItem.h"
#include "SKItemInclude.h"
#include "SaKumas_includes.h"
#include "SKDungeonScene.h"

namespace{
    const int yNum = 2;
    const int xNum = 8;
}

SKItem* SKItem::createRandamItem(){
    // TODO: アイテムのランダム生成の実装
    SKItem* item = 0;
    int i = randam_dungeon::rand(0, 7);
    if(i==0){
        item = new SwordItem();
    }else if(i==1){
        item = new ShieldItem();
    }else if(i==2){
        item = new UdewaItem();
    }else if(i==3){
        item = new ToutekiItem();
    }else if(i==4){
        item = new NenryouItem();
    }else if(i==5){
        item = new MakimonoItem();
    }else if(i==6){
        item = new EatingItem();
    }else if(i==7){
        item = new KusaItem();
    }
    return item;
}

void SKItem::objectDraw(int i_x, int i_y){
    GMDraw::Begin();
    gPlayScene->getCurrentEffect()->setTexture(gPlayScene->getDungeonScene()->getTexMan()->get(Texture_itemName));
    int x = m_itemNum%xNum;
    int y = m_itemNum/xNum;
    GMDraw::FillQuad(GMVector3D(i_x, i_y, 10), GMVector3D(i_x+mass_size+1, i_y, 10),
                     GMVector3D(i_x+mass_size+1, i_y+mass_size+1, 10), GMVector3D(i_x, i_y+mass_size+1, 10),
                     GMVector3D(0, 0, 1), GMVector3D(0, 0, 1),
                     GMVector3D(0, 0, 1), GMVector3D(0, 0, 1),
                     GMVector2D(1.0/xNum*x, 1.0/yNum*y), GMVector2D(1.0/xNum*(x+1), 1.0/yNum*y),
                     GMVector2D(1.0/xNum*(x+1), 1.0/yNum*(y+1)), GMVector2D(1.0/xNum*x, 1.0/yNum*(y+1)));
    GMDraw::End();
    
}

bool SKItem::objectUpdate(GMInput* input, double deltaTime){
    // TODO: SKItem::objectUpdate()のリターン値の検証
    return true;
}

void SKItem::objectInit(GMGraphics* g){
    
}

SKItem::SKItem():
SKObject(),
m_numName(itemNames::none),
m_flag(0),
m_itemNum(0),
m_delFlag(false)
{
    m_objectName = "仮素材";
}

SKItem::SKItem(const std::string& str):
SKObject(),
m_numName(itemNames::none),
m_flag(0)
{
    m_objectName = str;
    if(str == "階段"){
        m_itemNum = 8;
    }
}

SKItem::~SKItem(){
    
}

bool SKItem::isDel(){
    return m_delFlag;
}
