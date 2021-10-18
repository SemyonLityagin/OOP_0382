#include "SecondMapBuilder.h"

SecondMapBuilder::SecondMapBuilder() {
    Reset();
}
SecondMapBuilder::~SecondMapBuilder(){
    delete field;
}
void SecondMapBuilder::Reset(){
    field = new Field();
}

void SecondMapBuilder::BuildFloor() {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            field->GetCells()[i][j].SetType(Floor);
        }
    }
}

void SecondMapBuilder::BuildWalls() {
    for (int i = 0; i < Size; i++) {
        field->GetCells()[0][i].SetType(Wall);

        field->GetCells()[Size - 1][i].SetType(Wall);

        field->GetCells()[i][0].SetType(Wall);

        field->GetCells()[i][Size - 1].SetType(Wall);
    }

    for (int i = 2; i <= Size - 1; i++) {
        for (int j = 1; j <= Size - 1; j++) {
            field->GetCells()[i][j].SetType(Wall);
        }
    }
}

void SecondMapBuilder::BuildExit() {
    field->GetCells()[0][1].SetType(Exit);
}

void SecondMapBuilder::BuildEnter() {
    field->GetCells()[Size-1][Size-2].SetType(Enter);
}

Field* SecondMapBuilder::ReturnField() {
    Field* result = field;
    Reset();
    return result;
}