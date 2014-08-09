//
//  SKShield.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/05.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKShield.h"
#include "SKItemInclude.h"
#include "SaKumas_includes.h"

// 装備
// 投げる
// 置く
// 説明

ShieldItem::ShieldItem():
EpuipmentItem(){
    this->setName("盾");
    this->m_itemNum = 1;
}

ShieldItem::~ShieldItem(){
    
}

CarsorSelectReAction* ShieldItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo();
    command->addCarsor(new SoubiCommand());
    command->addCarsor(new NageruCommand());
    command->addCarsor(new OkuCommand());
    command->addCarsor(new SetumeiCommand());
    return command;
    
}

void ShieldItem::getSetumei(std::string &str){
    str = "盾の説明だ。まだ未実装だ。";
}

void ShieldItem::soubi(){
    gPlayScene->getPlayer()->soubiShiled(this);
}

void ShieldItem::hazusu(){
    gPlayScene->getPlayer()->soubiShiled(0);
}