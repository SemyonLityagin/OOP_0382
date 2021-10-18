#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "map/MapBuilder/Field/Cell/Cell.h"
#include "map/MapBuilder/Field/Field.h"
#include "map/MapBuilder/MapDirector.h"
#include "map/MapBuilder/FirstMapBuilder.h"
#include "map/MapBuilder/SecondMapBuilder.h"

class Game{
public:
    static void StartGame();
    static void DrawFieldOnWindow(Cell** cells, sf::RenderWindow *window);
};

#endif //GAME_GAME_H
