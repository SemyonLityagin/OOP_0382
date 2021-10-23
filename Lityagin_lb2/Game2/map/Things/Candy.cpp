#include "Candy.h"

Candy::Candy(int hp) {
    this->hp = hp;
}
void Candy::Interaction(Hero *obj) {
    obj->SetHealth(obj->GetHealth() + hp);
}