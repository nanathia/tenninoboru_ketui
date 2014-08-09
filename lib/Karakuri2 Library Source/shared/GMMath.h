//
//  GMMath.h
//  Game Framework
//
//  Created by numata on Jan 02, 2011.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_MATH_H__
#define __GM_MATH_H__


#include "GMObject.h"


/*!
    @class  GMMath
    @group  Math
    数学関係の処理をまとめたクラスです。
 */
struct GMMath : public GMObject {


    /*!
        @const  kDoubleEqThreshold
        double型の数値の等価判定を行う場合に使用する閾値です。
     */
    static const double kDoubleEqThreshold;

    /*!
        @const  kFloatEqThreshold
        float型の数値の等価判定を行う場合に使用する閾値です。
     */
    static const float  kFloatEqThreshold;

    /*!
        @task   数値補完
     */

    /*!
        @method     Barycentric
        @abstract   指定されたトライアングルと2つの正規化された重心 (エリア) 座標に基づいて定義されたポイントの、特定の軸でのデカルト座標を返します。
     */
    static double   Barycentric(double value1, double value2, double value3, double amount1, double amount2);
    
    /*!
        @method     CatmullRom
        2つの数値のCatmull-Rom補間を計算します。
     */
    static double   CatmullRom(double value1, double value2, double value3, double value4, double amount);
    
    /*!
        @method     EaseIn
        2つの数値のEase-In補間を計算します。
     */
    static double   EaseIn(double value1, double value2, double amount);
    
    /*!
        @method     EaseInOut
        2つの数値のEase-In/Ease-Out補間を計算します。
     */
    static double   EaseInOut(double value1, double value2, double amount);

    /*!
        @method     EaseOut
        2つの数値のEase-Out補間を計算します。
     */
    static double   EaseOut(double value1, double value2, double amount);
    
    /*!
        @method     Hermite
        2つの数値のエルミート・スプライン補間を計算します。
     */
    static double   Hermite(double value1, double tan1, double value2, double tan2, double amount);

    /*!
        @method     Lerp
        2つの数値の線形補間を計算します。
     */
    static double   Lerp(double value1, double value2, double amount);

    /*!
        @method     SmoothStep
        2つの数値の3次元方程式を使用した補間を計算します。
     */
    static double   SmoothStep(double edge0, double edge1, double x);


    /*!
        @task   数値処理
     */
    
    /*!
        @method     Clamp
        指定された範囲内に値を制限します。
     */
    static double   Clamp(double x, double minVal, double maxVal);

    /*!
        @method     Distance
        2つの数値の差の絶対値を計算します。
     */
    static double   Distance(double value1, double value2);

    /*!
        @method     Max
        2つの数値の最大値を返します。
     */
    static double   Max(double value1, double value2);

    /*!
        @method     Min
        2つの数値の最小値を返します。
     */
    static double   Min(double value1, double value2);
    
    /*!
        @task   角度の変換
     */
    
    /*!
        @method     ToDegrees
        @abstract   ラジアン単位の角度を度に変換します。
     */
    static double   ToDegrees(double radians);

    /*!
        @method     ToRadians
        @abstract   度をラジアン単位の角度に変換します。
     */
    static double   ToRadians(double degrees);

    /*!
        @method     WrapAngle
        @abstract   指定された角度を π ～ -π の間の値に狭めます。
     */
    static double   WrapAngle(double radians);
    
};


#endif  //#ifndef __GM_MATH_H__


