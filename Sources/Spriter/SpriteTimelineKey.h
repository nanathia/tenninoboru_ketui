#pragma once
#include "spatialtimelinekey.h"

namespace spriter{

class SpriteTimelineKey :
	public SpatialTimelineKey
{
public:
	SpriteTimelineKey( XMLElement* e );
	~SpriteTimelineKey(void);
	
    SpatialInfo getInfo() const{
		return SpatialTimelineKey::info;
	};
	void setInfo( SpatialInfo s ){
		info = s;
	}

	void paint(const GMVector3D& pos, const double scale, const GMVector3D& rota) const override;
	TimelineKey* linear( TimelineKey* keyB, double t );

	int folder;
	int file;
	bool useDefaultPivot;
	double pivot_x;
	double pivot_y;

};

}