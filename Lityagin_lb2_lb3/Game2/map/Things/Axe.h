#ifndef GAME_AXE_H
#define GAME_AXE_H

#include "Thing.h"

class Axe: public Thing{
private:
    int damage;
    ObjectType type;
    bool is_available;
    int coord[2] = {-1, -1};
public:
    Axe(int damage = 5, ObjectType type = axe, bool is_available = true);
    int GetData() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    ObjectType GetType() override;
    bool IsAvailable() override;
    std::string GetLog() override;
};

#endif //GAME_AXE_H
