#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "../../log/Subject.h"

enum ObjectType {hero, eye, spider, ent, axe, candy, coin, empty};

class Object:public Subject{
public:
    virtual void SetCoord(int x, int y);
    virtual int* GetCoord();
    virtual void SetType(ObjectType value);
    virtual void SetHealth(int health);
    virtual int GetHealth();
    virtual int GetForce();
    virtual void Interaction(Object* object);
    virtual int GetData();
    virtual ObjectType GetType();
};
#endif //GAME_OBJECT_H
