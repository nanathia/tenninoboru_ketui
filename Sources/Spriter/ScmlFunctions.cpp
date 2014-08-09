#include "ScmlFunctions.h"
#include "ScmlObject.h"
#include "GameMain.h"
#include "Animation.h"
#include "Karakuri.h"
#include <string>

namespace spriter{

ScmlObject* ScmlFunctions::nowScmlFile = 0;
double ScmlFunctions::m_sortNum = 0;
Animation* ScmlFunctions::m_currentAnimation = 0;

ScmlFunctions::ScmlFunctions(void)
{
    int* a = 0;
    *a = 0xffffffff;
}


ScmlFunctions::~ScmlFunctions(void)
{
}


void ScmlFunctions::SetScml( ScmlObject* scml ){
	nowScmlFile = scml;
    m_sortNum = 0.9;
}
    
void ScmlFunctions::draw(const GMVector3D& pos, double scale, const GMVector3D& rota, double ratio){
    m_currentAnimation->setCurrentTime(GMMath::Lerp(0, static_cast<double>(m_currentAnimation->length), ratio), pos, scale, rota);
    m_sortNum = 0;
}



void ScmlFunctions::DeleteScml(){
	delete nowScmlFile;
	nowScmlFile = 0;
}


double ScmlFunctions::linear( double a, double b, double t ){
	//ここで分かりやすくしてみよう。aとbが２つの値だ。
	//tがタイムで、aとbとの間を推移しているもの。
	//ここから線形補完を求める式を作り、完成した値を返す。
	//キー間のあたいの保管で使う。

	return ( ( b - a ) * t ) + a;
}


SpatialInfo ScmlFunctions::linear( const SpatialInfo& infoA, const SpatialInfo& infoB, int spin, double t ){
	SpatialInfo resultInfo;
	//ここの部分も理解を深めておこう。
	//ますリザルトインフォというインスタンスを作成している。
	//これは、言わずとも返す値である。クラスの中に全てが入っている。
	//第一引数にインフォA,第二引数にインフォBとある。	
	//そして、第四引数にt。これはtimeだ。どう考えても。
	//ということは、インフォAが補間を考える上でのスタートフレーム、
	//インフォBがエンドフレームと考えられる。
	//タイムは、その間を推移するものだ。
	//先で作ったlinear関数にSpatialInfoクラスの中身を一つ一つ適応させて、
	//一気に中身を補間してしまおうという関数だろう。

	resultInfo.x = linear( infoA.x, infoB.x, t );
	resultInfo.y = linear( infoA.y, infoB.y, t );
	resultInfo.angle = angleLinear( infoA.angle, infoB.angle, spin, t );
	resultInfo.scaleX = linear( infoA.scaleX, infoB.scaleX, t );
	resultInfo.scaleY = linear( infoA.scaleY, infoB.scaleY, t );
	resultInfo.a = linear( infoA.a, infoB.a, t );

	return resultInfo;
}


double ScmlFunctions::angleLinear( double angleA, double angleB, int spin, double t ){
	if( spin == 0 ){
		return angleA;
	}
	if( spin > 0 ){
		if( ( angleB - angleA ) < 0 ){
			angleB += 360.0;
			//スピンが1の場合にアングルBに360度足している
		}
	}else if( spin < 0 ){
		if( ( angleB - angleA ) > 0 ){
			angleB -= 360.0;
			//上の分岐の逆
		}
	}

	return linear( angleA, angleB, t );

}


double ScmlFunctions::quadratic( double a, double b, double c, double t ){
	return linear( linear( a,b,t ), linear( b,c,t ), t );
}
    
double ScmlFunctions::cubic( double a, double b, double c, double d, double t ){
    // TODO: ScmlFunctions::cubic()の実装
    return 0.0;
};
    
bool ScmlFunctions::setAnimation(const char* entity, const char* animation){
    std::string e(entity);
    std::string a(animation);
    
    m_currentAnimation = nowScmlFile->getAnimation(e, a);
    
    return true;
}

}
