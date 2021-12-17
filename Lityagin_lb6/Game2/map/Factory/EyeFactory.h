#ifndef GAME_EYEFACTORY_H
#define GAME_EYEFACTORY_H

#include "../Units/Eye.h"
#include "ObjectFactory.h"

class EyeFactory: public ObjectFactory{
public:
    Unit* CreateUnit() override;
};

#endif //GAME_EYEFACTORY_H
