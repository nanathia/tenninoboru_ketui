#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{

class TimelineKey;

class Timeline
{
public:
	Timeline( XMLElement* e );
	~Timeline(void);
	enum OBJECT_TYPE{
		SPRITE,
		BONE,
		BOX,
		POINT,
		SOUND,
		ENTITY,
		VARIABLE,
	};

	string name;
	int objectType;
	vector< TimelineKey* > keys;
};

}