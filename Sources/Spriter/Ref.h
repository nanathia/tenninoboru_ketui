#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

namespace spriter{

class Ref
{
public:
	Ref( XMLElement* e );
	~Ref(void);

	int parent;
	int timeline;
	int key;
};

}