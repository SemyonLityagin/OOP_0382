#ifndef GAME_THING_H
#define GAME_THING_H

#include "../MapBuilder/Field/Cell/Object.h"
#include "../Units/Hero.h"

class Thing : public Object{
public:
    virtual void Interaction(Hero* obj);
};

#endif //GAME_THING_H
