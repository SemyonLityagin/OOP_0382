#include "FirstMapBuilder.h"

FirstMapBuilder::FirstMapBuilder() {
    Reset();
}
FirstMapBuilder::~FirstMapBuilder(){
    delete field;
}
void FirstMapBuilder::Reset(){
    field = new Field();
}

void FirstMapBuilder::BuildFloor() {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            field->GetCells()[i][j].SetType(Floor);
        }
    }
}

void FirstMapBuilder::BuildWalls() {
    for (int i = 0; i < Size; i++) {
        field->GetCells()[0][i].SetType(Wall);

        field->GetCells()[Size - 1][i].SetType(Wall);

        field->GetCells()[i][0].SetType(Wall);

        field->GetCells()[i][Size - 1].SetType(Wall);
    }

    for (int i = 2; i <= Size - 1 - 2; i = i + 2) {
        for (int j = 1; j <= Size - 1 - 1; j = j + 2) {
            field->GetCells()[i][j].SetType(Wall);
        }
    }
}

void FirstMapBuilder::BuildExit() {
    field->GetCells()[1][0].SetType(Exit);
}

void FirstMapBuilder::BuildEnter() {
    field->GetCells()[Size-1][Size-2].SetType(Enter);
}

Field* FirstMapBuilder::ReturnField() {
    Field* result = field;
    Reset();
    return result;
}