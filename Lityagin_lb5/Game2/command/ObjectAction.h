#ifndef GAME_OBJECTACTION_H
#define GAME_OBJECTACTION_H

#include "../map/Units/Unit.h"
#include "../map/Things/Thing.h"
#include "../log/Logger.h"

class ObjectAction{
private:
    Field* field;
    Unit** enemy;
    Thing** thing;
    int ENEMY;
    int THING;
    Logger* logger;
public:
    ObjectAction(Unit** enemy, Thing** thing, int ENEMY, int THING, Logger* logger, Field* field);
    void CheckObject();
    void MoveEnemy();
    ~ObjectAction();
};

#endif //GAME_OBJECTACTION_H
