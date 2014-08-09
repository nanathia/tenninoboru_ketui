#pragma once
#include <vector>
#include <string>
#include "SpatialInfo.h"
#include "tinyxml2.h"
#include "timelinekey.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{

class SpatialTimelineKey :
	public TimelineKey
{
public:
	SpatialTimelineKey( XMLElement* e );
	virtual ~SpatialTimelineKey(void);

	SpatialInfo info;
};

}