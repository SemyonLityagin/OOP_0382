#include "MapDirector.h"

MapDirector::MapDirector(MapBuilder *build) {
    ChangeBuilder(build);
}

void MapDirector::ChangeBuilder(MapBuilder *build) {
    builder = build;
}

void MapDirector::ConstructMap() {
    builder->BuildFloor();
    builder->BuildWalls();
    builder->BuildExit();
    builder->BuildEnter();
}