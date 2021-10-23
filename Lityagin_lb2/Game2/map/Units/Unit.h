#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#include "../MapBuilder/Field/Cell/Object.h"
#include "../MapBuilder/Field/Field.h"

class Unit: public Object{
public:
    virtual void SetForce(int damage);
    virtual int GetForce();
    virtual void SetMaxHealth(int maxHealth);
    virtual bool IsAlive();
    virtual void Move(Field* field, int x, int y);
};

#endif //GAME_UNIT_H
