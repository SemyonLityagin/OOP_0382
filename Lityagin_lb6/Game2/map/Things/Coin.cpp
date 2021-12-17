#include "Coin.h"

Coin::Coin(int value, ObjectType type, bool is_available) {
    this->value = value;
    this->type = type;
    this->is_available = is_available;
}
void Coin::SetCoord(int x, int y) {
    this->coord[0] = x;
    this->coord[1] = y;
};
int* Coin::GetCoord() {
    return this->coord;
}
int Coin::GetData() {
    this->is_available = false;
    return this->value;
}
bool Coin::IsAvailable() {
    return this->is_available;
}
ObjectType Coin::GetType() {
    return this->type;
}

std::string Coin::GetLog() {
    return "type: coin\nvalue:" + std::to_string(value) + " \n" + "coord: ("   + std::to_string(coord[0]) + ", " + std::to_string(coord[1]) + ")" + " \n" +"available:" +
            std::to_string(is_available) + " \n" + "//-----------\n";
}

