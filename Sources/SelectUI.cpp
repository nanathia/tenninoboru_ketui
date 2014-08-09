//
//  SelectUI.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SelectUI.h"
#include "SaKumas_includes.h"
#include "PlayerPorch.h"
#include "SKDrawFont.h"
#include <cmath>


SelectUI::SelectUI():
m_child(0)
{
    m_isShow = false;
}

SelectUI::~SelectUI(){
    delete m_child;
    m_child = 0;
}

void SelectUI::update(GMInput *input, double deltaTime){
    // TODO: セレクトUIの実装
    if(m_isShow){
        if(m_child){
            auto it = gPlayScene->getPlayer()->getPorch()->getItems().begin();
            for(int i = 0; i < m_carsor; i++){
                it++;
            }
            const char* str = m_child->update(input, deltaTime, *it);
            if(str){
                std::string s = str;
                if(s == "close"){
                    if(m_child) delete m_child;
                    m_child = 0;
                }
            }
            return;
        }else{
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
                auto& pp = gPlayScene->getPlayer()->getPorch()->getItems();
                auto it = pp.begin();
                for(int i = 0; i < m_carsor; i++){
                    it++;
                }
                m_child = (*it)->getSelectReaction();
                
            }
        }
    }
    
}

void SelectUI::draw(GMSpriteBatch *s) const{
    if(m_isShow){
        PlayerPorch* pp = gPlayScene->getPlayer()->getPorch();
        GMColor c1 = GMColor::DarkBlue;
        c1.a = 0.8;
        s->draw(0, GMRect2D(200, 150, 600, 400), c1);
        if(pp->getItems().empty()) return;
        auto it = pp->getItems().begin();
        int page = m_carsor/10;
        int carsor = m_carsor % 10;
        int start = page*10;
        int pageEnd = (page+1)*10;
        int size = pp->getItems().size() < pageEnd ? static_cast<int>(pp->getItems().size()): pageEnd;
        for(int i = 0; i < start; i++){
            it++;
        }
        GMVector2D charSize(40,40);
        GMVector2D strPos(200, 550);
        GMVector2D strWidth(500);
        for(int i = 0; i < size-start; i++){
            if(i == carsor){
                GMColor c = GMColor::Honeydew;
                c.a = 0.3;
                s->draw(0, GMRect2D(200, 550-(i*40), 600, -40), c);
            }
            SKItem* item = *it;
            strPos.y -= 40;
            SKDrawFont::drawString(item->getName(), charSize, strPos, strWidth, s);
            it++;
        }
        if(m_child){
            GMColor bk = GMColor::Black;
            bk.a = 0.7;
            s->draw(0, 0, GMRect2D(0, SCREEN_SIZE), bk);
            m_child->draw(s);
        }
    }
}

void SelectUI::UiOn(){
    m_isShow = true;
}

void SelectUI::UiOff(){
    m_isShow = false;
    m_carsor = 0;
    delete m_child;
    m_child = 0;
}

bool SelectUI::isUiOpened(){
    return m_isShow;
}
