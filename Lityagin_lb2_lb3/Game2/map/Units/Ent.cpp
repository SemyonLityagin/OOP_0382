#include "Ent.h"

Ent::Ent(int health, int force, bool is_alive, ObjectType type) {
    this->health = health;
    this->force = force;
    this->is_alive = is_alive;
    this->type = type;
}
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
}
void Ent::SetType(ObjectType value) {
    this->type = value;
}
ObjectType Ent::GetType() {
    return this->type;
}
void Ent::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
}
int* Ent::GetCoord() {
    return this->coord;
}
void Ent::Interaction(Object* object) {
    object->SetHealth(object->GetHealth() - this->force);
}
bool Ent::IsAlive() {
    return is_alive;
}
void Ent::Move(Cell** cells, int x, int y) {
    if((x > 0 && x < Size - 1 && y > 0 && y < Size -1)&&cells[x][y].IsMovable()) {
        if(cells[x][y].GetObjectType() == empty) {
            cells[coord[0]][coord[1]].SetObject(nullptr);
            SetCoord(x, y);
            cells[x][y].SetObject(this);
        }
        else{
            if (cells[x][y].GetObjectType() == hero) {
                Interaction(cells[x][y].GetObject());
            }
        }
    }
}

std::string Ent::GetLog() {
    return "type: ent\nhealth: " + std::to_string(health) + " \n" + "damage: " + std::to_string(force) + " \n" + "coord: ("   + std::to_string(coord[0]) + ", " +
           std::to_string(coord[1]) + ")" + " \n" +"alive: " + std::to_string(is_alive) + " \n" + "//-----------\n";
}
