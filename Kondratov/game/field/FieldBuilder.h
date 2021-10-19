#ifndef SFMLPROJ_FIELDBUILDER_H
#define SFMLPROJ_FIELDBUILDER_H

#include <iostream>


class FieldBuilder {
public:
    virtual void BuildFoundation();
    virtual void BuildEntry();
    virtual void BuildExit();
    virtual void BuildWalls();
};


#endif
