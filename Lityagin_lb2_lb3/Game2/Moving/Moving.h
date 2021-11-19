#ifndef GAME_MOVING_H
#define GAME_MOVING_H


#include "../map/MapBuilder/Field/Cell/Cell.h"
#include "../map/MapBuilder/Field/Field.h"
#include <SFML/Graphics.hpp>
#include "../Drawing.h"

#include "../map/Units/Hero.h"
#include "../map/Units/Unit.h"
#include "../map/Things/Thing.h"
#include "../log/Logger.h"

class Move{
public:
    static void Movement(sf::RenderWindow* window, Field* field, Hero* gamer, Unit** evil, Thing** thing, Drawing* draw, int EVIL, int THING, Logger* logger);
    static void MoveEvil(Field* field, Unit** evils, int EVIL);
    static void CheckObject(Unit** evil, Thing** thing, int EVIL, int THING, Field* field);
    static void MoveHero(Field* field, Unit* hero, int x, int y);
};


#endif //GAME_MOVING_H
