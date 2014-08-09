//
//  GMBasicEffect.h
//  Game Framework
//
//  Created by numata on Jan 11, 2011.
//  Copyright 2011-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_BASIC_EFFECT_H__
#define __GM_BASIC_EFFECT_H__


#include "GMEffect.h"
#include "GMMatrix.h"
#include "GMTexture2D.h"


typedef enum {
    GMFogModeLinear,
    GMFogModeExp,
    GMFogModeExp2,
} GMFogMode;


struct __GMMaterial {
    GMVector3D  diffuse;
    GMVector3D  specular;
    GMVector3D  ambient;
    GMVector3D  emission;
    double      shininess;
    
    __GMMaterial()
    {
        diffuse = GMVector3D(0.8, 0.8, 0.8);
        specular = GMVector3D(0.0, 0.0, 0.0);
        ambient = GMVector3D(0.2, 0.2, 0.2);
        emission = GMVector3D(0.0, 0.0, 0.0);
        shininess = 0.0;
    }
    
    void set()
    {
        {
            GLfloat params[] = { (GLfloat)diffuse.x, (GLfloat)diffuse.y, (GLfloat)diffuse.z, 1.0f };
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
        }
        {
            GLfloat params[] = { (GLfloat)specular.x, (GLfloat)specular.y, (GLfloat)specular.z, 1.0f };
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, params);
        }
        {
            GLfloat params[] = { (GLfloat)ambient.x, (GLfloat)ambient.y, (GLfloat)ambient.z, 1.0f };
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);
        }
        {
            GLfloat params[] = { (GLfloat)emission.x, (GLfloat)emission.y, (GLfloat)emission.z, 1.0f };
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, params);
        }
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat)shininess);
    }
    
};


/*!
    @class      GMBasicEffect
    @group      Graphics
    @abstract   行列、ライティング、テクスチャ、マテリアルを管理し、シェーダとのやり取りを行うためのクラスです。
    <p>カメラ特性などの射影変換の設定はプロジェクション行列で、カメラの向きなどの設定はビュー行列で、各モデルの位置などの設定はワールド行列で行います。</p>
    <p>アルファブレンディングの設定は、GMDraw クラスで管理されています。また、ビューの大きさとポイントスプライトの設定は GMGraphics クラスで管理されています。</p>
    <p>Globals.cpp の設定で、GMShaderEnabled の値が true に設定されていなければ、OpenGL（あるいは OpenGL ES）の固定シェーダが利用されます。</p>
 */
class GMBasicEffect : public GMEffect {
    
    GMMatrix        mProjectionMatrix;
    GMMatrix        mViewMatrix;
    GMMatrix        mWorldMatrix;

    bool            mIsFogEnabled;
    GMColor         mFogColor;
    GMFogMode       mFogMode;
    double          mFogNearZ;
    double          mFogFarZ;
    double          mFogDensity;

    bool            mIsLightingEnabled;
    
    GMTexture2D*    mTexture;
    bool            mIsTextureEnabled;

    __GMMaterial    mMaterial;
    
public:
    GMBasicEffect();
    virtual ~GMBasicEffect();
    
public:
    virtual void    begin();
    virtual void    end();
    
protected:
    virtual void    bindAttribLocations();
    virtual void    getUniformLocations();
    
public:
    /*!
        @task   各種行列の管理
     */
    
    /*!
        @method     getProjectionMatrix
     */
    GMMatrix    getProjectionMatrix() const;
    
    /*!
        @method     getViewMatrix
     */
    GMMatrix    getViewMatrix() const;
    
    /*!
        @method     getWorldMatrix
     */
    GMMatrix    getWorldMatrix() const;
    
    /*!
        @method     setProjectionMatrix
     */
    void        setProjectionMatrix(const GMMatrix& matrix);
    
    /*!
        @method     setViewMatrix
     */
    void        setViewMatrix(const GMMatrix& matrix);
    
    /*!
        @method     setWorldMatrix
     */
    void        setWorldMatrix(const GMMatrix& matrix);


    /*!
        @task   フォグ設定
     */

    /*!
        @method     enableFog
        @abstract   フォグを有効または無効にします。
     */
    void        enableFog(bool flag);

    /*!
        @method     getFogColor
        @abstract   フォグの色を取得します。
     */
    GMColor     getFogColor() const;

    /*!
        @method     getFogDensity
        @abstract   フォグをGMFogModeExpかGMFogModeExp2のいずれかのモードで使用する際の密度を取得します。
     */
    double      getFogDensity() const;

    /*!
        @method     setFogMode
        @abstract   フォグのモードを取得します。
     */
    GMFogMode   getFogMode() const;

    /*!
        @method     getFogRangeFarZ
        @abstract   フォグをGMFogModeLinearモードで使用する際の遠景位置を取得します。
     */
    double      getFogRangeFarZ() const;

    /*!
        @method     getFogRangeNearZ
        @abstract   フォグをGMFogModeLinearモードで使用する際の近景位置を取得します。
     */
    double      getFogRangeNearZ() const;

    /*!
        @method     isFogEnabled
        @abstract   フォグを有効にしているかどうかを取得します。
     */
    bool        isFogEnabled() const;

    /*!
        @method     setFogColor
        @abstract   フォグの色を設定します。
        デフォルトの色は (0, 0, 0, 0) です。
     */
    void        setFogColor(const GMColor& color);

