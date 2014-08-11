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

namespace titleScene{
    
    MainChild::MainChild():
    m_animationTime(0){
    }
    MainChild::~MainChild(){
    }
    
    MainInter::MainInter():
    MainChild(){
        gTitleScene->getMusicMan()->get(MusicName_Main)->play();
    }
    MainInter::~MainInter(){
    }
    MainChild* MainInter::update(TitleMain* parent, GMInput* input, double deltaTime){
        MainChild* next = this;
        m_animationTime += deltaTime/3;
        if(m_animationTime >= 1){
            next = new MainMenu;
        }
        return next;
    }
    void MainInter::draw(TitleMain* parent, GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1-m_animationTime;
        s->draw(0, GMRect2D(0, SCREEN_SIZE), white);
    }
    
    MainMenu::MainMenu():
    MainChild(),
    m_slectWindow(0),
    m_speakWindow(0)
    {
        m_slectWindow = new selectWindow::Window;
        m_speakWindow = new JASpeakWindow::Window;
        selectWindow::Element* elements[] = {
            new selectWindow::Element(m_slectWindow),
            new selectWindow::Element(m_slectWindow),
            new selectWindow::Element(m_slectWindow),
            new selectWindow::Element(m_slectWindow),
        };
        elements[0]->setLabel("初めから旅する");
        elements[1]->setLabel("旅を続ける");
        elements[2]->setLabel("ゲーム詳細");
        elements[3]->setLabel("おまけ");
        int size = (int)sizeof(elements) / sizeof(elements[0]);
        for(int i = 0; i < size; i++){
            elements[i]->setRect(GMRect2D(500, 500-(i*50), 400, 50));
            m_slectWindow->addElement(elements[i]);
        }
        selectWindow::Carsor* carsor = new selectWindow::Carsor(m_slectWindow);
        m_slectWindow->setCarsor(carsor);
        elements[0]->setCarsor(carsor);
        m_speakWindow->addString("ワンパンマン。漸プレイステーション。漸コリジョンコレダー。");
        m_speakWindow->addString("そして誰もいなくなった。漸そして誰も要らなくなった。漸そして誰も見なくなった。");
        m_speakWindow->addString("今日から私は転校生。漸さて、どうしようか。漸まずは、自己紹介をしよう。");
        m_speakWindow->addString("扇風機が回りっぱなしだ。漸結構頭こんがらがってきた。漸そしてカレーをいっぱい買ったのよ。");
    }
    MainMenu::~MainMenu(){
    }
    MainChild* MainMenu::update(TitleMain* parent, GMInput* input, double deltaTime){
        MainChild* next = this;
        selectWindow::Element* selected = m_slectWindow->update(input, deltaTime);
        m_speakWindow->update(input, deltaTime);
        if(selected){
            if(selected->getLabel() == "初めから旅する"){
                next = new MainOuter(MainOuter::branch_newGame);
            }
        }
        return next;
    }
    void MainMenu::draw(TitleMain* parent, GMSpriteBatch* s){
        m_speakWindow->draw(s);
        m_slectWindow->draw(s);
        GMColor gold = GMColor::Gold;
        gold.a = 0.6;
        sizurus_fonts::SKFont::drawCharacter("撃", s, GMRect2D(400, 400, 100, 100), gold, 0.5, GMVector2D(0.5, 0.5));
    }
    
    MainOuter::MainOuter(MainOuter::OuterBranch branch):
    MainChild(),
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