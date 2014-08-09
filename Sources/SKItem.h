//
//  SKItem.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/29.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKItem__
#define __Karakuri2_Mac__SKItem__

#include "Karakuri.h"
#include "SKObject.h"
#include "ItemCommandInfo.h"

namespace itemFlags{
    enum flags{
        willDestroy,
        syukuhuku,
        noroi,
    };
}

namespace itemNames{
    enum itemName{
        kinoeda,
        bokutou,
        douken,
        tetunoken,
        haganenoken,
        kengyo,
        
        kawanotate,
        kinotate,
        kikkou,
        tetunotate,
        yaibanotate,
        
        genyu,
        kagami,
        hyoukessyou,
        kayaku,
        mokuzai,
        
        none = -99,
    };
    
};


class SKItem : public SKObject{
    bool m_delFlag;
    
protected:
    itemNames::itemName m_numName;
    int m_itemNum;
    unsigned m_flag;
    
public:
    SKItem();
    SKItem(const std::string& itemName);
    virtual ~SKItem();
    
    static SKItem* createRandamItem();
    
    void objectDraw(int s_draw_x, int s_draw_y) override;
    bool objectUpdate(GMInput* input, double deltaTime) override;
    void objectInit(GMGraphics* g) override;
    
    bool isDel();
    
public:
    virtual void getSetumei(std::string& strIn) = 0;
    // 表示UI取得
    virtual CarsorSelectReAction* getSelectReaction() = 0;
    
};




#endif /* defined(__Karakuri2_Mac__SKItem__) */
