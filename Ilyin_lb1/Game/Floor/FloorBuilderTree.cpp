#include "FloorBuilderTree.h"

FloorBuilderTree::FloorBuilderTree(){
    this->floor = new Floor(HEIGTH_OF_FLOOR, WIDTH_OF_FLOOR);
    // TODO: сделать считывание ширины поля
};

FloorBuilderTree::~FloorBuilderTree(){
    delete this->floor;
};

void FloorBuilderTree::GeneratNormalCells(){
    for (int i = 0; i < this->floor->height; ++i) {
        for (int j = 0; j < this->floor->width; ++j) {
            this->floor->cells[i][j] = new Cell(NORMAL_TEXTURE_PATH, sf::Vector2i(i, j), nullptr, Type::NORMAL);
        // TODO: nullptr в поле elem заменить на нормальное(пустое проходимое)
        }
    }
};

void FloorBuilderTree::GeneratWallCells(){
    for (int i = 0; i < this->floor->height; ++i) {
        for (int j = 0; j < this->floor->width; ++j) {
            if (i == 0 || i == this->floor->height - 1 || j == 0 || j == this->floor->width - 1){
                this->floor->cells[i][j]->setElem(nullptr);
                // TODO: nullptr в поле elem заменить на не проходимое
                this->floor->cells[i][j]->setType(Type::WALL);
                this->floor->cells[i][j]->setTexture(WALL_TEXTURE_PATH);
            }
        }
    }
    int** mass = new int*[this->floor->height];
    for (int i = 0; i < this->floor->height; ++i) mass[i] = new int[this->floor->width];
    for (int i = 0; i < this->floor->height; ++i) {
        for (int j = 0; j < this->floor->width; ++j) {
            mass[i][j] = 0;
        }
    }
    this->GeneratWallDungeonCells(0, 0, this->floor->width - 1, this->floor->height - 1, mass);
};

void FloorBuilderTree::GeneratWallDungeonCells(int x1, int y1, int x2, int y2, int** mass){
    int small_side, big_side = 3;
    int wall_index = -1;
    int len_xside = x2 - x1 - 1;
    int len_yside = y2 - y1 - 1;
    if ((len_xside * len_yside >= MIN_SIZE_OF_FLOOR*3) && (len_xside >= 3) && (len_yside >= 3)){
        if (len_xside >= len_yside) {
            small_side = len_yside;
            while (small_side * big_side < MIN_SIZE_OF_FLOOR) {
                big_side++;
            }
            if ((x2 - big_side) - (x1 + big_side) + 1 > 2 ) {
                while (wall_index == -1) {
                    wall_index = x1 + big_side + rand() % ((x2 - big_side) - (x1 + big_side) + 1);
                    if(mass[y1][wall_index] == 1 || mass[y2][wall_index] == 1){
                        wall_index = -1;
                    }
                    else{
                        mass[(int)(y1+y2)/2][wall_index] = 1;
                    }
                }
                for (int i = y1 + 1; i < y2 ; ++i) {
                    if (i != (int) ((y1 + y2) / 2)) {
                        this->floor->cells[i][wall_index]->setElem(nullptr);
                        // TODO: nullptr в поле elem заменить на не проходимое
                        this->floor->cells[i][wall_index]->setType(Type::WALL);
                        this->floor->cells[i][wall_index]->setTexture(WALL_TEXTURE_PATH);
                    }
                }
                this->GeneratWallDungeonCells(wall_index, y1, x2, y2, mass);
                this->GeneratWallDungeonCells(x1, y1, wall_index, y2, mass);
            }
        }else{
            small_side = len_xside;
            while (small_side * big_side < MIN_SIZE_OF_FLOOR){
                big_side++;
            }
            if ((y2 - big_side) - (y1 + big_side) + 1 > 2) {
                while (wall_index == -1) {
                    wall_index = y1 + big_side + rand() % ((y2 - big_side) - (y1 + big_side) + 1);
                    if(mass[wall_index][x1] == 1 || mass[wall_index][x2] == 1){
                        wall_index = -1;
                    }
                    else{
                        mass[wall_index][(int)(x1+x2)/2] = 1;
                    }
                }
                for (int i = x1 + 1; i < x2 ; ++i) {
                    if (i != (int) ((x1 + x2) / 2)) {
                        this->floor->cells[wall_index][i]->setElem(nullptr);
                        // TODO: nullptr в поле elem заменить на не проходимое
                        this->floor->cells[wall_index][i]->setType(Type::WALL);
                        this->floor->cells[wall_index][i]->setTexture(WALL_TEXTURE_PATH);
                    }
                }
                this->GeneratWallDungeonCells(x1, wall_index, x2, y2, mass);
                this->GeneratWallDungeonCells(x1, y1, x2, wall_index, mass);
            }
        }
    }
};

void FloorBuilderTree::GeneratEntryCell(){
    this->floor->cells[1][1]->setType(Type::ENTRY);
    this->floor->cells[1][1]->setTexture(ENTRY_TEXTURE_PATH);
};

void FloorBuilderTree::GeneratExitCell(){
    this->floor->cells[this->floor->height - 2][this->floor->width - 2]->setType(Type::EXIT);
    this->floor->cells[this->floor->height - 2][this->floor->width - 2]->setTexture(EXIT_TEXTURE_PATH);
};

void FloorBuilderTree::Reset(){
    this->floor = new Floor(this->floor->height, this->floor->width);
};

Floor* FloorBuilderTree::getFloor(){
    Floor* result = this->floor;
    this->Reset();
    return result;
};