//
//  ToutekiItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ToutekiItem.h"
#include "ItemCommandInfo.h"

ToutekiItem::ToutekiItem():
UsingItem(){
    this->setName("投物");
    this->m_itemNum = 8;
}

void ToutekiItem::use(){
    
}

CarsorSelectReAction* ToutekiItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo();
    command->addCarsor(new UtuCommand());
    command->addCarsor(new NageruCommand());
    command->addCarsor(new OkuCommand());
    command->addCarsor(new SetumeiCommand());
    return command;
    
}

void ToutekiItem::getSetumei(std::string &str){
    str = "投擲アイテムだ。まだ未実装だ。";
}