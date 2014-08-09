//
//  EAStrategy.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "EAStrategy.h"

EAStrategy::EAStrategy()
{
    
}

EAStrategy::~EAStrategy(){

}

// １フレームの敵の処理 処理が終わればtrue
void EAStrategy::action(SKEnemy* parent){
    GMException("ふぇー");
    
    // TODO: EAStrategy::action()の実装
}

// コンバート。
void EAStrategy::convertRadianToOffset(double radian, int& ofs_x, int& ofs_y) const{
    ofs_x = ofs_y = 0;
    
    if(radian == 0){
        // 右
        ofs_x = 1;
    }else if(radian == 0.25){
        // 右上
        ofs_x = 1;
        ofs_y = 1;
    }else if(radian == 0.5){
        // 上
        ofs_y = 1;
    }else if(radian == 0.75){
        // 左上
        ofs_x = -1;
        ofs_y = 1;
    }else if(radian == 1.0 || radian == -1.0){
        // 左
        ofs_x = -1;
    }else if(radian == -0.75){
        // 左下
        ofs_x = -1;
        ofs_y = -1;
    }else if(radian == -0.5){
        // 下
        ofs_y = -1;
    }else if(radian == -0.25){
        // 右下
        ofs_x = 1;
        ofs_y = -1;
    }else{
        throw "どの方向にも一致しない";
    }
}