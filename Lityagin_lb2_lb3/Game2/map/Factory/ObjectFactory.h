#ifndef GAME_OBJECTFACTORY_H
#define GAME_OBJECTFACTORY_H

#include "../Units/Unit.h"

class ObjectFactory{
public:
    virtual Unit* CreateUnit() = 0;
};

#endif //GAME_OBJECTFACTORY_H
