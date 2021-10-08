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
            field->cells[i][j] = new Cell(i, j, FloorPNG);
        }
    }
}

void MapBuilderOne::BuildWalls() {
    for(int i = 0; i < Size; i++) {
        field->cells[0][i] = new Cell(0, i, WallPNG);
        field->cells[Size - 1][i] = new Cell(Size - 1, i, WallPNG);
        field->cells[i][0] = new Cell(i, 0, WallPNG);
        field->cells[i][Size - 1] = new Cell(i, Size - 1, WallPNG);
    }
}

void MapBuilderOne::BuildExit() {
    field->cells[1][0] = new Cell(1, 0, ExitPNG);
}

void MapBuilderOne::BuildEnter() {
    field->cells[Size-1][Size-2] = new Cell(Size-1, Size-2, EnterPNG);
}

Field* MapBuilderOne::ReturnField() {
    Field* result = field;
    Reset();
    return result;
}