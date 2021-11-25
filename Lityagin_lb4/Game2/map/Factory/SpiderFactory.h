#ifndef GAME_SPIDERFACTORY_H
#define GAME_SPIDERFACTORY_H

#include "../Units/Spider.h"
#include "ObjectFactory.h"

class SpiderFactory: public ObjectFactory{
public:
    Unit* CreateUnit() override;
};

#endif //GAME_SPIDERFACTORY_H
