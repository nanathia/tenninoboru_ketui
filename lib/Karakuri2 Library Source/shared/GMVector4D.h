//
//  GMVector4D.h
//  Game Framework
//
//  Created by numata on Jan 10, 2011.
//  Copyright 2011-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GL_VECTOR4D_H__
#define __GL_VECTOR4D_H__


#include "GMObject.h"
class GMMatrix;
class GMVector2D;
class GMVector3D;
class GMQuat;


/*!
    @class  GMVector4D
    @group  Math
    4次元ベクトルを表すためのクラスです。
 */
struct GMVector4D : public GMObject {
    
public:
    /*!
        @const  One
     */
    static const GMVector4D&    One;

    /*!
        @const  UnitX
     */
    static const GMVector4D&    UnitX;

    /*!
        @const  UnitY
     */
    static const GMVector4D&    UnitY;

    /*!
        @const  UnitZ
     */
    static const GMVector4D&    UnitZ;

    /*!
        @const  UnitW
     */
    static const GMVector4D&    UnitW;

    /*!
        @const  Zero
     */
    static const GMVector4D&    Zero;
    
public:
    /*!
        @task   数値補完
     */
    
    /*!
        @method     Barycentric
     */
    static GMVector4D   Barycentric(const GMVector4D& v1, const GMVector4D& v2, const GMVector4D& v3, double amount1, double amount2);
    
    /*!
        @method     CatmullRom
        2つのベクトルのCatmull-Romの補間を計算します。
     */
    static GMVector4D   CatmullRom(const GMVector4D& vec1, const GMVector4D& vec2, const GMVector4D& vec3, const GMVector4D& vec4, double amount);

    /*!
        @method     EaseIn
        2つのベクトルのEase-Inの補間を計算します。
     */
    static GMVector4D   EaseIn(const GMVector4D& vec1, const GMVector4D& vec2, double amount);

    /*!
        @method     EaseInOut
        2つのベクトルのEase-In/Ease-Outの補間を計算します。
     */
    static GMVector4D   EaseInOut(const GMVector4D& vec1, const GMVector4D& vec2, double amount);

    /*!
        @method     EaseOut
        2つのベクトルのEase-Outの補間を計算します。
     */
    static GMVector4D   EaseOut(const GMVector4D& vec1, const GMVector4D& vec2, double amount);

    /*!
        @method     Hermite
        2つのベクトルのエルミート・スプライン補間を計算します。
     */
    static GMVector4D   Hermite(const GMVector4D& vec1, const GMVector4D& tan1, const GMVector4D& vec2, const GMVector4D& tan2, double amount);
    
    /*!
        @method     Lerp
        2つのベクトルの線形補間を計算します。
     */
    static GMVector4D   Lerp(const GMVector4D& vec1, const GMVector4D& vec2, double amount);
    
    /*!
        @method     SmoothStep
        2つのベクトルの3次元方程式を使用した補間を計算します。
     */
    static GMVector4D   SmoothStep(const GMVector4D& vec1, const GMVector4D& vec2, double amount);


    /*!
        @task   数値処理
     */
    
    /*!
        @method     Max
        x,y,z,wの各値の最大値を含むベクトルを作成します。
     */
    static GMVector4D   Max(const GMVector4D& vec1, const GMVector4D& vec2);
    
    /*!
        @method     Min
        x,y,z,wの各値の最小値を含むベクトルを作成します。
     */
    static GMVector4D   Min(const GMVector4D& vec1, const GMVector4D& vec2);
    
    /*!
        @task   変換
     */
    
    /*!
        @method     Transform
     */
    static GMVector4D   Transform(const GMVector2D& position, const GMMatrix& matrix);
    
    /*!
        @method     Transform
     */
    static GMVector4D   Transform(const GMVector3D& position, const GMMatrix& matrix);
    
    /*!
        @method     Transform
     */
    static GMVector4D   Transform(const GMVector4D& position, const GMMatrix& matrix);
    
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
    
