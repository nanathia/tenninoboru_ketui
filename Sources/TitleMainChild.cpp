//
//  TitleMainChild.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/07.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "TitleMainChild.h"
#include "SKMusicManager.h"
#include "SKSoundManager.h"
#include "SKTitle.h"
#include "SKSelectWindow.h"
#include "Globals.h"
#include "GameMain.h"
#include "SKFont.h"
#include "JASpeakWindow.h"
#include "SKTitleChild.h"
#include "SKTitleMainMenuState.h"
#include "TitleHajimekara.h"

namespace titleScene{
    
    MainChild::MainChild(TitleMain* user):
    m_animationTime(0),
    m_user(user){
    }
    MainChild::~MainChild(){
    }
    
    MainInter::MainInter(TitleMain* user):
    MainChild(user){
        gTitleScene->getMusicMan()->get(MusicName_Main)->play();
    }
    MainInter::~MainInter(){
    }
    MainChild* MainInter::update(TitleMain* parent, GMInput* input, double deltaTime){
        MainChild* next = this;
        m_animationTime += deltaTime/3;
        if(m_animationTime >= 1){
            next = new MainMenu(m_user);
        }
        return next;
    }
    void MainInter::draw(TitleMain* parent, GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1-m_animationTime;
        s->draw(0, GMRect2D(0, SCREEN_SIZE), white);
    }
    
    MainMenu::MainMenu(TitleMain* user):
    MainChild(user),
    m_state(0),
    m_nextBranch(MainOuter::branch_none)
    {
        selectWindow::Element* elements[] = {
            new selectWindow::Element(user->getSelectWindow()),
            new selectWindow::Element(user->getSelectWindow()),
            new selectWindow::Element(user->getSelectWindow()),
            new selectWindow::Element(user->getSelectWindow()),
        };
        elements[0]->setLabel("初めから旅する");
        elements[1]->setLabel("旅を続ける");
        elements[2]->setLabel("ゲーム詳細");
        elements[3]->setLabel("おまけ");
        int size = (int)sizeof(elements) / sizeof(elements[0]);
        for(int i = 0; i < size; i++){
            elements[i]->setRect(GMRect2D(500, 500-(i*50), 400, 50));
            user->getSelectWindow()->addElement(elements[i]);
        }
        selectWindow::Carsor* carsor = new selectWindow::Carsor(user->getSelectWindow());
        user->getSelectWindow()->setCarsor(carsor);
        elements[0]->setCarsor(carsor);
        m_state = new mainmenu::MenuState(this);
    }
    MainMenu::~MainMenu(){
    }
    MainChild* MainMenu::update(TitleMain* parent, GMInput* input, double deltaTime){
        MainChild* next = this;
        m_state->update(input, deltaTime);
        JASpeakWindow::Window* spk_win = getUser()->getSpeakWindow();
        spk_win->update(input, deltaTime);
        if(m_nextBranch != MainOuter::branch_none){
            next = new MainOuter(m_user, m_nextBranch);
        }
        return next;
    }
    void MainMenu::draw(TitleMain* parent, GMSpriteBatch* s){
        m_user->getSelectWindow()->draw(s);
        m_state->draw(s);
        JASpeakWindow::Window* spk_win = getUser()->getSpeakWindow();
        spk_win->draw(s);
    }
    TitleMain* MainMenu::getUser(){
        return m_user;
    }
    void MainMenu::goNext(MainOuter::OuterBranch branch){
        m_nextBranch = branch;
    }
    
    MainOuter::MainOuter(TitleMain* user, MainOuter::OuterBranch branch):
    MainChild(user),
    m_branch(branch){
    }
    MainOuter::~MainOuter(){
    }
    MainChild* MainOuter::update(TitleMain* parent, GMInput* input, double deltaTime){
        MainChild* next = this;
        m_animationTime += deltaTime/4;
        if(m_animationTime >= 1){
            if(m_branch == branch_newGame){
                gGameInst->ChangeScene("play");
            }
        }
        return next;
    }
    void MainOuter::draw(TitleMain* parent, GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = m_animationTime;
        s->draw(0, GMRect2D(0, SCREEN_SIZE), white);
    }
    
}