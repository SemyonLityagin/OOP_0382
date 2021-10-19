#include "Game.h"
#include <unistd.h>

Game::Game() {
    this->field = new Field;
    this->window = new sf::RenderWindow();
    for (int i = 0; i < 4; i++) {
        field_textures[i] = new sf::Texture;
        field_sprites[i] = new sf::Sprite(*field_textures[i]);
    }
}

void Game::start_game() {
    window->create(sf::VideoMode(RESULUTION_WIDTH, RESULUTION_WIDTH), NAME);
    this->loadTextures();
    auto builder = new PlainFieldBuilder();
    auto f_director = FieldDirector(builder);
    f_director.build_plain_field();
    field = builder->get_field();

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        this->drawField();
        window->display();
    }

    delete builder;
}

void Game::loadTextures() {
    for (int i = 0; i < 4; i++){
        switch (i) {
            case 0:
                field_textures[i]->loadFromFile(WALL_TEXTURE_PATH);
                break;
            case 1:
                field_textures[i]->loadFromFile(FOUNDATION_TEXTURE_PATH);
                break;
            case 2:
                field_textures[i]->loadFromFile(EXIT_TEXTURE_PATH);
                break;
            case 3:
                field_textures[i]->loadFromFile(ENTRY_TEXTURE_PATH);
                break;
        }
        field_sprites[i]->setTexture(*field_textures[i]);
        field_sprites[i]->setTextureRect(sf::IntRect(0, 0, WIDTH, WIDTH));
    }
}

void Game::drawField() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            auto cell = field->getCell(i, j);
            this->field_sprites[cell.get_type()]->setPosition(sf::Vector2f(i * WIDTH, j * WIDTH));
            window->draw(*this->field_sprites[cell.get_type()]);
        }
    }
}


