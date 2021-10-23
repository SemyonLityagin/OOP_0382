#ifndef GAME_AXE_H
#define GAME_AXE_H

#include "Thing.h"

class Axe: public Thing{
private:
    int damage;
    int coord[2] = {-1, -1};
public:
    Axe(int damage = 5);
    void Interaction(Hero* obj) override;
};

#endif //GAME_AXE_H
