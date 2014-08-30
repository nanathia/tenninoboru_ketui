//
//  NenryouItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "NenryouItem.h"

NenryouItem::NenryouItem(SKDungeonScene* scene):
UsingItem(scene)
{
    this->setName("燃料");
    this->m_itemNum = 3;
}

NenryouItem::~NenryouItem(){
    
}

void NenryouItem::use(){
    
}

void NenryouItem::getSetumei(std::string &str){
    str = "燃料アイテム。未実装だ。";
}

CarsorSelectReAction* NenryouItem::getSelectReaction(){
    // TODO:燃料アイテムコマンドの実装
    CommandInfo* com = new CommandInfo(m_scene);
//    com->addCarsor(new SoubiCommand(m_scene));
    com->addCarsor(new NageruCommand(m_scene));
    com->addCarsor(new OkuCommand(m_scene));
    com->addCarsor(new SetumeiCommand(m_scene));
    return com;
}