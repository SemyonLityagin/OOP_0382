#ifndef SFMLPROJ_GAME_H
#define SFMLPROJ_GAME_H

#include <SFML/Graphics.hpp>
#include "cell/Cell.h"
#include "field/Field.h"
#include "field/PlainFieldBuilder.h"
#include "field/FieldDirector.h"

#define RESULUTION_WIDTH 640
#define NAME "RPGLab"
#define FOUNDATION_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\foundation.png"
#define ENTRY_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\entry.png"
#define EXIT_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\exit.png"
#define WALL_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\wall.png"

class Game {
private:
    sf::Texture* field_textures[4];
    sf::Sprite* field_sprites[4];
    Field* field;
    sf::RenderWindow* window;
public:
    Game();
    void start_game();
    void loadTextures();
    void drawField();
};


#endif
