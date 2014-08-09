//
//  MakimonoItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "MakimonoItem.h"

MakimonoItem::MakimonoItem():
UsingItem(){
    this->setName("巻物");
    this->m_itemNum = 5;
}

MakimonoItem::~MakimonoItem(){
    
}

void MakimonoItem::use(){
    
}

void MakimonoItem::getSetumei(std::string &str){
    str = "巻物アイテムだ。未実装だ。";
}

CarsorSelectReAction* MakimonoItem::getSelectReaction(){
    // TODO: 巻物のセレクトの実装
    CommandInfo* com = new CommandInfo();
    com->addCarsor(new YomuCommand());
    com->addCarsor(new NageruCommand());
    com->addCarsor(new OkuCommand());
    com->addCarsor(new SetumeiCommand());
    return com;
}