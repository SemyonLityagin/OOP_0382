#ifndef GAME_CANDY_H
#define GAME_CANDY_H

#include "Thing.h"

class Candy: public Thing{
private:
    int hp;
    int coord[2] = {-1, -1};
public:
    Candy(int hp = 5);
    void Interaction(Hero* obj) override;
};

#endif //GAME_CANDY_H
