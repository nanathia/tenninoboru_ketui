
#include "SKUdewa.h"
#include "SaKumas_includes.h"
#include "ItemCommandInfo.h"

UdewaItem::UdewaItem():
EpuipmentItem(){
    this->setName("腕輪");
    this->m_itemNum = 2;
}

UdewaItem::~UdewaItem(){
    
}


CarsorSelectReAction* UdewaItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo();
    command->addCarsor(new SoubiCommand());
    command->addCarsor(new NageruCommand());
    command->addCarsor(new OkuCommand());
    command->addCarsor(new SetumeiCommand());
    return command;
    
}

void UdewaItem::soubi(){
    gPlayScene->getDungeonScene()->getPlayer()->soubiUdewa_1(this);
}

void UdewaItem::hazusu(){
    gPlayScene->getDungeonScene()->getPlayer()->soubiUdewa_2(0);
}

void UdewaItem::getSetumei(std::string &strIn){
    strIn = "未実装の説明";
}