    /*!
        @method     setFogDensity
        @abstract   フォグをGMFogModeExpかGMFogModeExp2のいずれかのモードで使用する際の密度を設定します。
        デフォルトの密度は1.0です。正の値だけが有効です。
     */
    void        setFogDensity(double density);

    /*!
        @method     setFogMode
        @abstract   フォグのモードを指定します。
        GMFogModeExp, GMFogModeExp2, GMFogModeLinearのいずれかを指定します。
        デフォルトは GMFogModeExp です。
     */
    void        setFogMode(GMFogMode mode);

    /*!
        @method     getFogRangeFarZ
        @abstract   フォグをGMFogModeLinearモードで使用する際の近景と遠景の位置を指定します。
        デフォルトの近景位置は0.0、遠景位置は1.0です。
     */
    void        setFogRange(double nearZ, double farZ);


    /*!
        @task   ライティング設定
     */

    /*!
        @method     enableLighting
        @abstract   ライティングを有効または無効にします。
     */
    void        enableLighting(bool flag);
    
    /*!
        @method     isLightingEnabled
        @abstract   ライティングを有効にしているかどうかを取得します。
     */
    bool        isLightingEnabled() const;


    /*!
        @task   ライト設定
     */

    /*!
        @method     enableLight
        @abstract   index番目のライトを有効または無効にします。
     */
    void        enableLight(int index, bool flag);
    
    /*!
        @method     setLightAmbientColor
        @abstract   index番目のライトのアンビエント色（環境光の色）を設定します。
     */
    void        setLightAmbientColor(int index, const GMColor& color);

    /*!
        @method     setLightAttenuation
        @abstract   index番目のライトの、光の減衰率を指定します。
     */
    void        setLightAttenuation(int index, double constant, double linear, double quadratic);

    /*!
        @method     setLightDiffuseColor
        @abstract   index番目のライトのディフューズ色（拡散反射光の色）を設定します。
     */
    void        setLightDiffuseColor(int index, const GMColor& color);
    
    /*!
        @method     setLightSpecularColor
        @abstract   index番目のライトのスペキュラ色（鏡面反射光の色）を設定します。
     */
    void        setLightSpecularColor(int index, const GMColor& color);
    
    /*!
        @method     setLightTypeAsParallel
        @abstract   index番目のライトを、方向を指定して平行光源として設定します。
     */
    void        setLightTypeAsParallel(int index, const GMVector3D& vecDirection);
    
    /*!
        @method     setLightTypeAsPoint
        @abstract   index番目のライトを、位置を指定して点光源として設定します。
     */
    void        setLightTypeAsPoint(int index, const GMVector3D& vecPosition);
    
    /*!
        @method     setLightTypeAsSpot
        @abstract   位置、方向、開き角度、拡散の度合いを指定して、スポットライトとしてライトを設定します。
        拡散の度合いを示す exponent には 0.0〜128.0 の値を指定します。
     */
    void        setLightTypeAsSpot(int index, const GMVector3D& vecPosition, const GMVector3D& vecDirection, double radAngle, double exponent);    

    
    /*!
        @task   テクスチャ設定
     */
    
    /*!
        @method     enableTexture
        @abstract   テクスチャを有効または無効にします。
     */
    void            enableTexture(bool flag);

    /*!
        @method     getTexture
        @abstract   現在設定されているテクスチャを取得します。
     */
    GMTexture2D*    getTexture() const;

    /*!
        @method     isTextureEnabled
        @abstract   テクスチャが有効化されているかどうかを取得します。
     */
    bool            isTextureEnabled() const;

    /*!
        @method     setTexture
        @abstract   テクスチャを設定します。
     */
    void            setTexture(GMTexture2D* tex);


    /*!
        @task   マテリアル設定
     */
    
    /*!
        @method     getMaterialAmbient
        @abstract   マテリアルのアンビエント色（環境反射の色）を取得します。
     */
    GMColor         getMaterialAmbient() const;

    /*!
        @method     getMaterialDiffuse
        @abstract   マテリアルのディフューズ色（拡散反射光の色）を取得します。
     */
    GMColor         getMaterialDiffuse() const;

    /*!
        @method     getMaterialEmission
        @abstract   マテリアルのエミッション色（自己発光の色）を取得します。
     */
    GMColor         getMaterialEmission() const;

    /*!
        @method     getMaterialShininess
        @abstract   マテリアルの輝度を取得します。
     */
    double          getMaterialShininess() const;

    /*!
        @method     getMaterialSpecular
        @abstract   マテリアルのスペキュラ色（鏡面反射光の色）を取得します。
     */
    GMColor         getMaterialSpecular() const;

    /*!
        @method     setMaterial
        @abstract   マテリアルの設定を行います。この設定は、ライティングが有効な環境でのみ反映されます。
        引数なしで実行した場合、OpenGL 標準のデフォルトマテリアル設定が使用されます（ディフューズ (0.8, 0.8, 0.8)、スペキュラ (0, 0, 0)、アンビエント (0.2, 0.2, 0.2)、エミッション (0, 0, 0)、輝度 0.0）。
     */
    void            setMaterial(const GMVector3D& diffuse = GMVector3D(0.8, 0.8, 0.8), const GMVector3D& specular = GMVector3D::Zero, const GMVector3D& ambient = GMVector3D(0.2, 0.2, 0.2), const GMVector3D& emission = GMVector3D::Zero, const double shininess = 0.0);

};


#endif  //#ifndef __GM_BASIC_EFFECT_H__

