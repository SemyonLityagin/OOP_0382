#ifndef GAME_OBJECTFACTORY_H
#define GAME_OBJECTFACTORY_H

#include "../Units/Unit.h"

class ObjectFactory{
public:
    virtual Unit* CreateUnit();
};

#endif //GAME_OBJECTFACTORY_H
