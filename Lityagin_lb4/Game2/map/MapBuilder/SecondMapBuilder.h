#ifndef GAME_SECONDMAPBUILDER_H
#define GAME_SECONDMAPBUILDER_H

#include "MapBuilder.h"
#include "Field/Field.h"
#include "Field/Cell/Cell.h"

class SecondMapBuilder : public MapBuilder{
private:
    Field* field;
public:
    SecondMapBuilder();
    ~SecondMapBuilder();
    void Reset();
    void BuildEnter() override;
    void BuildExit() override;
    void BuildWalls() override;
    void BuildFloor() override;
    Field* ReturnField() override;
};

#endif //GAME_SECONDMAPBUILDER_H
