#include "Field.h"

Field::Field(){
    cells = new Cell*[Size];
    for(int i = 0; i < Size; i++){
        cells[i] = new Cell[Size];
    }
}

Field::Field(const Field& other){
    this->cells = new Cell*[Size];
    for(int i = 0; i < Size; i++){
        this->cells[i] = new Cell[Size];
    }
    for(int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
}

Field& Field::operator=(const Field& other) {
    if(this != &other){
        for(int i = 0; i < Size; i++){
            delete[] this->cells[i];
        }
        delete[] this->cells;

        this->cells = new Cell*[Size];
        for(int i = 0; i < Size; i++){
            this->cells[i] = new Cell[Size];
        }
        for(int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                this->cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;
}

Field::Field(Field &&other) {
    std::swap(cells, other.cells);
}

Field& Field::operator = (Field&& other){
    if(this != &other){
        std::swap(this->cells, other.cells);
    }
    return *this;
}

Cell** Field::GetCells() {
    return cells;
}

Field::~Field(){
    for(int i = 0; i < Size; i++){
        delete[] cells[i];
    }
    delete[] cells;
}

