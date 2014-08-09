//
//  EatingItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "EatingItem.h"
#include "SaKumas_includes.h"
#include "ItemCommandInfo.h"
#include <string>

EatingItem::EatingItem():
UsingItem()
{
    this->setName("食べ物");
    this->m_itemNum = 6;
}

void EatingItem::use(){
}

CarsorSelectReAction* EatingItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo();
    command->addCarsor(new TaberuCommand());
    command->addCarsor(new NageruCommand());
    command->addCarsor(new OkuCommand());
    command->addCarsor(new SetumeiCommand());
    return command;
    
}

void EatingItem::getSetumei(std::string& str){
    str = "食料だ。まだ未実装である。";
}