#include "Timeline.h"
#include "TimelineKey.h"
#include "SpatialTimelineKey.h"
#include "BoneTimelineKey.h"
#include "SpriteTimelineKey.h"

namespace spriter{

Timeline::Timeline( XMLElement* e )
{
	name = e->Attribute( "name" );
	const char* type = e->Attribute( "object_type" );
	if( !type ){
		objectType = SPRITE;
	}else{
		string str = e->Attribute( "object_type" );
		if( str == "bone" ){
			objectType = BONE;
		}
	}

	XMLElement* c = e->FirstChildElement();
	while(c){
		string str = c->Name();
		if( str == "key" ){
			if( objectType == SPRITE ){
				keys.push_back( new SpriteTimelineKey( c ) );
			}else if( objectType == BONE ){
				keys.push_back( new BoneTimelineKey( c ) );
			}
		}else{
			int* a = 0;
            *a = 0xffffffff;
		}
		c = c->NextSiblingElement();
	}
}


Timeline::~Timeline(void)
{
	int size = (int)keys.size();
	for( int i = 0; i < size; i++ ){
		delete keys[ i ];
        keys[ i ] = 0;
	}
}

}