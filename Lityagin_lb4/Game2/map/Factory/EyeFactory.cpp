#include "EyeFactory.h"

Unit* EyeFactory::CreateUnit() {
    return new Eye();
}
