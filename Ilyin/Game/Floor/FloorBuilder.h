#ifndef GAME_FLOORBUILDER_H
#define GAME_FLOORBUILDER_H

#include "Floor.h"

class FloorBuilder {
public:
    virtual void GeneratNormalCells() = 0;
    virtual void GeneratWallCells() = 0;
    virtual void GeneratEntryCell() = 0;
    virtual void GeneratExitCell() = 0;
};


#endif //GAME_FLOORBUILDER_H