    /*!
        @var    w
     */
    double w;
    
public:
    /*!
     @task   コンストラクタ
     */
    
    /*!
        @method     GMVector4D
     */
    GMVector4D();
    
    /*!
        @method     GMVector4D
     */
    GMVector4D(double value);
    
    /*!
        @method     GMVector4D
     */
    GMVector4D(double x, double y, double z, double w);
    
    /*!
        @method     GMVector4D
     */
    GMVector4D(const GMVector2D& vec, double z, double w);
    
    /*!
        @method     GMVector4D
     */
    GMVector4D(const GMVector3D& vec, double w);
    
    /*!
        @method     GMVector4D
     */
    GMVector4D(const GMVector4D& vec);
    
public:
    /*!
        @method     メインの操作
     */
    
    /*!
        @method     clamp
        指定された範囲内に値を制限します。
     */
    GMVector4D  clamp(const GMVector4D& min, const GMVector4D& max) const;
    
    /*!
        @method     distance
        与えられたベクトルとの距離を計算します。
     */
    double      distance(const GMVector4D& vec) const;
    
    /*!
        @method     distanceSq
        与えられたベクトルとの距離の二乗を計算します。
     */
    double      distanceSq(const GMVector4D& vec) const;
    
    /*!
        @method     dot
        与えられたベクトルとのドット積（内積）を計算します。
     */
    double      dot(const GMVector4D& vec) const;
    
    /*!
        @method     equals
        与えられたベクトルと等しいかどうかを判定します。
     */
    bool        equals(const GMVector4D& vec, double accuracy) const;
    
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
    GMVector4D  normal() const;
    
    /*!
        @method     normalize
        このベクトルを正規化して、参照をリターンします。
     */
    GMVector4D& normalize();
    
    /*!
        @method     transform
     */
    GMVector4D  transform(const GMMatrix& matrix) const;
    
    /*!
     @method     transform
     */
    GMVector4D  transform(const GMQuat& quat) const;
    
public:
    /*!
        @task   演算子のオーバーロード
     */
    
    /*!
        @method     operator=
     */
    GMVector4D& operator=(const GMVector4D& vec);
    
    
    /*!
        @method     operator-
     */
    GMVector4D operator-() const;
    
    /*!
        @method     operator+
     */
    GMVector4D operator+(const GMVector4D& vec) const;
    
    /*!
        @method     operator-
     */
    GMVector4D operator-(const GMVector4D& vec) const;
    
    /*!
        @method     operator*
     */
    GMVector4D operator*(const GMVector4D& vec) const;
    
    /*!
        @method     operator/
     */
    GMVector4D operator/(const GMVector4D& vec) const;
    
    /*!
        @method     operator*
     */
    GMVector4D operator*(double value) const;
    
    /*!
        @method     operator/
     */
    GMVector4D operator/(double value) const;
    
    friend GMVector4D operator*(double value, const GMVector4D& vec);
    
    
    /*!
        @method     operator+=
     */
    GMVector4D& operator+=(const GMVector4D& vec);
    
    /*!
        @method     operator-=
     */
    GMVector4D& operator-=(const GMVector4D& vec);
    
    /*!
        @method     operator*=
     */
    GMVector4D& operator*=(const GMVector4D& vec);
    
    /*!
        @method     operator/=
     */
    GMVector4D& operator/=(const GMVector4D& vec);
    
    /*!
        @method     operator*=
     */
    GMVector4D& operator*=(double value);
    
    /*!
        @method     operator/=
     */
    GMVector4D& operator/=(double value);
    
    
    /*!
        @method     operator==
     */
    bool        operator==(const GMVector4D& vec) const;
    
    /*!
        @method     operator!=
     */
    bool        operator!=(const GMVector4D& vec) const;
    
};


#endif  //#ifndef __GL_VECTOR4D_H__


