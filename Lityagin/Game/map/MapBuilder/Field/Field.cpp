#include "Field.h"

Field::Field(){
    cells = new Cell**[Size];
    for(int i = 0; i < Size; i++){
        cells[i] = new Cell*[Size];
    }
}

Field::~Field(){
    for(int i = 0; i < Size; i++){
        delete cells[i];
    }
    delete cells;
}

void Field::DrawCells(sf::RenderWindow *window) {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            window->draw(*this->cells[i][j]->sprite);
        }
    }
}
