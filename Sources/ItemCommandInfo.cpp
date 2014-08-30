//
//  ItemCommandInfo.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "ItemCommandInfo.h"
#include "SaKumas_includes.h"
#include "PlayerPorch.h"
#include "SKDrawFont.h"
#include "SKDungeonScene.h"
#include <sstream>
#define pp (m_scene->getPlayer()->getPorch())

CommandInfo::CommandInfo(SKDungeonScene* scene):
m_scene(scene),
m_child(0),
m_carsor(0)
{
    
}

CommandInfo::~CommandInfo(){
    if(m_child) delete m_child;
    if(!m_carsors.empty()){
        auto it = m_carsors.begin();
        while(it != m_carsors.end()){
            delete *it;
            *it = 0;
            it++;
        }
    }
    m_child = 0;
    m_carsor = 0;
}

CarsorInfo::CarsorInfo(SKDungeonScene* scene):
m_scene(scene){
    
}

CarsorInfo::~CarsorInfo(){
    
}

void CarsorInfo::_draw(const GMVector2D& pos, const std::string &str, GMSpriteBatch* s){
    SKDrawFont::drawString(str, GMVector2D(40, 40), pos, 600, s);
}

CarsorSelectReAction::~CarsorSelectReAction(){
}

const char* CommandInfo::update(GMInput* input, double deltaTime, SKItem* item){
    const char* next = 0;
    
    if(m_child){
        if(const char* _str = m_child->update(input, deltaTime, item)){
            std::string str = _str;
            if(str == "close"){
                delete m_child;
                m_child = 0;
            }
        }
        return next;
    }
    
    if(input->isKeyDownTriggered(GMKeyMaskDown)){
        m_carsor += 1;
        if(m_carsor >= 20){
            m_carsor = 0;
        }
    }
    else if(input->isKeyDownTriggered(GMKeyMaskUp)){
        m_carsor -= 1;
        if(m_carsor < 0){
            m_carsor = 19;
        }
    }
    else if(input->isKeyDownTriggered(GMKeyMaskRight)){
        m_carsor += 10;
        if(m_carsor >= 20){
            m_carsor -= 20;
        }
    }
    else if(input->isKeyDownTriggered(GMKeyMaskLeft)){
        m_carsor -= 10;
        if(m_carsor < 0){
            m_carsor += 20;
        }
    }
    else if(input->isKeyDownTriggered(GMKeyMaskZ)){
        auto c_it = m_carsors.begin();
        for(int i = 0; i < m_carsor; i++){
            c_it++;
        }
        (*c_it)->choice(input, deltaTime, item);
    }
    else if(input->isKeyDownTriggered(GMKeyMaskX)){
        next = "close";
    }
    
    return next;
}

void CommandInfo::draw(GMSpriteBatch* s){
    if(m_child){
        m_child->draw(s);
    }else{
        
        auto it = m_carsors.begin();
        if(m_carsors.empty()) return;
        int drawPosY = 500;
        int count = 0;
        while(it != m_carsors.end()){
            if(count == m_carsor){
                GMColor db = GMColor::Silver;
                db.a = 0.5;
                s->draw(0, GMRect2D(350, drawPosY, 600, 40), db);
            }
            (*it)->draw(GMVector2D(350, drawPosY), s);
            drawPosY -= 40;
            it++;
            count++;
        }
    }
}

SoubiCommand::SoubiCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* SoubiCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    dynamic_cast<EpuipmentItem*>(item)->soubi();
    return 0;
}
void SoubiCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "装備", s);
}

YomuCommand::YomuCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* YomuCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void YomuCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "読む", s);
}

TaberuCommand::TaberuCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* TaberuCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void TaberuCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "食べる", s);
}

NakawomiruCommand::NakawomiruCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* NakawomiruCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void NakawomiruCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "中を見る", s);
}

SuteruCommand::SuteruCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* SuteruCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void SuteruCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "捨てる", s);
}

NageruCommand::NageruCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* NageruCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void NageruCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "投げる", s);
}

NomuCommand::NomuCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* NomuCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void NomuCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "飲む", s);
}

HirouCommand::HirouCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* HirouCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void HirouCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "拾う", s);
}

KoukanCommand::KoukanCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* KoukanCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void KoukanCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "交換", s);
}

SetumeiCommand::SetumeiCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* SetumeiCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void SetumeiCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "説明", s);
}

OkuCommand::OkuCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* OkuCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    if(m_scene->getPlayer()->getMass()->getItem()){
        m_scene->getUI()->textInput("ここには置けない");
        m_scene->getPlayer()->endItemSelect();
    }else{
        std::ostringstream oss;
        oss << item->getName() << "を置いた。";
        m_scene->getUI()->textInput(oss.str());
        pp->getItems().remove(item);
        m_scene->getPlayer()->getMass()->setItem(item);
        item->setMass(m_scene->getPlayer()->getMass());
        m_scene->getPlayer()->endItemSelect();
    }
    return 0;
}
void OkuCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "置く", s);
}

KakuCommand::KakuCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* KakuCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void KakuCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "書く", s);
}

UtuCommand::UtuCommand(SKDungeonScene* scene):
CarsorInfo(scene){
}
CarsorSelectReAction* UtuCommand::choice(GMInput* input, double deltaTime, SKItem* item){
    return 0;
}
void UtuCommand::draw(const GMVector2D &pos, GMSpriteBatch *s){
    this->_draw(pos, "撃つ", s);
}

void CommandInfo::addCarsor(CarsorInfo* carsor){
    m_carsors.push_back(carsor);
}
