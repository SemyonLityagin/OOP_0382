#ifndef GAME_HEROACTION_H
#define GAME_HEROACTION_H

#include "../map/Units/Hero.h"
#include "../log/Logger.h"

class HeroAction{
private:
    Hero* gamer;
    int* coord;
    Field* field;
    Logger* logger;
    LoggerImplication* base;
public:
    HeroAction(Hero* gamer, Field* field, Logger* logger, LoggerImplication* base);
    void MoveHeroLeft();
    void MoveHeroUp();
    void MoveHeroRight();
    void MoveHeroDown();
    bool CheckDeath();
    bool CheckWin();
    std::string GetData();
    void GetStats(Hero* new_gamer, Field* new_field);
    ~HeroAction();
};
#endif //GAME_HEROACTION_H
