#include "SpatialTimelineKey.h"

namespace spriter{

SpatialTimelineKey::SpatialTimelineKey( XMLElement* e ):
	TimelineKey( e ),
	info( e->FirstChildElement() )
{
	if( e->Attribute( "spin" ) ){
		info.spin = e->IntAttribute( "spin" );
	}
}


SpatialTimelineKey::~SpatialTimelineKey(void)
{
}

}