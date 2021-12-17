#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Commander.h"
#include "../save/SaveAndLoad.h"
#include <SFML/Graphics.hpp>
#include <fstream>


class Manager{
private:
    ObjectAction* objAct;
    HeroAction* heroAct;
    sf::RenderWindow* window = nullptr;
public:
    Manager(ObjectAction* objAct, HeroAction* heroAct);
    void DoIteration(Command command);
    void SetWindow(sf::RenderWindow* window);
    ~Manager();
};

#endif //GAME_MANAGER_H
