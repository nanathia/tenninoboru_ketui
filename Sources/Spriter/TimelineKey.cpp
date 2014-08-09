#include "TimelineKey.h"
#include "ScmlFunctions.h"

namespace spriter{

TimelineKey::TimelineKey( XMLElement* e ):
	time( 0 ),
	curveType( LINEAR )
{
	c1 = e->DoubleAttribute( "c1" );
	c2 = e->DoubleAttribute( "c2" );
	if( e->Attribute( "time" ) ){
		time = e->IntAttribute( "time" );
	}
}


TimelineKey::~TimelineKey(void)
{
}


TimelineKey* TimelineKey::interpolate( TimelineKey* nextKey, int nextKeyTime, double currentTime ){
	return linear( nextKey, ( getTWithNextKey( nextKey, nextKeyTime, currentTime ) ) );
}

double TimelineKey::getTWithNextKey( TimelineKey* nextKey, int nextKeyTime, double currentTime ){
	//ここが何してるのかがイマイチ分かんね
	//分かった。

	if( curveType == INSTANT || time == nextKey->time ){
		return 0;
	}

	//現在時間引くKeyA時間　割る　KeyB時間引くKeyA時間
	//つまりこれは補間の比率を出してるわけか。
	//割る方はつまり、全体時間。割られる方はつまり、その範囲での現在時間。
	//よって、変数tは0.0から1.0の線形の間を推移する値となる。
	double t = ( currentTime - time ) / ( nextKeyTime - time );

	//これより下は、補間モードが一次元以外の場合を指定された時用のものである。
	//おそらくは使うことはないだろうし、使っても理解することもない。やっていることさえわかっていれば問題はない。
	if( curveType == LINEAR ){
		return t;
	}else if( curveType == QUADRATIC ){
		return( ScmlFunctions::quadratic( 0.0, c1, 1.0, t ) );
	}else if( curveType == CUBIC ){
		return( ScmlFunctions::cubic( 0.0, c1, c2, 1.0, t ) );
	}
    
	return 0; // Runtime should never reach here        	
}

}