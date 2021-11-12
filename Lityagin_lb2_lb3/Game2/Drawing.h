#ifndef GAME_DRAWING_H
#define GAME_DRAWING_H

#define HeroPNG "../texture/Gamer.png"
#define EyePNG "../texture/Eye.png"
#define EntPNG "../texture/Ent.png"
#define SpiderPNG "../texture/Spider.png"
#define AxePNG "../texture/Axe.png"
#define CoinPNG "../texture/Coin.png"
#define CandyPNG "../texture/Candy.png"

#define FloorPNG "../texture/Cell.png"
#define EnterPNG "../texture/CellStart.png"
#define ExitPNG "../texture/CellEnd.png"
#define WallPNG "../texture/CellWall.png"

#include <SFML/Graphics.hpp>
#include "map/MapBuilder/Field/Cell/Cell.h"
#include "map/MapBuilder/Field/Field.h"

using namespace sf;

class Drawing{
private:
    Texture textureObject[7];
    Texture textureCell[4];
    Sprite sprite;
    CellTypes cellType;
    ObjectType objectType;
    Font font;
    Text text;
public:
    Drawing();
    void DrawFieldOnWindow(Cell** cells, RenderWindow *window);
};

#endif //GAME_DRAWING_H
