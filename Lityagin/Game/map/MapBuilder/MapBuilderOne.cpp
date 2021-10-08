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
        }
    }
}

void MapBuilderOne::BuildWalls() {
    for(int i = 0; i < Size; i++) {
        field->cells[0][i].SetTexture(WallPNG);
        field->cells[0][i].SetPosition(0, i);

        field->cells[Size - 1][i].SetTexture(WallPNG);
        field->cells[Size - 1][i].SetPosition(Size-1, i);

        field->cells[i][0].SetTexture(WallPNG);
        field->cells[i][0].SetPosition(i, 0);

        field->cells[i][Size - 1].SetTexture(WallPNG);
        field->cells[i][Size - 1].SetPosition(i, Size-1);
    }
}

void MapBuilderOne::BuildExit() {
    field->cells[1][0].SetTexture(ExitPNG);
    field->cells[1][0].SetPosition(1, 0);
}

void MapBuilderOne::BuildEnter() {
    field->cells[Size-1][Size-2].SetTexture(EnterPNG);
    field->cells[Size-1][Size-2].SetPosition(Size-1, Size-2);
}

Field* MapBuilderOne::ReturnField() {
    Field* result = field;
    Reset();
    return result;
}