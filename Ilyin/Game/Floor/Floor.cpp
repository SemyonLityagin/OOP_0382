#include "Floor.h"

Floor::Floor(int width, int height): width(width), height(height) {
    cells = new Cell**[WIDTH_OF_FLOOR];
    for (int i = 0; i < WIDTH_OF_FLOOR; i++) cells[i] = new Cell*[HEIGTH_OF_FLOOR];
};

Floor::Floor(const Floor& other){
    *this = other;
}

Floor& Floor::operator=(const Floor& other) {
    this->width = other.width;
    this->height = other.height;
    for(int i = 0; i < WIDTH_OF_FLOOR; i++) {
        for (int j = 0; j < HEIGTH_OF_FLOOR; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    return *this;
}

Floor& Floor::operator=(Floor&& other){
    this->width = other.width;
    other.width = 0;
    this->height = other.height;
    other.height = 0;
    for(int i = 0; i < WIDTH_OF_FLOOR; i++) {
        for (int j = 0; j < HEIGTH_OF_FLOOR; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    return *this;
};

void Floor::Draw_Floor(sf::RenderWindow* window) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            window->draw(*this->cells[i][j]->getSprite());
        }
    }
};

Floor::~Floor() {
    for (int i = 0; i < height; ++i) delete cells[i];
    delete cells;
}
