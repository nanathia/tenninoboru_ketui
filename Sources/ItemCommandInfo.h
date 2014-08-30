//
//  ItemCommandInfo.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/27.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__ItemCommandInfo__
#define __Karakuri2_Mac__ItemCommandInfo__

#include "Karakuri.h"
#include <vector>
#include <string>

class SKItem;
class SKDungeonScene;

class CarsorSelectReAction{
protected:
    
public:
    virtual const char* update(GMInput* input, double deltaTime, SKItem* item) = 0;
    virtual void draw(GMSpriteBatch* s) = 0;
    
    virtual ~CarsorSelectReAction();
};

class CarsorInfo{
protected:
    SKDungeonScene* m_scene;
    void _draw(const GMVector2D& pos, const std::string& str, GMSpriteBatch* s);
    
public:
    CarsorInfo(SKDungeonScene* scene);
    virtual ~CarsorInfo();
    virtual void draw(const GMVector2D& pos, GMSpriteBatch* s) = 0;
    virtual CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) = 0;
    
};

class SoubiCommand: public CarsorInfo{
public:
    SoubiCommand(SKDungeonScene* scene);
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;

};

class YomuCommand: public CarsorInfo{
public:
    YomuCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class TaberuCommand: public CarsorInfo{
public:
    TaberuCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class NakawomiruCommand: public CarsorInfo{
public:
    NakawomiruCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class SuteruCommand: public CarsorInfo{
public:
    SuteruCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class NageruCommand: public CarsorInfo{
public:
    NageruCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class NomuCommand: public CarsorInfo{
public:
    NomuCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class HirouCommand: public CarsorInfo{
public:
    HirouCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class KoukanCommand: public CarsorInfo{
public:
    KoukanCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class SetumeiCommand: public CarsorInfo{
public:
    SetumeiCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class OkuCommand: public CarsorInfo{
public:
    OkuCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class KakuCommand: public CarsorInfo{
public:
    KakuCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};

class UtuCommand: public CarsorInfo{
public:
    UtuCommand(SKDungeonScene* scene);
    CarsorSelectReAction* choice(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(const GMVector2D& pos, GMSpriteBatch* s) override;
    
};


class CommandInfo: public CarsorSelectReAction{
    std::vector<CarsorInfo*> m_carsors;
    int m_carsor;
    CarsorSelectReAction* m_child;
    SKDungeonScene* m_scene;
    
public:
    const char* update(GMInput* input, double deltaTime, SKItem* item) override;
    void draw(GMSpriteBatch* s) override;

    CommandInfo(SKDungeonScene* scene);
    ~CommandInfo();
    std::vector<CarsorInfo*> getCarsors();
    void addCarsor(CarsorInfo* carsor);
    
};

class Question: public CommandInfo{
    std::string m_questionStr;
public:
    void draw(GMSpriteBatch* s) override;
    
};

#endif /* defined(__Karakuri2_Mac__ItemCommandInfo__) */
