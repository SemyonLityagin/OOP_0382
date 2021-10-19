#include "PlainFieldBuilder.h"

PlainFieldBuilder::PlainFieldBuilder() {
    this->Reset();
}

PlainFieldBuilder::~PlainFieldBuilder() {
    delete this->field;
}

void PlainFieldBuilder::Reset() {
    this->field = new Field();
}

void PlainFieldBuilder::BuildFoundation() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Cell cell(FOUNDATION);
            this->field->setCell(i, j, cell);
        }
    }
}

void PlainFieldBuilder::BuildEntry() {
    Cell cell(ENTRY);
    this->field->setCell(0, 0, cell);
}

void PlainFieldBuilder::BuildExit() {
    Cell cell(EXIT);
    this->field->setCell(SIZE - 1, SIZE - 1, cell);
}

void PlainFieldBuilder::BuildWalls() {
    for (int i = 0; i < SIZE; i += 4) {
        int j = i ? 0 : 4;
        int end = (i == SIZE - 4) ? SIZE - 4 : SIZE;
        for (; j < end; j += 4) {
            int i1 = rand() % 4;
            int j1 = rand() % 4;
            Cell cell(WALL);
            this->field->setCell(i + i1, j + j1, cell);
        }
    }
}

Field *PlainFieldBuilder::get_field() {
    Field* result = this->field;
    this->Reset();
    return result;
}