#ifndef SFMLPROJ_FIELDDIRECTOR_H
#define SFMLPROJ_FIELDDIRECTOR_H

#include "FieldBuilder.h"


class FieldDirector {
private:
    FieldBuilder *builder;
public:
    FieldDirector(FieldBuilder *b);

    void set_builder(FieldBuilder *b);

    void build_plain_field();
};


#endif
