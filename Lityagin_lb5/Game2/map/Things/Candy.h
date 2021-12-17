#ifndef GAME_CANDY_H
#define GAME_CANDY_H

#include "Thing.h"

class Candy: public Thing{
private:
    int hp;
    ObjectType type;
    bool is_available;
    int coord[2] = {-1, -1};
public:
    Candy(int hp = 5, ObjectType type = candy, bool is_available = true);
    int GetData() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    ObjectType GetType() override;
    bool IsAvailable() override;
    std::string GetLog() override;
};

#endif //GAME_CANDY_H
