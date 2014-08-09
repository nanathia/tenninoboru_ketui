#pragma once

#include "SpatialInfo.h"
#include "Karakuri.h"

namespace spriter{

class ScmlObject;
class Animation;
class Entity;
    
class ScmlFunctions
{
    static Animation* m_currentAnimation;
    
public:
	ScmlFunctions(void);
	~ScmlFunctions(void);

	static ScmlObject* nowScmlFile;

    // セットテクスチャの要領で、scml をセット。
	static void SetScml( ScmlObject* );
    // エンティティ（キャラクター）名と、アニメーション名の設定
    static bool setAnimation(const char* entity, const char* animation);
    // 描画する。床に立つように描かれ、他の情報は指定できる。
    // ポジション、縮尺、０〜１でのアニメーションの補間値指定。
    static void draw(const GMVector3D& pos, double scale, const GMVector3D& rota, double ratio);
	static void DeleteScml();

	static double linear( double a, double b, double t );
	static SpatialInfo linear( const SpatialInfo& infoA, const SpatialInfo& infoB, int spin, double t );
	static double angleLinear( double angleA, double angleB, int spin, double t );
	static double quadratic( double a, double b, double c, double t );
	static double cubic( double a, double b, double c, double d, double t );
    
    static double m_sortNum;
};

}