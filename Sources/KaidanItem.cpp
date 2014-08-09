//
//  KaidanItem.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "KaidanItem.h"
#include "ItemCommandInfo.h"

KaidanItem::KaidanItem():
SKItem()
{
    
}

KaidanItem::~KaidanItem(){
    
}

void KaidanItem::noru(){
    
}

void KaidanItem::getSetumei(std::string& str){
    
}

CarsorSelectReAction* KaidanItem::getSelectReaction(){
    CommandInfo* com = new CommandInfo();
    return com;
}