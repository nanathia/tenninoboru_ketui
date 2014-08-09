

#include "ESDestroy.h"

ESDestroy::ESDestroy():
EAStrategy()
{
    
}

ESDestroy::~ESDestroy(){
    
}

const char* ESDestroy::resetAction(SKEnemy *parent){
    return 0;
}

void ESDestroy::action(SKEnemy*){
    return;
}