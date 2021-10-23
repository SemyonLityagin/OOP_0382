#include "HeroFactory.h"

Unit* HeroFactory::CreateUnit() {
    return new Hero();
}