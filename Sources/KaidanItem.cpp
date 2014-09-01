//
//  KaidanItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "KaidanItem.h"
#include "ItemCommandInfo.h"
#include "SaKumas_includes.h"
#include "SKDungeonScene.h"

KaidanItem::KaidanItem(SKDungeonScene* scene):
SKItem(scene)
{
    this->setName("階段");
    this->m_itemNum = 8;
}

KaidanItem::~KaidanItem(){
    
}

void KaidanItem::noru(){
    
}

void KaidanItem::getSetumei(std::string& str){
    
}

CarsorSelectReAction* KaidanItem::getSelectReaction(){
    CommandInfo* com = new CommandInfo(m_scene);
    return com;
}