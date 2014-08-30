//
//  SwordItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKSword.h"
#include "SaKumas_includes.h"
#include "ItemCommandInfo.h"
#include <string>

SwordItem::SwordItem(SKDungeonScene* scene):
EpuipmentItem(scene){
    this->setName("剣");
    this->m_itemNum = 0;
}

SwordItem::~SwordItem(){
    
}

void SwordItem::soubi(){
    // TODO: SKItem::useの実装
    
    return;
    
}

void SwordItem::hazusu(){
    // TODO: SKItem::getの実装
    
    return;
}

void SwordItem::getSetumei(std::string &strIn){
    
}

CarsorSelectReAction* SwordItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo(m_scene);
    command->addCarsor(new SoubiCommand(m_scene));
    command->addCarsor(new NageruCommand(m_scene));
    command->addCarsor(new OkuCommand(m_scene));
    command->addCarsor(new SetumeiCommand(m_scene));
    return command;
    
}