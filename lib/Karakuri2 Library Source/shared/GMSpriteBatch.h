//
//  GMSpriteBatch.h
//  Game Framework
//
//  Created by numata on Jan 02, 2011.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_SPRITE_BATCH_H__
#define __GM_SPRITE_BATCH_H__


#include "GMObject.h"
#include "GMTexture2D.h"
#include "GMTypes.h"
#include "GMDraw.h"
#include "GMGraphics.h"
#include "GMBasicEffect.h"

#include <list>


enum GMSpriteFlip {
    GMSpriteFlipNone,
    GMSpriteFlipHorizontally,
    GMSpriteFlipVertically,
};

/*!
    @enum       GMSpriteSortMode
    @group      Graphics
    @abstract   スプライト描画のソート方法を指定する定数です。
    @constant   GMSpriteSortModeImmediate       バッチ処理を行わず、即座に描画が行われます。
    @constant   GMSpriteSortModeDeferred        描画命令を発行した順に描画が行われます。（デフォルト）
    @constant   GMSpriteSortModeTexture         テクスチャによって描画順をソートします。
    @constant   GMSpriteSortModeBackToFront     layerDepth指定による深さで逆順にソートします。
    @constant   GMSpriteSortModeFrontToBack     layerDepth指定による深さでソートします。
 */
enum GMSpriteSortMode {
    GMSpriteSortModeImmediate,
    GMSpriteSortModeDeferred,
    GMSpriteSortModeTexture,
    GMSpriteSortModeBackToFront,
    GMSpriteSortModeFrontToBack,
};


struct GMSprite : public GMObject {
    
    GMTexture2D*    tex;
    GMRect2D        destRect;
    GMRect2D        srcRect;
    GMColor         color;
    double          rotation;
    GMVector2D      origin;
    GMSpriteFlip    flip;
    double          layerDepth;
    unsigned        count;
    
public:
    GMSprite(GMTexture2D* tex, const GMRect2D& destRect, const GMRect2D& srcRect, const GMColor& color,
             double rotation, const GMVector2D& origin, GMSpriteFlip flip, double layerDepth, unsigned count);
    
};


/*!
    @class  GMSpriteBatch
    @group  Graphics
    <p>2D画面へのスプライト描画を簡素化し、描画順を制御するために使用するクラスです。</p>
    <p>このクラスの begin()〜end() の間で行われた描画はバッファリングされ、end() の呼び出し時に描画順がソートされて描画されます。</p>
    <p><strong>GMSpriteBatch クラスのオブジェクトを使用した描画は、GMBasicEffect クラスのオブジェクトの begin()〜end() の呼び出し内で行う必要があります。</strong></p>
    <p>このクラスのインスタンスは、GMScene クラスのサブクラスの willAppear() メソッドが呼ばれたときに new して作成してください。</p>
    <p>実際の OpenGL / OpenGL ES の描画命令の発行は、GMDraw クラスを介して、GMDrawSys クラスによって行われます。</p>
 */
class GMSpriteBatch : public GMObject {
    
    GMSpriteSortMode        mSortMode;
    std::list<GMSprite*>    mSpriteList;
    int                     mDrawCount;
    
    bool    mHasBegun;

public:
    /*!
        @task   コンストラクタ
     */
    
    /*!
        @method     GMSpriteBatch
        コンストラクタ
     */
    GMSpriteBatch();
    
public:
    /*!
        @task   描画の開始と終了
     */
    
    /*!
        @method     begin
        <p>ソートのモードを指定して描画を開始します。デフォルトのモードは GMSpriteSortModeDeferred です。</p>
        <p>GMSpriteSortModeDeferred, GMSpriteSortModeFrontToBack, GMSpriteSortModeBackToFront, GMSpriteSortModeTexture, GMSpriteSortModeImmediate が指定できます。</p>
     */
    void    begin(GMSpriteSortMode sortMode = GMSpriteSortModeDeferred);

    /*!
        @method     end
        <p>これまでにバッファリングされたスプライト描画をソートして、描画処理を行います。</p>
     */
    void    end();

    
    /*!
        @task   矩形を指定する描画
     */

    /*!
        @method     draw
        <p>テクスチャと描画先の矩形を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMRect2D& destRect, double layerDepth = 0.0);

    /*!
        @method     draw
        <p>テクスチャ、描画先の矩形、カラーを指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMRect2D& destRect, const GMColor& color, double layerDepth = 0.0);

    /*!
        @method     draw
        <p>テクスチャ、描画先の矩形、描画元の矩形を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMRect2D& destRect, const GMRect2D& srcRect, double layerDepth = 0.0);

    /*!
        @method     draw
        <p>テクスチャ、描画先の矩形、描画元の矩形を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMRect2D& destRect, const GMRect2D& srcRect, const GMColor& color, double layerDepth = 0.0);

    /*!
        @method     draw
        <p>テクスチャ、描画先の矩形、描画元の矩形、カラー、回転の角度、回転の中心座標、フリップの有無を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMRect2D& destRect, const GMRect2D& srcRect, const GMColor& color, double rotation, const GMVector2D& origin, GMSpriteFlip flip, double layerDepth = 0.0);


    /*!
        @task   位置を指定する描画
     */
    
    /*!
        @method     draw
        <p>テクスチャと描画先の座標を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMVector2D& pos, double layerDepth = 0.0);

    /*!
        @method     draw
        <p>テクスチャ、描画先の座標、カラーを指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMVector2D& pos, const GMColor& color, double layerDepth = 0.0);
    
    /*!
        @method     draw
        <p>テクスチャ、描画先の座標、描画元の矩形を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMVector2D& pos, const GMRect2D& srcRect, double layerDepth = 0.0);

    /*!
        @method     draw
        <p>テクスチャ、描画先の座標、描画元の矩形、カラーを指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMVector2D& pos, const GMRect2D& srcRect, const GMColor& color, double layerDepth = 0.0);
    
    /*!
        @method     draw
        <p>テクスチャ、描画先の座標、描画元の矩形、カラー、回転の角度、回転の中心座標、スケーリング、フリップの有無を指定して、スプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    draw(GMTexture2D* tex, const GMVector2D& pos, const GMRect2D& srcRect, const GMColor& color, double rotation, const GMVector2D& origin, const GMVector2D& scale, GMSpriteFlip flip, double layerDepth = 0.0);


    /*!
        @task   カラーのみの描画
        <p>カラーを指定して、色で塗り潰したスプライト描画を行います。</p>
        <p>GMSpriteSortModeFrontToBack または GMSpriteSortModeBackToFront のソートモードで有効な奥行き (layerDepth) も指定できます。デフォルトの奥行きは 0.0 です。</p>
     */
    void    fill(const GMRect2D& rect, const GMColor& color, double layerDepth = 0.0);

private:
    void    __applyGraphicsSettings();
    void    __flushBatchDraws();
    
};


#endif  //#ifndef __GM_SPRITE_BATCH_H__


