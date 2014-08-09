#pragma once

#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{
    
class MyTexture;

class File
{
public:
	File( XMLElement* e );
	~File(void);

	string name;
	double pivotX;
	double pivotY;

	MyTexture* tex;
};

}