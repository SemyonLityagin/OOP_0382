#include "Game.h"
using namespace sf;

void Game::StartGame() {
    RenderWindow window(VideoMode(Size*40, Size*40), "Game!");
    auto* builder = new FirstMapBuilder();
    auto director = MapDirector(builder);
    director.ConstructMap();
    Field* field = builder->ReturnField();
    delete builder;
/*
    auto* builder2 = new SecondMapBuilder();
    director = MapDirector(builder2);
    director.ConstructMap();
    Field* field2 = builder2->ReturnField();
    Field field3;
    Field field4;
    delete builder2;
    field3 = std::move(*field2);
    field4 = std::move(*field);
    delete field2;
    delete field;
*/
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        DrawFieldOnWindow(field->GetCells(), &window);
        window.display();
    }
    delete field;
    //delete field2;
}

void Game::DrawFieldOnWindow(Cell** cells, sf::RenderWindow *window) {
    Texture texture;
    Sprite sprite;
    int number;
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            number = cells[i][j].GetType();
            switch(number){
                case 0: {
                    texture.loadFromFile(EnterPNG);
                    sprite = Sprite(texture);
                    sprite.setPosition(i * 40, j * 40);
                    break;
                }
                case 1: {
                    texture.loadFromFile(FloorPNG);
                    sprite = Sprite(texture);
                    sprite.setPosition(i * 40, j * 40);
                    break;
                }
                case 2: {
                    texture.loadFromFile(WallPNG);
                    sprite = Sprite(texture);
                    sprite.setPosition(i * 40, j * 40);
                    break;
                }
                case 3: {
                    texture.loadFromFile(ExitPNG);
                    sprite = Sprite(texture);
                    sprite.setPosition(i * 40, j * 40);
                    break;
                }
                default:
                    std::cout << "Not correct type in " << i << " " << j;
            }
            window->draw(sprite);
        }
    }
}