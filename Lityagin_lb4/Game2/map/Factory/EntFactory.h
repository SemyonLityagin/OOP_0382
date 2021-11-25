#ifndef GAME_ENTFACTORY_H
#define GAME_ENTFACTORY_H

#include "../Units/Ent.h"
#include "ObjectFactory.h"

class EntFactory: public ObjectFactory{
public:
    Unit* CreateUnit() override;
};

#endif //GAME_ENTFACTORY_H
