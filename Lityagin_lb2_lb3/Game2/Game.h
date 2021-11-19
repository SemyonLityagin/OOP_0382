#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "map/MapBuilder/Field/Cell/Cell.h"
#include "map/MapBuilder/Field/Field.h"
#include "map/MapBuilder/MapDirector.h"
#include "map/MapBuilder/FirstMapBuilder.h"
#include "Drawing.h"

#include "./map/Units/Hero.h"
#include "./map/Units/Unit.h"
#include "./map/Units/Ent.h"
#include "./map/Units/Eye.h"
#include "./map/Units/Spider.h"
#include "./map/Things/Axe.h"
#include "./map/Things/Coin.h"
#include "./map/Things/Candy.h"
#include "./map/Things/Thing.h"
#include "./map/Units/Spider.h"
#include "./map/Factory/EntFactory.h"
#include "./map/Factory/EyeFactory.h"
#include "./map/Factory/SpiderFactory.h"
#include "./map/Factory/ObjectFactory.h"
#include "./Moving/Moving.h"
#include "./log/Observer.h"
#include "./log/Subject.h"
#include "./log/ConsoleLogger.h"
#include "./log/FileLogger.h"
#include "./log/Logger.h"
#include "./log/LoggerImplication.h"
#include "./log/Decorator.h"

class Game{
public:
    void StartGame(int EVIL, int THING);
    Unit** CreateEvil(Cell** cell, int EVIL);
    Thing** CreateThing(Cell** cell, int THING);
};

#endif //GAME_GAME_H
