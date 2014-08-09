#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
#include "SpatialInfo.h"
using namespace std;
using namespace tinyxml2;
class GMVector3D;

namespace spriter{
    
class TimelineKey
{
public:
	TimelineKey( XMLElement* e );
	virtual ~TimelineKey(void);

	enum INTERPOLATION_TYPE{
		INSTANT,
		LINEAR,
		QUADRATIC,
		CUBIC,
	};

	int time;
	int curveType;
	double c1;
	double c2;
	
	virtual void paint(const GMVector3D& pos, const double scale, const GMVector3D& rota) const{
		//CCHALT( me! );
	}
	TimelineKey* interpolate( TimelineKey* nextKey, int nextKeyTime, double currentTime );
	double getTWithNextKey( TimelineKey* nextKey, int nextKeyTime, double currentTime );
	virtual TimelineKey* linear( TimelineKey* keyB, double t ){
        
		return 0;
	};
	virtual SpatialInfo getInfo() const{
		return 0;
	};
	virtual void setInfo( SpatialInfo ){
	}
};

}