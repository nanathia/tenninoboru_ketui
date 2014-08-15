//
//  StartDemoChild.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SKStartDemo.h"
#include "SKMusicManager.h"
#include "SKSoundManager.h"
#include "StartDemoChild.h"
#include "StartDemoMainState.h"
#include "GameMain.h"
#include "Globals.h"
#include "SKTextureManager.h"


namespace startdemo{
    
    StartDemoState::StartDemoState(SKStartDemo* user):
    m_child(0){
        m_child = new StartDemoInter(user);
    }
    StartDemoState::~StartDemoState(){
        delete m_child;
        m_child = 0;
    }
    void StartDemoState::update(GMInput* input, double deltaTime){
        StartDemoChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void StartDemoState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    
    StartDemoChild::StartDemoChild(SKStartDemo*user):
    m_user(user){
    }
    StartDemoChild::~StartDemoChild(){
    }
    
    StartDemoInter::StartDemoInter(SKStartDemo* user):
    StartDemoChild(user),
    m_time(0){
    }
    StartDemoInter::~StartDemoInter(){
    }
    StartDemoChild* StartDemoInter::update(GMInput* input, double deltaTime){
        StartDemoChild* next = this;
        m_time += deltaTime / 5;
        if(m_time >= 1){
            next = new StartDemoMain(m_user);
        }
        return next;
    }
    void StartDemoInter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1-m_time;
        s->draw(gGameInst->getTexMan()->get(TextureName_Fill), GMRect2D(0, SCREEN_SIZE), white);
    };
    
    StartDemoOuter::StartDemoOuter(SKStartDemo* user):
    StartDemoChild(user),
    m_time(0){
    }
    StartDemoOuter::~StartDemoOuter(){
    }
    StartDemoChild* StartDemoOuter::update(GMInput* input, double deltaTime){
        StartDemoChild* next = this;
        m_time += deltaTime / 5;
        if(m_time >= 1){
            next = new StartDemoMain(m_user);
        }
        return next;
    }
    void StartDemoOuter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = m_time;
        s->fill(GMRect2D(0, SCREEN_SIZE), white);
    };
    
    StartDemoMain::StartDemoMain(SKStartDemo* user):
    StartDemoChild(user),
    m_state(0){
        m_sel_win = new selectWindow::Window;
        m_spk_win = new JASpeakWindow::Window;
        m_spk_win->addString("画面切り替わったわね。");
        m_spk_win->addString("まずは私の自己紹介からしようかしらね。");
        m_spk_win->addString("私の名前は、時空亜空。", nextScene);
        m_spk_win->addString("様々な時間と空間を管理しているわ。");
        m_spk_win->addString("時空亜空っていうこの名前は、漸いつだったか、「時空亜空を渡る人」漸って意味を込めて付けられた名前よ。");
        m_spk_win->addString("私が、この世界をプレイするあなたの漸「メタい」パートナーよ。よろしく　笑");
        m_spk_win->addString("物語には、私は関係しないけど、漸この声をかけてあなたを導くわ。");
        m_spk_win->addString("さて、今から始めるゲームは漸「天に昇る決意」。");
        m_spk_win->addString("どんなゲームか。");
        m_spk_win->addString("今から説明するわね。", nextScene);
        m_spk_win->addString("テスト", nextScene);
        m_spk_win->addString("テスト２", nextScene);
        m_spk_win->addString("テスト３", nextScene);
        m_spk_win->addString("テスト４", nextScene);
        m_spk_win->addString("テスト５", nextScene);
        m_spk_win->addString("テスト６", nextScene);
        m_spk_win->addString("テスト７", nextScene);
        m_spk_win->addString("テスト９", nextScene);
        m_spk_win->addString("テスト１０", nextScene);
        m_spk_win->addString("テスト１１", nextScene);
        m_spk_win->addString("テスト１２", nextScene);
        m_spk_win->addString("テスト１３", nextScene);
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        m_spk_win->addString("");
        GMVector2D s;
        s = SCREEN_SIZE;
        GMColor white = GMColor::White;
        white.a = 0.4;
        m_spk_win->setColor(white);
        m_user->getMusicMan()->get(SKStartDemo::musicName_MainBGM)->setVolume(0.5);
        m_user->getMusicMan()->get(SKStartDemo::musicName_MainBGM)->play();
        m_state = new startdemomain::StartDemoState(this);
    }
    StartDemoMain::~StartDemoMain(){
    }
    StartDemoChild* StartDemoMain::update(GMInput* input, double deltaTime){
        StartDemoChild* next = this;
        m_state->update(input, deltaTime);
        return next;
    }
    void StartDemoMain::draw(GMSpriteBatch* s){
        m_state->draw(s);
        m_spk_win->draw(s);
    };
    JASpeakWindow::Window* StartDemoMain::getSpkWin(){
        return m_spk_win;
    }
    
    
}
