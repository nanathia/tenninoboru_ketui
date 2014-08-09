//
//  GMSaveBox.h
//  Game Framework
//
//  Created by numata on 09/07/25.
//  Copyright 2009-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_SAVE_BOX_H__
#define __GM_SAVE_BOX_H__

#include "GMObject.h"

#include <string>


#pragma mark -
#pragma mark SaveBox Class Declaration

/*!
    @class  GMSaveBox
    @group  System
    @abstract ゲームの実行状態を保存し、読み込み直すためのクラスです。
    このクラスは、クラスメソッドだけを使って利用します。
 */
class GMSaveBox : public GMObject {

#pragma mark -
#pragma mark Friend Function Declaration

    friend void __GMSetupSaveBox();
    friend void __GMCleanUpSaveBox();


#pragma mark -
#pragma mark Constructor / Destructor

private:
    GMSaveBox();
    ~GMSaveBox();


#pragma mark -
#pragma mark 値が設定されていることの確認と、保存の実行

public:
    /*!
        @task 値が設定されていることの確認と、保存の実行
     */

    /*!
        @method HasValue
        指定したキーに対応する値が存在することを確認します。
     */
    bool    HasValue(const std::string& key) const;

    /*!
        @method RemoveValue
        指定したキーに対応する値があれば取り除きます。
     */
    void    RemoveValue(const std::string& key) const;

    /*!
        @method Save
        @abstract 保存を実行します。
        <p>値を設定したあと、この関数を呼び出すまでは、確実に設定された値が保存されることは保証されません。
        また、この関数が呼び出されなくても、設定された値が保存されることはあります。</p>
     */
    void    Save();
    
public:
#pragma mark -
#pragma mark 値の取得
    /*!
        @task 値の取得
     */
    
    /*!
        @method GetBoolValue
        名前を指定して bool 値を取得します。
     */
    bool        GetBoolValue(const std::string& key) const;

    /*!
        @method GetDoubleValue
        名前を指定して double 値を取得します。
     */
    double      GetDoubleValue(const std::string& key) const;
    
    /*!
        @method GetFloatValue
        名前を指定して float 値を取得します。
     */
    float       GetFloatValue(const std::string& key) const;

    /*!
        @method GetIntValue
        名前を指定して int 値を取得します。
     */
    int         GetIntValue(const std::string& key) const;
    
    /*!
        @method GetStringValue
        名前を指定して文字列を取得します。
     */
    std::string GetStringValue(const std::string& key) const;
    
public:
#pragma mark -
#pragma mark 値の設定
    /*!
        @task 値の設定
     */
    
    /*!
        @method SetBoolValue
        名前を指定して bool 値を保存します。
     */
    void        SetBoolValue(const std::string& key, bool boolValue);

    /*!
        @method SetDoubleValue
        名前を指定して double 値を保存します。
     */
    void        SetDoubleValue(const std::string& key, double doubleValue);
    
    /*!
        @method SetFloatValue
        名前を指定して float 値を保存します。
     */
    void        SetFloatValue(const std::string& key, float floatValue);

    /*!
        @method SetIntValue
        名前を指定して int 値を保存します。
     */
    void        SetIntValue(const std::string& key, int intValue);

    /*!
        @method SetStringValue
        名前を指定して文字列を保存します。
     */
    void        SetStringValue(const std::string& key, const std::string& strValue);

    
#pragma mark -
#pragma mark Debug Support

public:
    std::string to_s() const;

};


#endif  //#ifndef __GM_SAVE_BOX_H__

