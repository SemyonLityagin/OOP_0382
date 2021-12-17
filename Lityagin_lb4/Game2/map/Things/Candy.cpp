#include "Candy.h"

Candy::Candy(int hp, ObjectType type, bool is_available) {
    this->hp = hp;
    this->type = type;
    this->is_available = is_available;
}

void Candy::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
};
int* Candy::GetCoord() {
    return this->coord;
}
int Candy::GetData() {
    this->is_available = false;
    return this->hp;
}
ObjectType Candy::GetType() {
    return this->type;
}
bool Candy::IsAvailable() {
    return this->is_available;
}

std::string Candy::GetLog() {
    return "type: candy\nhp+:" + std::to_string(hp) + " \n" + "coord: ("   + std::to_string(coord[0]) + ", " + std::to_string(coord[1]) + ")" + " \n" +"available:" +
           std::to_string(is_available) + " \n" + "//-----------\n";
}
