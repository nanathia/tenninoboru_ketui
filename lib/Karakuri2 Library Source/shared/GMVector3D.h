//
//  GMVector3D.h
//  Game Framework
//
//  Created by numata on Jan 10, 2011.
//  Copyright 2011-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_VECTOR3D_H__
#define __GM_VECTOR3D_H__


#include "GMObject.h"
struct GMVector2D;
struct GMMatrix;
struct GMQuat;


/*!
    @class  GMVector3D
    @group  Math
    3次元ベクトルを表すためのクラスです。
 */
struct GMVector3D : public GMObject {

public:
    /*!
        @const  Backward
     */
    static const GMVector3D&    Backward;

    /*!
        @const  Down
     */
    static const GMVector3D&    Down;
    
    /*!
        @const  Forward
     */
    static const GMVector3D&    Forward;
    
    /*!
        @const  Left
     */
    static const GMVector3D&    Left;
    
    /*!
        @const  One
     */
    static const GMVector3D&    One;
    
    /*!
        @const  Right
     */
    static const GMVector3D&    Right;
    
    /*!
        @const  UnitX
     */
    static const GMVector3D&    UnitX;
    
    /*!
        @const  UnitY
     */
    static const GMVector3D&    UnitY;
    
    /*!
        @const  UnitZ
     */
    static const GMVector3D&    UnitZ;
    
    /*!
        @const  Up
     */
    static const GMVector3D&    Up;
    
    /*!
        @const  Zero
     */
    static const GMVector3D&    Zero;

public:
    /*!
        @task   数値補完
     */
    
    /*!
        @method     Barycentric
     */
    static GMVector3D   Barycentric(const GMVector3D& v1, const GMVector3D& v2, const GMVector3D& v3, double amount1, double amount2);
    
    /*!
        @method     CatmullRom
        2つのベクトルのCatmull-Romの補間を計算します。
     */
    static GMVector3D   CatmullRom(const GMVector3D& vec1, const GMVector3D& vec2, const GMVector3D& vec3, const GMVector3D& vec4, double amount);

    /*!
        @method     EaseIn
        2つのベクトルのEase-Inの補間を計算します。
     */
    static GMVector3D   EaseIn(const GMVector3D& vec1, const GMVector3D& vec2, double amount);

    /*!
        @method     EaseInOut
        2つのベクトルのEase-In/Ease-Outの補間を計算します。
     */
    static GMVector3D   EaseInOut(const GMVector3D& vec1, const GMVector3D& vec2, double amount);

    /*!
        @method     EaseOut
        2つのベクトルのEase-Outの補間を計算します。
     */
    static GMVector3D   EaseOut(const GMVector3D& vec1, const GMVector3D& vec2, double amount);

    /*!
        @method     Hermite
        2つのベクトルのエルミート・スプライン補間を計算します。
     */
    static GMVector3D   Hermite(const GMVector3D& vec1, const GMVector3D& tan1, const GMVector3D& vec2, const GMVector3D& tan2, double amount);
    
    /*!
        @method     Lerp
        2つのベクトルの線形補間を計算します。
     */
    static GMVector3D   Lerp(const GMVector3D& vec1, const GMVector3D& vec2, double amount);

    /*!
        @method     SmoothStep
        2つのベクトルの3次元方程式を使用した補間を計算します。
     */
    static GMVector3D   SmoothStep(const GMVector3D& vec1, const GMVector3D& vec2, double amount);


    /*!
        @task   数値処理
     */
    
    /*!
        @method     Max
        x,y,zの各値の最大値を含むベクトルを作成します。
     */
    static GMVector3D   Max(const GMVector3D& vec1, const GMVector3D& vec2);
    
    /*!
        @method     Min
        x,y,zの各値の最小値を含むベクトルを作成します。
     */
    static GMVector3D   Min(const GMVector3D& vec1, const GMVector3D& vec2);
    
    /*!
        @var    x
     */
    double x;
    
    /*!
        @var    y
     */
    double y;
    
    /*!
        @var    z
     */
    double z;
    
public:
    /*!
        @task   コンストラクタ
     */

    /*!
        @method     GMVector3D
     */
    GMVector3D();
    
