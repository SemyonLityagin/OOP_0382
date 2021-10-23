#include "Ent.h"

Ent::Ent(int health, int force, int maxHealth, bool is_alive, ObjectType type) {
    this->health = health;
    this->force = force;
    this->is_alive = is_alive;
    this->maxHealth = maxHealth;
    this->type = type;
};

void Ent::SetHealth(int health) {
    this->health = health;
    if(health <= 0){
        this->is_alive = false;
    }
}
int Ent::GetHealth() {
    return this->health;
}
void Ent::SetForce(int damage) {
    this->force = damage;
};
void Ent::SetMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
};
void Ent::SetType(ObjectType value) {
    this->type = value;
};
ObjectType Ent::GetType() {
    return this->type;
};
void Ent::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
};
int* Ent::GetCoord() {
    return this->coord;
}
void Ent::Interaction(Object* units) {
    units->SetHealth(units->GetHealth() - this->force);
}
bool Ent::IsAlive() {
    return is_alive;
}
void Ent::Move(Field *field, int x, int y) {
    if((x > 0 && x < Size - 1 && y > 0 && y < Size -1)&&field->GetCells()[x][y].IsMovable()) {
        if(field->GetCells()[x][y].GetObjectType() == empty) {
            field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
            SetCoord(x, y);
            field->GetCells()[x][y].SetObject(this);
        }
    }
};