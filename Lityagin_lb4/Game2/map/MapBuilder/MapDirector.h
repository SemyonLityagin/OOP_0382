#ifndef GAME_MAPDIRECTOR_H
#define GAME_MAPDIRECTOR_H

#include "MapBuilder.h"

class MapDirector{
private:
    MapBuilder* builder;
public:
    MapDirector(MapBuilder* build);
    void ChangeBuilder(MapBuilder* build);
    void ConstructMap();
};

#endif //GAME_MAPDIRECTOR_H
