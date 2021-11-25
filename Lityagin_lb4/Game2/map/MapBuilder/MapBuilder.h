#ifndef GAME_MAPBUILDER_H
#define GAME_MAPBUILDER_H

#include "./Field/Field.h"

class MapBuilder{
public:
    virtual void BuildEnter();
    virtual void BuildExit();
    virtual void BuildWalls();
    virtual void BuildFloor();
    virtual Field* ReturnField();
};

#endif //GAME_MAPBUILDER_H
