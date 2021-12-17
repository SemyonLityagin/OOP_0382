#ifndef GAME_EYE_H
#define GAME_EYE_H

#include "Unit.h"

class Eye:public Unit{
private:
    int health;
    int force;
    bool is_alive;
    ObjectType type;
    int coord[2] = {-1,-1};
public:
    explicit Eye(int health = 8, int force = 4,bool is_alive = true, ObjectType type = eye);
    void SetHealth(int health) override;
    int GetHealth() override;
    void SetForce(int damage) override;
    void SetType(ObjectType value) override;
    ObjectType GetType() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    void Interaction(Object* object) override;
    bool IsAlive() override;
    void Move(Cell** cell, int x, int y) override;
    std::string GetLog() override;
};
#endif //GAME_EYE_H