    /*!
        @method     GMVector3D
     */
    GMVector3D(double value);
    
    /*!
        @method     GMVector3D
     */
    GMVector3D(double x, double y, double z);
    
    /*!
        @method     GMVector3D
     */
    GMVector3D(const GMVector2D& vec, double z);
    
    /*!
        @method     GMVector3D
     */
    GMVector3D(const GMVector3D& vec);
    
public:
    /*!
        @task   メインの操作
     */

    /*!
        @method     clamp
        指定された範囲内に値を制限します。
     */
    GMVector3D  clamp(const GMVector3D& min, const GMVector3D& max) const;
    
    /*!
        @method     cross
        与えられたベクトルとのクロス積（外積）を計算します。
     */
    GMVector3D  cross(const GMVector3D& vec) const;
    
    /*!
        @method     distance
        与えられたベクトルとの距離を計算します。
     */
    double      distance(const GMVector3D& vec) const;
    
    /*!
        @method     distanceSq
        与えられたベクトルとの距離の二乗を計算します。
     */
    double      distanceSq(const GMVector3D& vec) const;
    
    /*!
        @method     dot
        与えられたベクトルとのドット積（内積）を計算します。
     */
    double      dot(const GMVector3D& vec) const;
    
    /*!
        @method     equals
        与えられたベクトルと等しいかどうかを判定します。
     */
    bool        equals(const GMVector3D& vec, double accuracy) const;
    
    /*!
        @method     length
        このベクトルの長さを計算します。
     */
    double      length() const;
    
    /*!
        @method     lengthSq
        このベクトルの長さの二乗を計算します。
     */
    double      lengthSq() const;
    
    /*!
        @method     normal
        単位ベクトルを作成します。
     */
    GMVector3D  normal() const;
    
    /*!
        @method     normalize
        このベクトルを正規化して、参照をリターンします。
     */
    GMVector3D& normalize();
    
    /*!
        @method     reflect
     */
    GMVector3D  reflect(const GMVector3D& normal) const;
    
    /*!
        @method     transform
        指定された4x4行列を使ってこのベクトルを変形します。
     */
    GMVector3D  transform(const GMMatrix& matrix) const;
    
    /*!
        @method     transform
        指定されたクォータニオンを使ってこのベクトルを変形します。
     */
    GMVector3D  transform(const GMQuat& quat) const;
    
public:
    /*!
        @task   演算子のオーバーロード
     */
    
    /*!
        @method     operator=
     */
    GMVector3D& operator=(const GMVector3D& vec);
    
    
    /*!
        @method     operator-
     */
    GMVector3D operator-() const;
    
    /*!
        @method     operator+
     */
    GMVector3D operator+(const GMVector3D& vec) const;
    
    /*!
        @method     operator-
     */
    GMVector3D operator-(const GMVector3D& vec) const;
    
    /*!
        @method     operator*
     */
    GMVector3D operator*(const GMVector3D& vec) const;
    
    /*!
        @method     operator/
     */
    GMVector3D operator/(const GMVector3D& vec) const;
    
    /*!
        @method     operator*
     */
    GMVector3D operator*(double value) const;
    
    /*!
        @method     operator/
     */
    GMVector3D operator/(double value) const;
    
    friend GMVector3D operator*(double value, const GMVector3D& vec);
    
    
    /*!
        @method     operator+=
     */
    GMVector3D& operator+=(const GMVector3D& vec);
    
    /*!
        @method     operator-=
     */
    GMVector3D& operator-=(const GMVector3D& vec);
    
    /*!
        @method     operator*=
     */
    GMVector3D& operator*=(const GMVector3D& vec);
    
    /*!
        @method     operator/=
     */
    GMVector3D& operator/=(const GMVector3D& vec);
    
    /*!
        @method     operator*=
     */
    GMVector3D& operator*=(double value);
    
    /*!
        @method     operator/=
     */
    GMVector3D& operator/=(double value);
    
    
    /*!
        @method     operator==
     */
    bool        operator==(const GMVector3D& vec) const;
    
    /*!
        @method     operator!=
     */
    bool        operator!=(const GMVector3D& vec) const;

};


#endif  //#ifndef __GM_VECTOR3D_H__

