#ifndef GAME_GAME_H
#define GAME_GAME_H

#define HeroPNG "../texture/Gamer.png"
#define EyePNG "../texture/Eye.png"
#define EntPNG "../texture/Ent.png"
#define SpiderPNG "../texture/Spider.png"
#define AxePNG "../texture/Axe.png"
#define CoinPNG "../texture/Coin.png"
#define CandyPNG "../texture/Candy.png"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "map/MapBuilder/Field/Cell/Cell.h"
#include "map/MapBuilder/Field/Field.h"
#include "map/MapBuilder/MapDirector.h"
#include "map/MapBuilder/FirstMapBuilder.h"

#include "./map/Units/Hero.h"
#include "./map/Units/Unit.h"
#include "./map/Units/Ent.h"
#include "./map/Units/Eye.h"
#include "./map/Units/Spider.h"
#include "./map/Factory/HeroFactory.h"
#include "./map/Factory/EntFactory.h"
#include "./map/Factory/EyeFactory.h"
#include "./map/Factory/SpiderFactory.h"
#include "./map/Factory/ObjectFactory.h"


class Game{
public:
    static void StartGame();
    static void DrawFieldOnWindow(Cell** cells, sf::RenderWindow *window);
    static void MoveEvil(Field* field, Unit** evils);
    static void MoveHero(Field* field, Unit* hero, int x, int y);
};

#endif //GAME_GAME_H
