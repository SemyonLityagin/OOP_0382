#include "FieldDirector.h"

void FieldDirector::set_builder(FieldBuilder *b) {
    this->builder = b;
}

void FieldDirector::build_plain_field() {
    this->builder->BuildFoundation();
    this->builder->BuildEntry();
    this->builder->BuildExit();
    this->builder->BuildWalls();
}

FieldDirector::FieldDirector(FieldBuilder *b) {
    this->set_builder(b);
}
