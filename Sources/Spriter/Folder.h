#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{
    
class File;

class Folder
{
public:
	Folder( XMLElement* e );
	~Folder(void);

	string name;
	vector< File* > files;
};

}