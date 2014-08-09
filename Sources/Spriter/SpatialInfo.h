#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{
    
class SpatialInfo
{
public:
	SpatialInfo( XMLElement* e );
	SpatialInfo( void );
	~SpatialInfo(void);

	double x;
	double y;
	double angle;
	double scaleX;
	double scaleY;
	double a;
	int spin;


	//解釈保留だ
	//解決した。親子関係を構成してそれをインスタンスとして返すのだ。オールコピーでいいだろう。
	SpatialInfo unmapFromParent( const SpatialInfo& parentInfo ) const;
};

}