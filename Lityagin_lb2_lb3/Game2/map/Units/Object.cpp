#include "Object.h"

void Object::SetCoord(int x, int y) {};
void Object::SetType(ObjectType value){};
ObjectType Object::GetType(){ return empty; };
int* Object::GetCoord() { return nullptr; };
void Object::SetHealth(int health) {}
int Object::GetHealth(){ return 0; }
void Object::Interaction(Object *unit) {}
int Object::GetData() { return 0; }
int Object::GetForce() { return 0; }


