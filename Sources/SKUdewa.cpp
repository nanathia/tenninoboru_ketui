
#include "SKUdewa.h"
#include "SaKumas_includes.h"
#include "ItemCommandInfo.h"

UdewaItem::UdewaItem(SKDungeonScene* scene):
EpuipmentItem(scene){
    this->setName("腕輪");
    this->m_itemNum = 2;
}

UdewaItem::~UdewaItem(){
    
}


CarsorSelectReAction* UdewaItem::getSelectReaction(){
    CommandInfo* command = new CommandInfo(m_scene);
    command->addCarsor(new SoubiCommand(m_scene));
    command->addCarsor(new NageruCommand(m_scene));
    command->addCarsor(new OkuCommand(m_scene));
    command->addCarsor(new SetumeiCommand(m_scene));
    return command;
    
}

void UdewaItem::soubi(){
    m_scene->getPlayer()->soubiUdewa_1(this);
}

void UdewaItem::hazusu(){
    m_scene->getPlayer()->soubiUdewa_2(0);
}

void UdewaItem::getSetumei(std::string &strIn){
    strIn = "未実装の説明";
}