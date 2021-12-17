#ifndef GAME_OBJECTACTION_H
#define GAME_OBJECTACTION_H

#include "../map/Units/Unit.h"
#include "../map/Things/Thing.h"
#include "../log/Logger.h"
#include "../Drawing.h"

class ObjectAction{
private:
    Field* field;
    Unit** enemy;
    Thing** thing;
    int ENEMY;
    int THING;
    Logger* logger;
    Drawing* draw;
public:
    ObjectAction(Unit** enemy, Thing** thing, int ENEMY, int THING, Logger* logger, Field* field, Drawing* draw);
    void CheckObject();
    void MoveEnemy();
    std::string GetData();
    void GetStats(Unit** new_enemy, Thing** new_thing, int new_ENEMY, int new_THING, Field* new_field);
    ~ObjectAction();
};

#endif //GAME_OBJECTACTION_H
