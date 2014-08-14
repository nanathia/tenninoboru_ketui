//
//  StartDemoMainState.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/14.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "GameMain.h"
#include "StartDemoMainState.h"
#include "StartDemoChild.h"
#include "SKTextureManager.h"
#include "SKStartDemo.h"

namespace startdemo{
namespace startdemomain{
    
    StartDemoState::StartDemoState(StartDemoMain* user):
    m_child(0){
        m_child = new TextOnly(user);
    }
    StartDemoState::~StartDemoState(){
        delete m_child;
        m_child = 0;
    }
    void StartDemoState::update(GMInput* input, double deltaTime){
        StateChild* nextChild = m_child->update(input, deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    void StartDemoState::draw(GMSpriteBatch* s){
        m_child->draw(s);
    };
    void StartDemoState::goNext(){
        m_child->goNext();
    }
    
    StateChild::StateChild(StartDemoMain* user):
    m_user(user),
    m_isNext(0){
    }
    StateChild::~StateChild(){
    }
    void StateChild::goNext(){
        m_isNext = true;
    }
    bool StateChild::isVisible(){
        return true;
    }
    
    TextOnly::TextOnly(StartDemoMain* user):
    StateChild(user){
    }
    TextOnly::~TextOnly(){
    }
    StateChild* TextOnly::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        m_user->getSpkWin()->update(input, deltaTime);
        if(m_isNext || ((m_user->getSpkWin()->getKey() == StartDemoMain::nextScene) && input->isKeyDownTriggered(GMKeyMaskSpace|GMKeyMaskZ|GMKeyMaskReturn))){
            next = new JikuakuuInter(m_user);
        }
        return next;
    }
    void TextOnly::draw(GMSpriteBatch* s){
    };
    
    TextOnly3::TextOnly3(StartDemoMain* user):
    StateChild(user){
    }
    TextOnly3::~TextOnly3(){
    }
    StateChild* TextOnly3::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new JikuakuuInter(m_user);
        }
        return next;
    }
    void TextOnly3::draw(GMSpriteBatch* s){
    };
    
    TextOnly4::TextOnly4(StartDemoMain* user):
    StateChild(user){
    }
    TextOnly4::~TextOnly4(){
    }
    StateChild* TextOnly4::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new AllOuter(m_user);
        }
        return next;
    }
    void TextOnly4::draw(GMSpriteBatch* s){
    };
    
    JikuakuuInter::JikuakuuInter(StartDemoMain* user):
    StateChild(user),
    m_time(0){
    }
    JikuakuuInter::~JikuakuuInter(){
    }
    StateChild* JikuakuuInter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        m_time += deltaTime/4;
        if(m_time >= 1){
            next = new JikuakuuImage(m_user);
        }
        if(m_isNext){
            next = new JikuakuuImage(m_user);
        }
        return next;
    }
