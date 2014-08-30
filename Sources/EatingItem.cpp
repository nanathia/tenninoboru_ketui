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

EatingItem::EatingItem(SKDungeonScene* scene):
UsingItem(scene)
{
    this->setName("食べ物");
    this->m_itemNum = 6;
}

void EatingItem::use(){
}

CarsorSelectReAction* EatingItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo(m_scene);
    command->addCarsor(new TaberuCommand(m_scene));
    command->addCarsor(new NageruCommand(m_scene));
    command->addCarsor(new OkuCommand(m_scene));
    command->addCarsor(new SetumeiCommand(m_scene));
    return command;
    
}

void EatingItem::getSetumei(std::string& str){
    str = "食料だ。まだ未実装である。";
}