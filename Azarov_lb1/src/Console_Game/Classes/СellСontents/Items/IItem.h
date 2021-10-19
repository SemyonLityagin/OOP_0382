#ifndef CONSOLE_GAME_IITEM_H
#define CONSOLE_GAME_IITEM_H

#include "unq_p.h"

class IItem{

public:
    virtual unq_p<IItem> clone() = 0;
};

#endif //CONSOLE_GAME_IITEM_H
