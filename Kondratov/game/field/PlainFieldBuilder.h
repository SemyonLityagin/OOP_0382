#ifndef SFMLPROJ_PLAINFIELDBUILDER_H
#define SFMLPROJ_PLAINFIELDBUILDER_H

#include "FieldBuilder.h"
#include "Field.h"
#include <cstdlib>

#define FOUNDATION_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\foundation.png"
#define ENTRY_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\entry.png"
#define EXIT_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\exit.png"
#define WALL_TEXTURE_PATH "C:\\Coding\\SFMLProj\\resources\\field_textures\\wall.png"

class PlainFieldBuilder : public FieldBuilder {
private:
    Field *field;
public:
    PlainFieldBuilder();

    ~PlainFieldBuilder();

    void Reset();

    void BuildFoundation() override;

    void BuildEntry() override;

    void BuildExit() override;

    void BuildWalls() override;

    Field *get_field();
};

#endif
