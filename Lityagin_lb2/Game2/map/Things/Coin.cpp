#include "Coin.h"

Coin::Coin(int value) {
    this->value = value;
}

void Coin::Interaction(Hero *obj) {
    obj->SetCoins(1);
}
