//
//  KusaItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "KusaItem.h"
#include "ItemCommandInfo.h"

KusaItem::KusaItem(SKDungeonScene* scene):
UsingItem(scene){
    this->setName("草");
    this->m_itemNum = 4;
}

void KusaItem::use(){
    
}

CarsorSelectReAction* KusaItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo(m_scene);
    command->addCarsor(new NomuCommand(m_scene));
    command->addCarsor(new NageruCommand(m_scene));
    command->addCarsor(new OkuCommand(m_scene));
    command->addCarsor(new SetumeiCommand(m_scene));
    return command;
    
}

void KusaItem::getSetumei(std::string &str){
    str = "草だ。まだ未実装だ。";
}