//
//  GMGame.cpp
//  Game Framework
//
//  Created by numata on Jan 04, 2011.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#include "GMGame.h"
#include "GMException.h"
#include "GMGlobals.h"
#include "GMGraphics.h"
#include "GMSaveBox.h"

#include <TargetConditionals.h>

#include "Globals.h"


static GMGame*  sGameInst   = 0;


GMGame::GMGame()
    : mCurrentScene(0), mTitle(GM_DEFAULT_TITLE), mStartUpColor(gGMDefaultStartUpColor)
{
    sGameInst = this;
    
    mSubDisplayConnectionNotified = false;
    
    ///// タイトルの設定
#if !TARGET_OS_IPHONE
    setTitle(GAME_TITLE);
#endif
}

GMGame::~GMGame()
{
    if (mCurrentScene) {
        mCurrentScene->didDisappear();
        if (GMGraphics::Graphics2) {
            mCurrentScene->didDisappear2();
        }
        mCurrentScene = 0;
    }
    std::map<std::string, GMScene*>::iterator it = mSceneMap.begin();
	while (it != mSceneMap.end()) {
        delete (*it).second;
		it++;
	}
}

void GMGame::setStartUpColor(const GMColor& color)
{
    mStartUpColor = color;
}

void GMGame::setTitle(const std::string& str)
{
    mTitle = str;
}

GMColor GMGame::getStartUpColor() const
{
    return mStartUpColor;
}

std::string GMGame::getTitle() const
{
    return mTitle;
}


#pragma mark ==== ゲーム進行 ====

void GMGame::drawView(GMGraphics* g)
{
    if (mCurrentScene == 0) {
        throw GMException("Game scene has not been selected.");
    }
    
    mCurrentScene->drawView(g);
}

void GMGame::drawView2(GMGraphics* g2)
{
    if (mCurrentScene == 0) {
        throw GMException("Game scene has not been selected.");
    }
    
    if (!mSubDisplayConnectionNotified) {
        mCurrentScene->willAppear2(g2);
        mSubDisplayConnectionNotified = true;
    }
    mCurrentScene->drawView2(g2);
}

void GMGame::updateModel(GMInput* input, double deltaTime)
{
    if (mCurrentScene == 0) {
        throw GMException("Game scene has not been selected.");
    }
    
#if IS_DEBUG
    if(input->isKeyDownTriggered(GMKeyMaskP) && input->isKeyDown(GMKeyMaskC)){
        this->ChangeScene("play");
    }else if(input->isKeyDownTriggered(GMKeyMaskT) && input->isKeyDown(GMKeyMaskC)){
        this->ChangeScene("title");
    }else if(input->isKeyDownTriggered(GMKeyMaskD) && input->isKeyDown(GMKeyMaskC)){
        this->ChangeScene("startDemo");
    }
#endif
    
    mCurrentScene->updateModel(input, deltaTime);
}


#pragma mark ==== シーン管理 ====

void GMGame::addScene(const std::string& name, GMScene* aScene)
{
    aScene->__setName(name);
    mSceneMap[name] = aScene;
}

GMScene* GMGame::GetCurrentScene()
{
    return sGameInst->mCurrentScene;
}

GMScene* GMGame::GetScene(const std::string& name)
{
    return sGameInst->mSceneMap[name];
}

void GMGame::ChangeScene(const std::string& name)
{
    GMScene* theScene = GMGame::GetScene(name);
    if (!theScene) {
        throw GMException("Game scene \"%s\" was not found.", name.c_str());
    }
    gGMNextScene = theScene;
}

void GMGame::__applySceneChange()
{
    if (mCurrentScene) {
        mCurrentScene->didDisappear();
        if (GMGraphics::Graphics2) {
            mCurrentScene->didDisappear2();
        }
    }
    
    mCurrentScene = gGMNextScene;
    gGMNextScene = 0;
    
    mCurrentScene->willAppear(GMGraphics::Graphics1);
    if (GMGraphics::Graphics2) {
        mCurrentScene->willAppear2(GMGraphics::Graphics2);
        mSubDisplayConnectionNotified = true;
    }
}