//    texName_Tetorapeddora,
//    texName_sakuma,
//    texName_sakuma_c,
//    texName_jiikuuakuu,
    void JikuakuuInter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = m_time;
        GMColor white_quota = GMColor::White;
        white_quota.a = m_time/3;
        s->fill(GMRect2D(0, SCREEN_SIZE), white_quota);
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_jiikuuakuu), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool JikuakuuInter::isVisible(){
        return false;
    }
    
    JikuakuuImage::JikuakuuImage(StartDemoMain* user):
    StateChild(user){
    }
    JikuakuuImage::~JikuakuuImage(){
    }
    StateChild* JikuakuuImage::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new JikuuakuuOuter(m_user);
        }
        return next;
    }
    void JikuakuuImage::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1.0/3.0;
        s->fill(GMRect2D(0, SCREEN_SIZE), white);
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_jiikuuakuu), GMRect2D(0, SCREEN_SIZE));
    };
    
    JikuuakuuOuter::JikuuakuuOuter(StartDemoMain* user):
    StateChild(user){
    }
    JikuuakuuOuter::~JikuuakuuOuter(){
    }
    StateChild* JikuuakuuOuter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        m_time += deltaTime/3;
        if(m_time >= 1){
            next = new TextOnly2(m_user);
        }else
        if(m_isNext){
            next = new TextOnly2(m_user);
        }
        return next;
    }
    void JikuuakuuOuter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1-m_time;
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_jiikuuakuu), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool JikuuakuuOuter::isVisible(){
        return false;
    }
    
    TextOnly2::TextOnly2(StartDemoMain* user):
    StateChild(user){
    }
    TextOnly2::~TextOnly2(){
    }
    StateChild* TextOnly2::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new SakumaInter(m_user);
        }
        return next;
    }
    void TextOnly2::draw(GMSpriteBatch* s){
    };
    
    SakumaInter::SakumaInter(StartDemoMain* user):
    StateChild(user){
    }
    SakumaInter::~SakumaInter(){
    }
    StateChild* SakumaInter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        m_time += deltaTime/3;
        if(m_time >= 1){
            next = new SakumaVisible(m_user);
        }else
        if(m_isNext){
            next = new SakumaVisible(m_user);
        }
        return next;
    }
    void SakumaInter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = m_time;
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool SakumaInter::isVisible(){
        return false;
    }
    
    SakumaVisible::SakumaVisible(StartDemoMain* user):
    StateChild(user){
    }
    SakumaVisible::~SakumaVisible(){
    }
    StateChild* SakumaVisible::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new SakumaInter2(m_user);
        }
        return next;
    }
    void SakumaVisible::draw(GMSpriteBatch* s){
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma), GMRect2D(0, SCREEN_SIZE));
    };
    
    SakumaInter2::SakumaInter2(StartDemoMain* user):
    StateChild(user){
    }
    SakumaInter2::~SakumaInter2(){
    }
    StateChild* SakumaInter2::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        m_time += deltaTime/3;
        if(m_time >= 1){
            next = new SakumaSakumaVisible2(m_user);
        }else
        if(m_isNext){
            next = new SakumaSakumaVisible2(m_user);
        }
        return next;
    }
    void SakumaInter2::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = m_time;
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma), GMRect2D(0, SCREEN_SIZE), white);
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma_c), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool SakumaInter2::isVisible(){
        return false;
    }
    
    SakumaSakumaVisible2::SakumaSakumaVisible2(StartDemoMain* user):
    StateChild(user){
    }
    SakumaSakumaVisible2::~SakumaSakumaVisible2(){
    }
    StateChild* SakumaSakumaVisible2::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new SakumaOuter(m_user);
        }
        return next;
    }
    void SakumaSakumaVisible2::draw(GMSpriteBatch* s){
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma), GMRect2D(0, SCREEN_SIZE));
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma_c), GMRect2D(0, SCREEN_SIZE));
    };
    
    SakumaOuter::SakumaOuter(StartDemoMain* user):
    StateChild(user){
    }
    SakumaOuter::~SakumaOuter(){
    }
    StateChild* SakumaOuter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new TextOnly4(m_user);
        }
        return next;
    }
    void SakumaOuter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1-m_time;
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma), GMRect2D(0, SCREEN_SIZE), white);
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_sakuma_c), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool SakumaOuter::isVisible(){
        return false;
    }
    
    TetoraInter::TetoraInter(StartDemoMain* user):
    StateChild(user){
    }
    TetoraInter::~TetoraInter(){
    }
    StateChild* TetoraInter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new TetoraVisible(m_user);
        }
        return next;
    }
    void TetoraInter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = m_time;
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_Tetorapeddora), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool TetoraInter::isVisible(){
        return false;
    }
    
    TetoraOuter::TetoraOuter(StartDemoMain* user):
    StateChild(user){
    }
    TetoraOuter::~TetoraOuter(){
    }
    StateChild* TetoraOuter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new TextOnly3(m_user);
        }
        return next;
    }
    void TetoraOuter::draw(GMSpriteBatch* s){
        GMColor white = GMColor::White;
        white.a = 1-m_time;
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_Tetorapeddora), GMRect2D(0, SCREEN_SIZE), white);
    };
    bool TetoraOuter::isVisible(){
        return false;
    }
    
    TetoraVisible::TetoraVisible(StartDemoMain* user):
    StateChild(user){
    }
    TetoraVisible::~TetoraVisible(){
    }
    StateChild* TetoraVisible::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_isNext){
            next = new TetoraOuter(m_user);
        }
        return next;
    }
    void TetoraVisible::draw(GMSpriteBatch* s){
        s->draw(gStartDemo->getTexMan()->get(SKStartDemo::texName_Tetorapeddora), GMRect2D(0, SCREEN_SIZE));
    };
    
    AllOuter::AllOuter(StartDemoMain* user):
    StateChild(user){
    }
    AllOuter::~AllOuter(){
    }
    StateChild* AllOuter::update(GMInput* input, double deltaTime){
        StateChild* next = this;
        if(m_time <= 1){
            gGameInst->ChangeScene("play");
        }
        return next;
    }
    void AllOuter::draw(GMSpriteBatch* s){
    };
    bool AllOuter::isVisible(){
        return false;
    }
    
}
}
