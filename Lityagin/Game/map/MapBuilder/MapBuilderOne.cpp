#include "MapBuilderOne.h"

MapBuilderOne::MapBuilderOne() {
    Reset();
}
MapBuilderOne::~MapBuilderOne(){
    delete field;
}
void MapBuilderOne::Reset(){
    field = new Field();
}

void MapBuilderOne::BuildFloor() {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            field->cells[i][j].SetTexture(FloorPNG);
            field->cells[i][j].SetPosition(i, j);
            field->cells[i][j].SetType(1);
        }
    }
}

void MapBuilderOne::BuildWalls() {
    for (int i = 0; i < Size; i++) {
        field->cells[0][i].SetTexture(WallPNG);
        field->cells[0][i].SetPosition(0, i);
        field->cells[0][i].SetType(2);

        field->cells[Size - 1][i].SetTexture(WallPNG);
        field->cells[Size - 1][i].SetPosition(Size - 1, i);
        field->cells[Size - 1][i].SetType(2);

        field->cells[i][0].SetTexture(WallPNG);
        field->cells[i][0].SetPosition(i, 0);
        field->cells[i][0].SetType(2);

        field->cells[i][Size - 1].SetTexture(WallPNG);
        field->cells[i][Size - 1].SetPosition(i, Size - 1);
        field->cells[i][Size - 1].SetType(2);
    }

    for (int i = 2; i <= Size - 1 - 2; i = i + 2) {
        for (int j = 1; j <= Size - 1 - 1; j = j + 2) {
            field->cells[i][j].SetTexture(WallPNG);
            field->cells[i][j].SetPosition(i, j);
            field->cells[i][j].SetType(2);
        }
    }
}

void MapBuilderOne::BuildExit() {
    field->cells[1][0].SetTexture(ExitPNG);
    field->cells[1][0].SetPosition(1, 0);
    field->cells[1][0].SetType(3);
}

void MapBuilderOne::BuildEnter() {
    field->cells[Size-1][Size-2].SetTexture(EnterPNG);
    field->cells[Size-1][Size-2].SetPosition(Size-1, Size-2);
    field->cells[Size-1][Size-2].SetType(0);
}

Field* MapBuilderOne::ReturnField() {
    Field* result = field;
    Reset();
    return result;
}