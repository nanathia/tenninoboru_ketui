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
#include "TitleHajimekara.h"

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
        StateChild(user),
        m_sel_win(0),
        m_currentselect(none){
            selectWindow::Window* sel_win = m_user->getUser()->getSelectWindow();
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            spk_win->addString("はじめからゲームを開始するのね。");
            spk_win->addString("このゲームは、とある少女、漸サクマの悲劇と努力の物語よ。");
            spk_win->addString("始めていいかしら？", saisyokarahajimeruka_);
        }
        Hajimekara::~Hajimekara(){
            if(m_sel_win) delete m_sel_win;
            m_sel_win = 0;
        }
        StateChild* Hajimekara::update(GMInput* input, double deltaTime){
            StateChild* next = this;
            JASpeakWindow::Window* spk_win = m_user->getUser()->getSpeakWindow();
            
            if(m_sel_win){
                selectWindow::Element* pushElem = 0;
                if(spk_win->getKey() == saisyokarahajimeruka_){
                    pushElem = m_sel_win->update(input, deltaTime);
                    if(pushElem){
                        if(pushElem->getLabel() == "うん"){
                            spk_win->addString("じゃあ、君をゲーム世界に誘うわ。");
                            spk_win->addString("えーと少し待ってね。");
                            spk_win->addString("・・・・・・・・・・・・・");
                            spk_win->addString("・・・・・・・・・・・・・・漸・・・・・・・・・・・・・・");
                            spk_win->addString("準備出来たわ。");
                            spk_win->addString("画面変わるわよー。", goToGame_begin);
                        }else if(pushElem->getLabel() == "やめとく"){
                            spk_win->addString("あら、やめるの？");
                            spk_win->addString("分かったわ。漸メイン選択に戻るわね。", backMainSelect);
                        }else if(pushElem->getLabel() == "誰？"){
                            spk_win->addString("私？");
                            spk_win->addString("んー。後で教えてあげるから。");
                            spk_win->addString("私が誰か知りたいなら、漸今は「うん」押したらいいと思うわ。", saisyokarahajimeruka_);
                        }
                        delete m_sel_win;
                        m_sel_win = 0;
                        spk_win->setKey(-1);
                    }
                }
                
            }
            
            int push = spk_win->getKey();
            if(push == saisyokarahajimeruka_ && !m_sel_win){
                m_sel_win = new selectWindow::Window;
                selectWindow::Element* elements[] = {
                    new selectWindow::Element(m_sel_win),
                    new selectWindow::Element(m_sel_win),
                    new selectWindow::Element(m_sel_win),
                };
                elements[0]->setLabel("うん");
                elements[1]->setLabel("やめとく");
                elements[2]->setLabel("誰？");
                int size = (int)sizeof(elements) / sizeof(elements[0]);
                for(int i = 0; i < size; i++){
                    elements[i]->setRect(GMRect2D(200, 350-(i*50), 200, 50));
                    m_sel_win->addElement(elements[i]);
                }
                selectWindow::Carsor* carsor = new selectWindow::Carsor(m_sel_win);
                elements[0]->setCarsor(carsor);
                m_sel_win->setCarsor(carsor);
            }else if(push == backMainSelect && input->isKeyDownTriggered(GMKeyMaskZ | GMKeyMaskSpace | GMKeyMaskReturn)){
                next = new MainCommandSelect(m_user);
                spk_win->setKey(-1);
            }else if(push == backThisSelect && input->isKeyDownTriggered(GMKeyMaskZ | GMKeyMaskSpace | GMKeyMaskReturn)){
                spk_win->setKey(saisyokarahajimeruka_);
            }else if(push == goToGame_begin && input->isKeyDownTriggered(GMKeyMaskZ | GMKeyMaskSpace | GMKeyMaskReturn)){
                m_user->goNext(MainOuter::branch_newGame);
            }
            
            return next;
        }
        void Hajimekara::draw(GMSpriteBatch* s){
            if(m_sel_win) m_sel_win->draw(s);
        };
        selectWindow::Window* Hajimekara::getSel_Win(){
            return m_sel_win;
        }
        
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