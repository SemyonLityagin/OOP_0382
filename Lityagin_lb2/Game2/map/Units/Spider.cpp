#include "Spider.h"

Spider::Spider(int health, int force, int maxHealth, bool is_alive, ObjectType type) {
    this->health = health;
    this->force = force;
    this->is_alive = is_alive;
    this->maxHealth = maxHealth;
    this->type = type;
};
void Spider::SetHealth(int health) {
    this->health = health;
    if(health <= 0){
        this->is_alive = false;
    }
}
int Spider::GetHealth() {
    return this->health;
}
void Spider::SetForce(int damage) {
    this->force = damage;
};
void Spider::SetMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
};
void Spider::SetType(ObjectType value) {
    this->type = value;
};
ObjectType Spider::GetType() {
    return this->type;
};
void Spider::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
};
void Spider::Interaction(Object* units) {
    units->SetHealth(units->GetHealth() - this->force);
}
int* Spider::GetCoord() {
    return this->coord;
};
bool Spider::IsAlive() {
    return is_alive;
}
void Spider::Move(Field *field, int x, int y) {
    if((x > 0 && x < Size - 1 && y > 0 && y < Size -1)) {
        if(field->GetCells()[x][y].GetObjectType() == empty) {
            field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
            SetCoord(x, y);
            field->GetCells()[x][y].SetObject(this);
        }
    }
};
