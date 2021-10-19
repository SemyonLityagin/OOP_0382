#include "Field.h"

Field::Field() {
    grid = new Cell *[SIZE];
    for (int i = 0; i < SIZE; i++) grid[i] = new Cell[SIZE];
}

Field::Field(const Field &source) : Field() {
    for (int i = 0; i < SIZE; i++) {
        std::copy(source.grid[i], source.grid[i] + SIZE, this->grid[i]);
    }
}

Field::Field(Field&& other) {
    std::swap(this->grid, other.grid);
    other.grid = nullptr;
}

Field& Field::operator= (Field&& other) {
    if (this != &other) {
        delete this;
        this->grid = other.grid;
        other.grid = nullptr;
    }
    return *this;
}

Field& Field::operator= (const Field &other) {
    if (this != &other){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
                grid[i][j] = other.grid[i][j];
        }
    }
    return *this;
}

Field::~Field() {
    for (int i = 0; i < SIZE; i++)
        delete[] grid[i];
    delete[] grid;
}

void Field::setCell(int i, int j, Cell &cell) {
    this->grid[i][j] = cell;
}

Cell &Field::getCell(int i, int j) {
    return this->grid[i][j];
}

