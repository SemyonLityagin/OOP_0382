#ifndef GAME_EYE_H
#define GAME_EYE_H

#include "Unit.h"

class Eye:public Unit{
private:
    int health;
    int force;
    bool is_alive;
    int maxHealth;
    ObjectType type;
    int coord[2] = {-1,-1};
public:
    Eye(int health = 6, int force = 2, int maxHealth = 6,bool is_alive = true, ObjectType type = eye);
    void SetHealth(int health) override;
    int GetHealth() override;
    void SetForce(int damage) override;
    void SetMaxHealth(int maxHealth) override;
    void SetType(ObjectType value) override;
    ObjectType GetType() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    void Interaction(Object* units) override;
    bool IsAlive() override;
    void Move(Field *field, int x, int y) override;
};
#endif //GAME_EYE_H
