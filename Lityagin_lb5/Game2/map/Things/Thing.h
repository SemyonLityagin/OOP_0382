#ifndef GAME_THING_H
#define GAME_THING_H

#include "../Units/Object.h"
#include "../Units/Hero.h"

class Thing : public Object{
public:
    virtual ~Thing()=default;
    virtual bool IsAvailable();
};

#endif //GAME_THING_H
