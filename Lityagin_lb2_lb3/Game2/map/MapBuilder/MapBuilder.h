#ifndef GAME_MAPBUILDER_H
#define GAME_MAPBUILDER_H

class MapBuilder{
public:
    virtual void BuildEnter();
    virtual void BuildExit();
    virtual void BuildWalls();
    virtual void BuildFloor();
};

#endif //GAME_MAPBUILDER_H
