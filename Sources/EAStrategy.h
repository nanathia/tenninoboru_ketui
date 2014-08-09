//
//  EAStrategy.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__EAStrategy__
#define __Karakuri2_Mac__EAStrategy__

#include "Karakuri.h"
#include "SaKumas_includes.h"
#include <string>

// 名前を入れるだけでアルゴリズムを組むクラス
// 移動かどうか。

class EAStrategy{
protected:
    // コンバート。
    void convertRadianToOffset(double radian, int& x, int& y) const;
    
public:
    EAStrategy();
    virtual ~EAStrategy();
    
public:
    // １フレームの敵の処理 処理が終わればtrue
    virtual bool isMove(){
        return false;
    }
    virtual void action(SKEnemy*) = 0;
    virtual const char* resetAction(SKEnemy*) = 0;
};


#endif /* defined(__Karakuri2_Mac__EAStrategy__) */
