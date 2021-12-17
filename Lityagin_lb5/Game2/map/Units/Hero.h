#ifndef GAME_HERO_H
#define GAME_HERO_H

#include "Unit.h"
#include "../Things/Thing.h"

class Hero:public Unit{
private:
    int health;
    int coins;
    int force;
    bool is_alive;
    int maxHealth;
    ObjectType type;
    int coord[2] = {Size-1 , Size-2};
public:
    Hero(int health = 20, int force = 2, int maxHealth = 20, int coins = 0,bool is_alive = true, ObjectType type = hero);
    void SetHealth(int health) override;
    int GetHealth() override;
    int GetForce() override;
    void SetForce(int damage) override;
    void SetCoins(int value);
    int GetCoins();
    void SetMaxHealth(int maxHealth) override;
    void SetType(ObjectType value) override;
    ObjectType GetType() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    void Interaction(Object* object) override;
    bool IsAlive() override;
    void Move(Cell** cells, int x, int y) override;
    std::string GetLog() override;
};

#endif //GAME_HERO_H