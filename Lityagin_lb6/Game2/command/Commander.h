#ifndef GAME_COMMANDER_H
#define GAME_COMMANDER_H

#include <SFML/Graphics.hpp>
#include "../map/MapBuilder/Field/Field.h"

enum Command {moveUp, moveDown, moveRight, moveLeft, close, objectAction, nothing, win, death, save1, load1, save, load};

class Commander{
private:
    sf::Keyboard::Key direction[4] = {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S};
    sf::Keyboard::Key SaveAndLoad[4] = {sf::Keyboard::F5, sf::Keyboard::F6, sf::Keyboard::F1, sf::Keyboard::F2};
    bool pressed;
public:
    Commander(){};
    Commander(sf::Keyboard::Key b1,sf::Keyboard::Key b2, sf::Keyboard::Key b3, sf::Keyboard::Key b4 );
    Command Moving(sf::Event event);

};

#endif //GAME_COMMANDER_H
