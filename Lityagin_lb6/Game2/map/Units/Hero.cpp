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
void Hero::Interaction(Object* object) {
    if(object->GetType() == eye || object->GetType() == ent || object->GetType() == spider) {
        object->SetHealth(object->GetHealth() - this->force);
    }
    else if(object->GetType() == axe){
        this->SetForce(force + object->GetData());
    }
    else if(object->GetType() == candy){
        this->SetHealth(health + object->GetData());
    }
    else if(object->GetType() == coin){
        this->SetCoins(coins + object->GetData());
    }
}
bool Hero::IsAlive() {
    return is_alive;
}

void Hero::Move(Cell** cells, int x, int y) {
    if((x > 0 && x < Size - 1 && y > 0 && y < Size -1)&&cells[x][y].IsMovable() || cells[x][y].GetType() == Exit){
        if(cells[x][y].GetObjectType() == empty) {
            cells[coord[0]][coord[1]].SetObject(nullptr);
            SetCoord(x, y);
            cells[x][y].SetObject(this);
        }
        else{
            if (cells[x][y].GetObjectType() != empty) {
                Interaction(cells[x][y].GetObject());
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

int Hero::GetMaxHealth() {
    return this->maxHealth;
}


