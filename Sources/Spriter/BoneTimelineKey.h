#pragma once
#include "spatialtimelinekey.h"

namespace spriter{

class BoneTimelineKey :
	public SpatialTimelineKey
{
public:
	BoneTimelineKey( XMLElement* e );
	~BoneTimelineKey(void);

	int length;
	int width;

	void paint(const GMVector3D& pos, const double scale, const GMVector3D& rota) const override{
        // Do nothing
	}
    
	SpatialInfo getInfo() const{
		return info;
	}
    
	void setInfo( SpatialInfo s ){
		info = s;
	}
    
	TimelineKey* linear( TimelineKey* keyB, double t );
};

}