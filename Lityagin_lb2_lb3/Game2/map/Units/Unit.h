#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#include "Object.h"
#include "../MapBuilder/Field/Field.h"

class Unit: public Object{
public:
    virtual ~Unit()=default;
    virtual void SetForce(int damage);
    virtual void SetMaxHealth(int maxHealth);
    virtual bool IsAlive();
    virtual void Move(Field* field, int x, int y);
};

#endif //GAME_UNIT_H
