#ifndef GAME_MAPBUILDERONE_H
#define GAME_MAPBUILDERONE_H

#include "MapBuilder.h"
#include "Field/Field.h"
#include "Field/Cell/Cell.h"

#define FloorPNG "/home/cruelcookie/CLionProjects/Game/texture/Cell.png"
#define EnterPNG "/home/cruelcookie/CLionProjects/Game/texture/CellStart.png"
#define ExitPNG "/home/cruelcookie/CLionProjects/Game/texture/CellEnd.png"
#define WallPNG "/home/cruelcookie/CLionProjects/Game/texture/CellWall.png"

class MapBuilderOne : public MapBuilder{
private:
    Field* field;
public:
    MapBuilderOne();
    ~MapBuilderOne();
    void Reset();
    void BuildEnter() override;
    void BuildExit() override;
    void BuildWalls() override;
    void BuildFloor() override;
    Field* ReturnField();
};

#endif //GAME_MAPBUILDERONE_H
