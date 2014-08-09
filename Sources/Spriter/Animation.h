#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class GMVector3D;

namespace spriter{

class MainlineKey;
class SpatialTimelineKey;
class Timeline;
class TimelineKey;
class Ref;

class Animation
{
public:
	Animation( XMLElement* e );
	~Animation(void);
	enum LOOP_TYPE{
		NO_LOOPING,
		LOOPING,
	};

    // 
	void setCurrentTime(double newTime, const GMVector3D& pos, const double scale, const GMVector3D& rota);
	void updateCharacter(const MainlineKey& mainKey, int newTime, const GMVector3D& pos, const double scale, const GMVector3D& rota);
	MainlineKey* mainlineKeyFromTime( int time );
	TimelineKey* keyFromRef( const Ref& ref, int newTime ) const;

	string name;
	int length;
	LOOP_TYPE loopType;
    vector< MainlineKey* > mainlineKeys;
	vector< Timeline* > timelines;
};

}
