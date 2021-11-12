#ifndef GAME_SPIDER_H
#define GAME_SPIDER_H

#include "Unit.h"

class Spider:public Unit{
private:
    int health;
    int force;
    bool is_alive;
    ObjectType type;
    int coord[2] = {-1, -1};
public:
    explicit Spider(int health = 2, int force = 1,bool is_alive = true, ObjectType type = spider);
    void SetHealth(int health) override;
    int GetHealth() override;
    void SetForce(int damage) override;
    void SetType(ObjectType value) override;
    ObjectType GetType() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    void Interaction(Object* units) override;
    bool IsAlive() override;
    void Move(Field *field, int x, int y) override;
    std::string GetLog() override;
};
#endif //GAME_SPIDER_H
