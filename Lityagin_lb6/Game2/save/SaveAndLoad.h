#ifndef GAME_SAVEANDLOAD_H
#define GAME_SAVEANDLOAD_H

#include <fstream>
#include <string>
#include "../command/HeroAction.h"
#include "../command/ObjectAction.h"
#include "../map/Things/Axe.h"
#include "../map/Things/Coin.h"
#include "../map/Things/Candy.h"
#include "../map/Units/Spider.h"
#include "../map/Units/Ent.h"
#include "../map/Units/Eye.h"
#include "../command/Commander.h"
#include "./LoadError.h"

class SaveAndLoad{
public:
    static void Save(HeroAction *heroAct, ObjectAction *objAct, Command command);
    static void Load(HeroAction* heroAct, ObjectAction* objAct, Command command);
};

#endif //GAME_SAVEANDLOAD_H
