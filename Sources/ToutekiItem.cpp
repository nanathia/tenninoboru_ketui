//
//  ToutekiItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ToutekiItem.h"
#include "ItemCommandInfo.h"

ToutekiItem::ToutekiItem(SKDungeonScene* scene):
UsingItem(scene){
    this->setName("投物");
    this->m_itemNum = 7;
}

void ToutekiItem::use(){
    
}

CarsorSelectReAction* ToutekiItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo(m_scene);
    command->addCarsor(new UtuCommand(m_scene));
    command->addCarsor(new NageruCommand(m_scene));
    command->addCarsor(new OkuCommand(m_scene));
    command->addCarsor(new SetumeiCommand(m_scene));
    return command;
    
}

void ToutekiItem::getSetumei(std::string &str){
    str = "投擲アイテムだ。まだ未実装だ。";
}