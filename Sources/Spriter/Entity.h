#pragma once
#include <vector>
#include <string>
#include <map>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{

class Animation;
class CharacterMap;

class Entity
{
public:
	Entity( XMLElement* e );
	~Entity(void);
	string name;
	vector< CharacterMap* > characterMaps;
	map<string, Animation* > animations;
};

}