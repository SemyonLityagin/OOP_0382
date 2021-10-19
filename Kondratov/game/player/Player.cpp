//
// Created by Юрий on 19.10.2021.
//

#include "Player.h"

Player::Player(int health, int attack, int armor): health(health), attack(attack), armor(armor) {}

int Player::get_attack() {
    return this->attack;
}

void Player::change_attack(int value) {
    this->attack += value;
}

int Player::get_health() {
    return this->health;
}

void Player::change_health(int value) {
    this->health += value;
}


void Player::interact_with_object() {
}

int Player::get_armor() {
    return this->armor;
}

void Player::change_armor(int value) {
    this->armor += value;
}


