

#ifndef __Karakuri2_Mac__syokutyuuFactory__
#define __Karakuri2_Mac__syokutyuuFactory__

#include "Karakuri.h"

class syokutyuu;
class EAStrategy;
class SKEnemy;

class syokutyuuFactory{
public:
    EAStrategy* create(SKEnemy*, const char* nextName);
};

#endif