#include "Axe.h"

Axe::Axe(int damage) {
    this->damage = damage;
}
void Axe::Interaction(Hero *obj) {
    obj->SetForce(obj->GetForce() + damage);
}
