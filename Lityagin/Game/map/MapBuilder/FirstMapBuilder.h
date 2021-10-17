#ifndef GAME_FIRSTMAPBUILDER_H
#define GAME_FIRSTMAPBUILDER_H

#include "MapBuilder.h"
#include "Field/Field.h"
#include "Field/Cell/Cell.h"

#define FloorPNG "../texture/Cell.png"
#define EnterPNG "../texture/CellStart.png"
#define ExitPNG "../texture/CellEnd.png"
#define WallPNG "../texture/CellWall.png"

class FirstMapBuilder : public MapBuilder{
private:
    Field* field;
public:
    FirstMapBuilder();
    ~FirstMapBuilder();
    void Reset();
    void BuildEnter() override;
    void BuildExit() override;
    void BuildWalls() override;
    void BuildFloor() override;
    Field* ReturnField();
};

#endif //GAME_FIRSTMAPBUILDER_H
