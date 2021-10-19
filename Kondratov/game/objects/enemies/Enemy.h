//
// Created by Юрий on 19.10.2021.
//

#ifndef SFMLPROJ_ENEMY_H
#define SFMLPROJ_ENEMY_H

#include "../CellObject.h"

class Enemy: public CellObject {
public:
    void interact_with_player() override;
    virtual void AttackPlayer();
};


#endif //SFMLPROJ_ENEMY_H
