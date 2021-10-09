#include "Field.h"

Field::Field(){
    cells = new Cell*[Size];
    for(int i = 0; i < Size; i++){
        cells[i] = new Cell[Size];
    }
}

Field::Field(const Field& other):Field(){
    for(int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

Field& Field::operator=(const Field& other) {
    if(this != &other){
        //*this = Field();
        for(int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                this->cells[i][j] = other.cells[i][j];

            }
        }
    }
    return *this;
}

Field::Field(Field &&other) {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            std::swap(cells[i][j], other.cells[i][j]);
        }
    }
}

Field& Field::operator = (Field&& other){
    if(this != &other){
        for(int i = 0; i < Size; i++){
            for(int j = 0; j < Size; j++){
                std::swap(this->cells[i][j], other.cells[i][j]);
            }
        }
    }
    return *this;
}

Field::~Field(){
    delete[] cells;
}

void Field::DrawCells(sf::RenderWindow *window) {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            window->draw(this->cells[i][j].GetSprite());
        }
    }
}
