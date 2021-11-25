#include "EntFactory.h"

Unit* EntFactory::CreateUnit() {
    return new Ent();
}

