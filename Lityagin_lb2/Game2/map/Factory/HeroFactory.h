#ifndef GAME_HEROFACTORY_H
#define GAME_HEROFACTORY_H

#include "../Units/Hero.h"
#include "ObjectFactory.h"

class HeroFactory: public ObjectFactory{
public:
    Unit* CreateUnit() override;
};


#endif //GAME_HEROFACTORY_H
