
#include "LogoChild.h"
#include "SKSoundManager.h"
#include "SKTitleChild.h"
#include "SKTitle.h"
#include "Globals.h"
#include "SKDrawFont.h"
#include "GameMain.h"

namespace titleScene{

    LogoChild::LogoChild(){
    }
    LogoChild::~LogoChild(){
    }
    
    LogoInter::LogoInter():
    LogoChild(){
    }
    LogoInter::~LogoInter(){
    }
    LogoChild* LogoInter::update(TitleLogo* parent, GMInput* input, double deltaTime){
        LogoChild* next = this;
        parent->m_time += deltaTime;
        parent->m_animationTime += deltaTime/3;
        if(parent->m_animationTime >= 1){
            next = new LogoInterval();
        }
        return next;
    }
    void LogoInter::draw(TitleLogo* parent, GMSpriteBatch* s){
        GMGraphics::CurrentGraphics->clear(GMColor::White);
        GMColor c = GMColor::DarkBlue;
        GMColor c2 = GMColor::White;
        GMColor c3 = GMColor::SkyBlue;
        c3.a = parent->m_animationTime;
        c2.a = GMMath::EaseIn(0, 1, parent->m_animationTime);
        c.a = parent->m_animationTime;
        s->draw(0, GMRect2D(0, SCREEN_SIZE), c, 0);
        s->draw(parent->m_LogoImage, GMRect2D(SCREEN_SIZE.x-400, 200, 300, 300), c2);
        gGameInst->getFont()->drawString(s, "Project by", GMVector2D(50, SCREEN_SIZE.y/2+50), c3);
        if(parent->m_animationTime >= 0.5){
            GMColor c4 = GMColor::SkyBlue;
            c4.a = GMMath::EaseInOut(0, 1, parent->m_animationTime-0.5)*2;
            SKDrawFont::drawString("時空亜空の世界", 70, GMVector2D(50, SCREEN_SIZE.y/2-50), 0, s, c4);
        }
    }
    
    LogoInterval::LogoInterval():
    LogoChild(),
    m_interval(0){
        gTitleScene->getSoundMan()->get(SoundName_Logo)->play();
    }
    LogoInterval::~LogoInterval(){
    }
    LogoChild* LogoInterval::update(TitleLogo* parent, GMInput* input, double deltaTime){
        LogoChild* next = this;
        m_interval += deltaTime/3;
        if(m_interval >= 1){
            next = new LogoOuter();
        }
        return next;
    }
    void LogoInterval::draw(TitleLogo* parent, GMSpriteBatch* s){
        GMGraphics::CurrentGraphics->clear(GMColor::White);
        s->draw(0, GMRect2D(0, SCREEN_SIZE), GMColor::DarkBlue);
        GMColor c2 = GMColor::White;
        c2.a = parent->m_animationTime;
        s->draw(parent->m_LogoImage, GMRect2D(SCREEN_SIZE.x-400, 200, 300, 300), c2);
        gGameInst->getFont()->drawString(s, "Project by", GMVector2D(50, SCREEN_SIZE.y/2+50), GMColor::SkyBlue);
        SKDrawFont::drawString("時空亜空の世界", 70, GMVector2D(50, SCREEN_SIZE.y/2-50), 0, s, GMColor::SkyBlue);
    }
    
    LogoOuter::LogoOuter(){
    }
    LogoOuter::~LogoOuter(){
    }
    LogoChild* LogoOuter::update(TitleLogo* parent, GMInput* input, double deltaTime){
        LogoChild* next = this;
        parent->m_time += deltaTime;
        parent->m_animationTime -= deltaTime/2;
        if(parent->m_animationTime <= 0){
            next = 0;
        }
        return next;
    }
    void LogoOuter::draw(TitleLogo* parent, GMSpriteBatch* s){
        GMGraphics::CurrentGraphics->clear(GMColor::White);
        GMColor c = GMColor::DarkBlue;
        GMColor c2 = GMColor::White;
        GMColor c3 = GMColor::SkyBlue;
        c3.a = parent->m_animationTime;
        c2.a = GMMath::EaseOut(0, 1, parent->m_animationTime);
        c.a = parent->m_animationTime;
        s->draw(0, GMRect2D(0, SCREEN_SIZE), c);
        s->draw(parent->m_LogoImage, GMRect2D(SCREEN_SIZE.x-400, 200, 300, 300), c2);
        gGameInst->getFont()->drawString(s, "Project by", GMVector2D(50, SCREEN_SIZE.y/2+50), c3);
        SKDrawFont::drawString("時空亜空の世界", 70, GMVector2D(50, SCREEN_SIZE.y/2-50), 0, s, c3);
    }

}