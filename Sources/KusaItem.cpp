//
//  KusaItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "KusaItem.h"
#include "ItemCommandInfo.h"

KusaItem::KusaItem(){
    this->setName("草");
    this->m_itemNum = 4;
}

void KusaItem::use(){
    
}

CarsorSelectReAction* KusaItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo();
    command->addCarsor(new NomuCommand());
    command->addCarsor(new NageruCommand());
    command->addCarsor(new OkuCommand());
    command->addCarsor(new SetumeiCommand());
    return command;
    
}

void KusaItem::getSetumei(std::string &str){
    str = "草だ。まだ未実装だ。";
}