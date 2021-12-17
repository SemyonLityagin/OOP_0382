#ifndef GAME_HEROACTION_H
#define GAME_HEROACTION_H

#include "../map/Units/Hero.h"

class HeroAction{
private:
    Hero* gamer;
    int* coord;
    Field* field;
public:
    HeroAction(Hero* gamer, Field* field);
    void MoveHeroLeft();
    void MoveHeroUp();
    void MoveHeroRight();
    void MoveHeroDown();
    bool CheckDeath();
    bool CheckWin();
    ~HeroAction();
};
#endif //GAME_HEROACTION_H
