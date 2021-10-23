#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

enum ObjectType {hero, eye, spider, ent, axe, candy, coin, empty};

class Object{
public:
    virtual void SetCoord(int x, int y);
    virtual int* GetCoord();
    virtual void SetType(ObjectType value);
    virtual void SetHealth(int health);
    virtual int GetHealth();
    virtual void Interaction(Object* unit);
    virtual ObjectType GetType();
};
#endif //GAME_OBJECT_H
