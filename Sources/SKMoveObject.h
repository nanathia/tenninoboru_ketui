//
//  SKMoveObject.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/07/13.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKMoveObject__
#define __Karakuri2_Mac__SKMoveObject__

#include "Karakuri.h"
#include "SKObject.h"

class SKMoveObject: public SKObject{
protected:
    int m_hp;
    double objSpeed;
    int m_turnActionCounter;
    
    // ダメージを受けたフラグ
    bool m_isDamaged;
    
protected:
    double m_objHeight;
    double m_time;
    string characterName;
    string animeName;
    bool spin;
    
public:
    
    void actionCount();
    void actionReset();
    bool isActionEnabled();
    const std::string& getAnimeName();
    
    bool objectUpdate(GMInput* input, double deltaTime) override;
    
    SKMoveObject();
    virtual ~SKMoveObject();
    void attack();
    int getHp() const;
    
    // 移動可能なマスかどうか
    bool isEnableMoveMass(SKMass* mass);
    // 攻撃可能なマスかどうか
    bool isEnableAttackMass(SKMass* mass);
    
    // ダメージを受けたか
    bool isDamaged();
    void damage(int point, SKMoveObject* obj);
    void damaged();
    
    void getLocalizeOffset(SKMass* mass, int& x, int& y);
    SKMass* getMassForAngle(SKMass* mass);
    
};

#endif /* defined(__Karakuri2_Mac__SKMoveObject__) */
