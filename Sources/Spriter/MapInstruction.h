#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{
    
class MapInstruction
{
public:
	MapInstruction(void);
	~MapInstruction(void);

	int folder;
	int file;
	int tarFolder;
	int tarFile;
};

}