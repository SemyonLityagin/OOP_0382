#include "SpiderFactory.h"

Unit* SpiderFactory::CreateUnit() {
    return new Spider();
}
