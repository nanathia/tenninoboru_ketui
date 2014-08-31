//
//  MapSelectSceneSelectObj.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/31.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MapSelectSceneSelectObj__
#define __Karakuri2_Mac__MapSelectSceneSelectObj__

#include "Karakuri.h"

namespace mapSelect{
    class SKMapSelectScene;
    class SelectCarsor;
    class SelectObjState;
    
    class SelectObj{
        // 前後
        SelectObj* m_next;
        SelectObj* m_prev;
        // 選択カーソル
        SelectCarsor* m_carsor;
        // 状態
        SelectObjState* m_state;
        // 親
        SKMapSelectScene* m_parent;
        // テクスチャ
        GMTexture2D* m_tex;
        // 位置
        const GMRect2D m_rect;
        // 名前
        const std::string m_name;
        
    public:
        SelectObj(SKMapSelectScene* parent, const GMRect2D& rect, GMTexture2D* tex, const std::string& name);
        ~SelectObj();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        // カーソルが渡れるように連結
        void setPrev(SelectObj* prev);
        void setNext(SelectObj* next);
        SelectObj* getPrev();
        SelectObj* getNext();
        // カーソルメソッド
        void setCarsor(SelectCarsor* carsor);
        SelectCarsor* getCarsor();
        // 親取得
        SKMapSelectScene* getScene();
        // 名前
        const std::string& Name() const;
        // 位置
        const GMRect2D& Rect() const;
        // 画像
        GMTexture2D* getTex();
    };
    
}

#endif /* defined(__Karakuri2_Mac__MapSelectSceneSelectObj__) */
