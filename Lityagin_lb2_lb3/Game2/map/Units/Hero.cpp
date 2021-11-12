#include "Hero.h"

Hero::Hero(int health, int force, int maxHealth, int coins, bool is_alive, ObjectType type) {
    this->health = health;
    this->force = force;
    this->is_alive = is_alive;
    this->coins = coins;
    this->maxHealth = maxHealth;
    this->type = type;
}
void Hero::SetHealth(int health) {
    if(health >= this->maxHealth){
        this->health = maxHealth;
    }
    else{
        this->health = health;
    }
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
}
void Hero::SetMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}
void Hero::SetType(ObjectType value) {
    this->type = value;
}
ObjectType Hero::GetType() {
    return this->type;
}
void Hero::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
}
int* Hero::GetCoord() {
    return this->coord;
}
void Hero::Interaction(Object* units) {
    if(units->GetType() == eye || units->GetType() == ent || units->GetType() == spider) {
        units->SetHealth(units->GetHealth() - this->force);
    }
    else if(units->GetType() == axe){
        this->SetForce(force + units->GetData());
    }
    else if(units->GetType() == candy){
        this->SetHealth(health + units->GetData());
    }
    else if(units->GetType() == coin){
        this->SetCoins(coins + units->GetData());
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
            if (field->GetCells()[x][y].GetObjectType() != empty) {
                Interaction(field->GetCells()[x][y].GetObject());
            }
        }
    }
}

void Hero::SetCoins(int value) {
    this->coins = this->coins + value;
    if(this->coins >= 10){
        SetMaxHealth(maxHealth + 5);
        this->coins = this->coins - 10;
    }
}

int Hero::GetCoins() {
    return this->coins;
}

std::string Hero::GetLog() {
    return "type: hero\nhealth: " + std::to_string(health) + " \ndamage: " + std::to_string(force) + " \ncoord: ("   + std::to_string(coord[0]) + ", " +
           std::to_string(coord[1]) + ")" + " \ncoins: " + std::to_string(coins) +"\nalive: " + std::to_string(is_alive) + " \n//-----------\n";
}

