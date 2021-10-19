#ifndef SFMLPROJ_PLAYER_H
#define SFMLPROJ_PLAYER_H

#include "../objects/CellObject.h"

class Player {
private:
    int health;
    int attack;
    int armor;
public:
    Player(int health = 12, int attack = 3, int armor = 3);
    int get_attack();
    void change_attack(int value);
    int get_health();
    void change_health(int value);
    void interact_with_object();
    int get_armor();
    void change_armor(int value);
};


#endif
