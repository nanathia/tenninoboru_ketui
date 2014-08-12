//
//  TitleHajimekara.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "TitleHajimekara.h"
#include "SKTitleMainMenuState.h"
#include "JASpeakWindow.h"
#include "SKSelectWindow.h"

namespace titleScene{
    namespace mainmenu{
        
        HajimekaraState::HajimekaraState(Hajimekara* user):
        m_child(0){
            m_child = new HajimekaraYes(user);
        }
        HajimekaraState::~HajimekaraState(){
            delete m_child;
            m_child = 0;
        }
        
        void HajimekaraState::update(GMInput* input, double deltaTime){
            HajimekaraStateChild* nextChild = m_child->update(input, deltaTime);
            if(nextChild != m_child){
                delete m_child;
                m_child = nextChild;
            }
        }
        void HajimekaraState::draw(GMSpriteBatch* s){
            m_child->draw(s);
        };
        
        HajimekaraStateChild::HajimekaraStateChild(Hajimekara*user):
        m_user(user){
        }
        HajimekaraStateChild::~HajimekaraStateChild(){
        }
        
        HajimekaraLeady::HajimekaraLeady(Hajimekara* user):
        HajimekaraStateChild(user){
        }
        HajimekaraLeady::~HajimekaraLeady(){
        }
        HajimekaraStateChild* HajimekaraLeady::update(GMInput* input, double deltaTime){
            HajimekaraStateChild* next = this;
            selectWindow::Element* pushElem = m_user->getSel_Win()->update(input, deltaTime);
            if(pushElem){
                if(pushElem->getLabel() == "うん"){
                    next = new HajimekaraYes(m_user);
                }else if(pushElem->getLabel() == "やめとく"){
                    next = new HajimekaraNone(m_user);
                }else if(pushElem->getLabel() == "誰？"){
                    next = new HajimekaraDare(m_user);
                }
            }
            return next;
        }
        void HajimekaraLeady::draw(GMSpriteBatch* s){
        };
        
        HajimekaraYes::HajimekaraYes(Hajimekara* user):
        HajimekaraStateChild(user){
        }
        HajimekaraYes::~HajimekaraYes(){
        }
        HajimekaraStateChild* HajimekaraYes::update(GMInput* input, double deltaTime){
            HajimekaraStateChild* next = this;
            
            return next;
        }
        void HajimekaraYes::draw(GMSpriteBatch* s){
        };
        
        HajimekaraNone::HajimekaraNone(Hajimekara* user):
        HajimekaraStateChild(user){
        }
        HajimekaraNone::~HajimekaraNone(){
        }
        HajimekaraStateChild* HajimekaraNone::update(GMInput* input, double deltaTime){
            HajimekaraStateChild* next = this;
            return next;
        }
        void HajimekaraNone::draw(GMSpriteBatch* s){
        };
        
        HajimekaraDare::HajimekaraDare(Hajimekara* user):
        HajimekaraStateChild(user){
        }
        HajimekaraDare::~HajimekaraDare(){
        }
        HajimekaraStateChild* HajimekaraDare::update(GMInput* input, double deltaTime){
            HajimekaraStateChild* next = this;
            return next;
        }
        void HajimekaraDare::draw(GMSpriteBatch* s){
        };
        
        HajimekaraOuter::HajimekaraOuter(Hajimekara* user):
        HajimekaraStateChild(user){
        }
        HajimekaraOuter::~HajimekaraOuter(){
        }
        HajimekaraStateChild* HajimekaraOuter::update(GMInput* input, double deltaTime){
            HajimekaraStateChild* next = this;
            return next;
        }
        void HajimekaraOuter::draw(GMSpriteBatch* s){
        };
        
        
    }
}