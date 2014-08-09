#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
#include "CharacterMap.h"
#include "SpatialInfo.h"
#include "Entity.h"
#include "Folder.h"
#include <map>

using namespace std;
using namespace tinyxml2;

namespace spriter{

class CharacterMap;
class SpatialInfo;
class Entity;
class Folder;

class ScmlObject
{
public:
	ScmlObject( const char* filename );
	~ScmlObject(void);
    
    vector< Folder* > folders;
    Animation* getAnimation(const string& entityName, const string& animationName);
    
private:
    
	void setCurrentTime( double newTime );
	void applyCharacterMap( CharacterMap charMap, bool reset );

	map<string, Entity* > entities;
	int currentEntity;
	int currentAnimation;

	double currentTime;

	XMLDocument* document;
};

}