#ifndef CONSOLE_GAME_ICREATURE_H
#define CONSOLE_GAME_ICREATURE_H

#include "unq_p.h"

class ICreature {

public:
    virtual unq_p<ICreature> clone() = 0;
};

#endif //CONSOLE_GAME_ICREATURE_H
