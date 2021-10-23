#include "Hero.h"

Hero::Hero(int health, int force, int maxHealth, int coins, bool is_alive, ObjectType type) {
    this->health = health;
    this->force = force;
    this->is_alive = is_alive;
    this->coins = coins;
    this->maxHealth = maxHealth;
    this->type = type;
};
void Hero::SetHealth(int health) {
    this->health = health;
    if(health <= 0){
        this->is_alive = false;
    }
}
int Hero::GetHealth() {
    return this->health;
}
int Hero::GetForce(){
    return this->force;
}
void Hero::SetForce(int damage) {
    this->force = damage;
};
void Hero::SetMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
};
void Hero::SetType(ObjectType value) {
    this->type = value;
};
ObjectType Hero::GetType() {
    return this->type;
};
void Hero::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
};
int* Hero::GetCoord() {
    return this->coord;
};
void Hero::Interaction(Object* units) {
    if(units->GetType() == eye ||units->GetType() == ent || units->GetType() == spider) {
        units->SetHealth(units->GetHealth() - this->force);
    }
    else{
        units->Interaction(this);
    }
}
bool Hero::IsAlive() {
    return is_alive;
}
void Hero::Move(Field *field, int x, int y) {
    if((x > 0 && x < Size - 1 && y > 0 && y < Size -1)&&field->GetCells()[x][y].IsMovable() || field->GetCells()[x][y].GetType() == Exit){
        if(field->GetCells()[x][y].GetObjectType() == empty) {
            field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
            SetCoord(x, y);
            field->GetCells()[x][y].SetObject(this);
        }
        else{
            if(x > 0 && x < Size-1 && y > 0 && Size-1 > y) {
                if (field->GetCells()[x][y].GetObjectType() != empty) {
                    Interaction(field->GetCells()[x][y].GetObject());
                }
            }
        }
    }
}

void Hero::SetCoins(int value) {
    this->coins = this->coins + value;
    if(coins == 10){
        SetMaxHealth(maxHealth + 5);
    }
};