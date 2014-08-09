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

SwordItem::SwordItem():
EpuipmentItem(){
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
    CommandInfo* command = new CommandInfo();
    command->addCarsor(new SoubiCommand());
    command->addCarsor(new NageruCommand());
    command->addCarsor(new OkuCommand());
    command->addCarsor(new SetumeiCommand());
    return command;
    
}