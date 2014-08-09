#include "BoneTimelineKey.h"
#include "SpatialTimelineKey.h"
#include "ScmlFunctions.h"
#include "tinyxml2.h"
using namespace tinyxml2;

namespace spriter{

    BoneTimelineKey::BoneTimelineKey( XMLElement* e ):
	SpatialTimelineKey( e ),
	length( 200 ),
	width( 10 )
{

}


BoneTimelineKey::~BoneTimelineKey(void)
{
}


TimelineKey* BoneTimelineKey::linear( TimelineKey* keyB, double t ){
    
	BoneTimelineKey* returnKey = new BoneTimelineKey( *this );
	SpatialTimelineKey* key_B = dynamic_cast< SpatialTimelineKey* >( keyB );
	returnKey->info = ScmlFunctions::linear( this->info, key_B->info, this->info.spin, t );

	return returnKey;
}

}