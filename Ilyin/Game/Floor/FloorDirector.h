#ifndef GAME_FLOORDIRECTOR_H
#define GAME_FLOORDIRECTOR_H

#include "FloorBuilder.h"

class FloorDirector {
private:
    FloorBuilder* builder;

public:
    FloorDirector(FloorBuilder* b);

    void setBuilder(FloorBuilder* b);

    void Builder_FloorBuilderTree();

};


#endif //GAME_FLOORDIRECTOR_H
