#include "Axe.h"

Axe::Axe(int damage, ObjectType type, bool is_available) {
    this->damage = damage;
    this->type = type;
    this->is_available = is_available;
}
void Axe::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
};
int* Axe::GetCoord() {
    return this->coord;
}
int Axe::GetData() {
    this->is_available = false;
    return this->damage;
}
ObjectType Axe::GetType() {
    return this->type;
}
bool Axe::IsAvailable() {
    return this->is_available;
}

std::string Axe::GetLog() {
    return "type: axe\nforce+:" + std::to_string(damage) + " \n" + "coord: ("   + std::to_string(coord[0]) + ", " + std::to_string(coord[1]) + ")" + " \n" +"available:" +
           std::to_string(is_available) + " \n" + "//-----------\n";
}
