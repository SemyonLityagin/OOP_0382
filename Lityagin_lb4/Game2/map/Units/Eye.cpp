#include "Eye.h"

Eye::Eye(int health, int force, bool is_alive, ObjectType type) {
    this->health = health;
    this->force = force;
    this->is_alive = is_alive;
    this->type = type;
}
void Eye::SetHealth(int health) {
    this->health = health;
    if(health <= 0){
        this->is_alive = false;
    }
}
int Eye::GetHealth() {
    return this->health;
}
void Eye::SetForce(int damage) {
    this->force = damage;
}
void Eye::SetType(ObjectType value) {
    this->type = value;
}
ObjectType Eye::GetType() {
    return this->type;
}
void Eye::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
}
int* Eye::GetCoord() {
    return this->coord;
}
void Eye::Interaction(Object* object) {
    object->SetHealth(object->GetHealth() - this->force);
}
bool Eye::IsAlive() {
    return is_alive;
}
void Eye::Move(Cell** cells, int x, int y) {
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

std::string Eye::GetLog() {
    return "type: eye\nhealth: " + std::to_string(health) + " \n" + "damage: " + std::to_string(force) + " \n" + "coord: ("   + std::to_string(coord[0]) + ", " +
           std::to_string(coord[1]) + ")" + " \n" +"alive: " + std::to_string(is_alive) + " \n" + "//-----------\n";
}

