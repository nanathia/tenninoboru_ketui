#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

namespace spriter{

class Ref;

class MainlineKey
{
public:
	MainlineKey( XMLElement* e );
	~MainlineKey(void);
	int time;
	vector< Ref* > boneRefs;
	vector< Ref* > objectRefs;
};

}