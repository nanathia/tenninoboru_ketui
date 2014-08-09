#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;



namespace spriter{

class MapInstruction;

class CharacterMap
{
public:
	CharacterMap( XMLElement* e );
	~CharacterMap(void);

	string name;
	vector< MapInstruction* > maps;
};

}