#ifndef GAME_FIRSTMAPBUILDER_H
#define GAME_FIRSTMAPBUILDER_H

#include "MapBuilder.h"
#include "Field/Field.h"
#include "Field/Cell/Cell.h"

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
    Field* ReturnField() override;
};

#endif //GAME_FIRSTMAPBUILDER_H
