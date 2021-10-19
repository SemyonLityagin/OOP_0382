//
// Created by Юрий on 19.10.2021.
//

#ifndef SFMLPROJ_MUDGOLEM_H
#define SFMLPROJ_MUDGOLEM_H

#include "Enemy.h"

class MudGolem: public Enemy {
private:
    int armor;
public:
    explicit MudGolem(int armor);
    void AttackPlayer() override;
};


#endif //SFMLPROJ_MUDGOLEM_H
