//
//  GMQuat.h
//  Game Framework
//
//  Created by numata on Jan 02, 2011.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_QUAT_H__
#define __GM_QUAT_H__


#include "GMObject.h"

struct GMMatrix;
struct GMVector3D;


/*
    http://blogs.msdn.com/b/ito/archive/2009/05/01/more-bones-04.aspx より
    クォータニオンを使うと便利
        ・アニメーションデータが多すぎるので圧縮したい（キーフレーム間の回転補間）
        ・自由に回転状態を変化させたい（岩などのオブジェクトが地面の起伏の状態によって回転状態が変化する場合、飛行機などの姿勢制御）
        ・回転状態を変化させる必要はないけど対象となるオブジェクトが大量にある（爆発などで大量の破片がランダムに回転しながら飛び散るエフェクト）
    オイラー角で十分
        ・制限された回転（FPS、TPSなどのカメラコントロール）
        ・回転状態を変化する必要がない（爆発などで少数の破片がランダムに回転しながら飛び散るエフェクト）
        ・誤差があっても大丈夫（回転の結合が短時間だけ必要な場合、上記のエフェクトなどカットシーン的な場面で使われる回転） 
 */

/*!
    @class      GMQuat
    @group      Math
    @abstract   クォータニオンを表現するためのクラスです。
 */
struct GMQuat : public GMObject {
    
public:
    /*!
        @const  Identity
     */
    static const GMQuat&    Identity;

public:
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
    
    /*!
        @task   生成メソッド
     */
    
    /*!
        @method     CreateFromAxisAngle
     */
    static GMQuat   CreateFromAxisAngle(const GMVector3D& axis, double angle);

    /*!
        @method     CreateFromYawPitchRoll
     */
    static GMQuat   CreateFromYawPitchRoll(double yaw, double pitch, double roll);
    

    /*!
        @task   数値補完
     */
    
    /*!
        @method     EaseIn
        2つのクォータニオンのEase-Inの補間を計算します。
     */
    static GMQuat   EaseIn(const GMQuat& q1, const GMQuat& q2, double amount);

    /*!
        @method     EaseInOut
        2つのクォータニオンのEase-In/Ease-Outの補間を計算します。
     */
    static GMQuat   EaseInOut(const GMQuat& q1, const GMQuat& q2, double amount);

    /*!
        @method     EaseOut
        2つのクォータニオンのEase-Outの補間を計算します。
     */
    static GMQuat   EaseOut(const GMQuat& q1, const GMQuat& q2, double amount);

    /*!
        @method     Lerp
        2つのクォータニオンの線形補間を計算します。
     */
    static GMQuat   Lerp(const GMQuat& q1, const GMQuat& q2, double amount);

    /*!
        @method     Slerp
        2つのクォータニオンの球状線形補間を計算します。
     */
    static GMQuat   Slerp(const GMQuat& q1, const GMQuat& q2, double amount);
    
    
    /*!
        @task   コンストラクタ
     */
    
    /*!
        @method     GMQuat
     */
    GMQuat();
    
    /*!
        @method     GMQuat
     */
    GMQuat(double x, double y, double z, double w);
    
    /*!
        @method     GMQuat
     */
    GMQuat(const GMQuat& quat);
    
    /*!
        @method     GMQuat
     */
    GMQuat(const GMMatrix& mat);
    
    /*!
        @task   メインの操作
     */
    
    /*!
        @method     concat
        新しいクォータニオンを連結します。
     */
    GMQuat      concat(const GMQuat& quat) const;

    /*!
        @method     conjugate
        クォータニオンの共役を計算します。
     */
    GMQuat&     conjugate();

    /*!
        @method     dot
        クォータニオンの内積を計算します。
     */
    double      dot(const GMQuat& quat) const;
    
    /*!
        @method     equals
        クォータニオンが等しいかどうかを判定します。
     */
    bool        equals(const GMQuat& quat, double accuracy) const;
    
    /*!
        @method     inverse
        逆クォータニオンをリターンします。
     */
    GMQuat      inverse() const;
    
    /*!
        @method     length
        クォータニオンの長さを計算します。
     */
    double      length() const;
    
    /*!
        @method     lengthSq
        クォータニオンの長さの二乗を計算します。
     */
    double      lengthSq() const;
    
    /*!
        @method     normal
        単位クォータニオンを作成します。
     */
    GMQuat      normal() const;
    
    /*!
        @method     normalize
        このクォータニオンを正規化して、その参照をリターンします。
     */
    GMQuat&     normalize();
    
    /*!
        @method     toMatrix
        このクォータニオンと同様の回転を表す4x4行列をリターンします。
     */
    GMMatrix    toMatrix() const;
    
    /*!
        @task   演算子のオーバーロード
     */
    
    /*!
        @method     operator=
     */
    GMQuat&     operator=(const GMQuat& quat);    
    
    /*!
        @method     operator-
     */
    GMQuat      operator-() const;
    
    /*!
        @method     operator+
     */
    GMQuat      operator+(const GMQuat& quat) const;
    
    /*!
        @method     operator-
     */
    GMQuat      operator-(const GMQuat& quat) const;
    
    /*!
        @method     operator*
     */
    GMQuat      operator*(const GMQuat& quat) const;
    
    /*!
        @method     operator*
     */
    GMQuat      operator*(double scale) const;
    
    /*!
        @method     operator/
     */
    GMQuat      operator/(const GMQuat& quat) const;
    
    /*!
        @method     operator/
     */
    GMQuat      operator/(double value) const;

    
    /*!
        @method     operator+=
     */
    GMQuat&     operator+=(const GMQuat& quat);
    
    /*!
        @method     operator-=
     */
    GMQuat&     operator-=(const GMQuat& quat);
    
    /*!
        @method     operator*=
     */
    GMQuat&     operator*=(const GMQuat& quat);
    
    /*!
        @method     operator=
     */
    GMQuat&     operator*=(double scale);
    
    /*!
        @method     operator/=
     */
    GMQuat&     operator/=(const GMQuat& quat);
    
    /*!
        @method     operator/=
     */
    GMQuat&     operator/=(double value);

    
    /*!
        @method     operator==
     */
    bool        operator==(const GMQuat& quat) const;
    
    /*!
        @method     operator!=
     */
    bool        operator!=(const GMQuat& quat) const;

};


#endif  //#ifndef __GM_QUAT_H__


