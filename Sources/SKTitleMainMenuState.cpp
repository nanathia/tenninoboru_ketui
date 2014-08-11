//
//  SKTitleMainMenuState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/11.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKTitleMainMenuState.h"
#include "SKTitleChild.h"
#include "TitleMainChild.h"
#include "SKSelectWindow.h"
#include "JASpeakWindow.h"

namespace titleScene{
    namespace mainmenu{
        
        MenuState::MenuState(MainMenu* user):
        m_child(0){
            m_child = new MainCommandSelect(user);
        }
        MenuState::~MenuState(){
            delete m_child;
            m_child = 0;
        }
        void MenuState::update(GMInput* input, double deltaTime){
            StateChild* nextChild = m_child->update(input, deltaTime);
            if(nextChild != m_child){
                delete m_child;
                m_child = nextChild;
            }
        }
        void MenuState::draw(GMSpriteBatch* s){
            m_child->draw(s);
        };
        
        StateChild::StateChild(MainMenu*user):
        m_user(user){
        }
        StateChild::~StateChild(){
        }
        
        MainCommandSelect::MainCommandSelect(MainMenu* user):
        StateChild(user){
        }
        MainCommandSelect::~MainCommandSelect(){
        }
        StateChild* MainCommandSelect::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            selectWindow::Element* sel_elem = sel_win->update(input, deltaTime);
            if(sel_elem){
                if(sel_elem->getLabel() == "初めから旅する"){
                    next = new Hajimekara(m_user);
                }
            }
            return next;
        }
        void MainCommandSelect::draw(GMSpriteBatch* s){
        };
        
        Hajimekara::Hajimekara(MainMenu* user):
        StateChild(user){
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            spk_win->addString("はじめからゲームを開始するのね。");
            spk_win->addString("このゲームは、とある少女、漸サクマの悲劇と努力の物語よ。漸始めていいかしら？");
        }
        Hajimekara::~Hajimekara(){
        }
        StateChild* Hajimekara::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            spk_win->update(input, deltaTime);
            return next;
        }
        void Hajimekara::draw(GMSpriteBatch* s){
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            spk_win->draw(s);
        };
        
        Tudukikara::Tudukikara(MainMenu* user):
        StateChild(user){
        }
        Tudukikara::~Tudukikara(){
        }
        StateChild* Tudukikara::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            return next;
        }
        void Tudukikara::draw(GMSpriteBatch* s){
        };
        
        Settei::Settei(MainMenu* user):
        StateChild(user){
        }
        Settei::~Settei(){
        }
        StateChild* Settei::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            return next;
        }
        void Settei::draw(GMSpriteBatch* s){
        };
        
        Omake::Omake(MainMenu* user):
        StateChild(user){
        }
        Omake::~Omake(){
        }
        StateChild* Omake::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            return next;
        }
        void Omake::draw(GMSpriteBatch* s){
        };
        
        Chancel::Chancel(MainMenu* user):
        StateChild(user){
        }
        Chancel::~Chancel(){
        }
        StateChild* Chancel::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            return next;
        }
        void Chancel::draw(GMSpriteBatch* s){
        };
        
    }
}