#include "Game.h"
using namespace sf;

void Game::StartGame() {
    RenderWindow window(VideoMode(Size*40, Size*40), "Game!");
    MapBuilderOne* builder = new MapBuilderOne();
    MapDirector director = MapDirector(builder);
    director.ConstructMap();
    Field* field = builder->ReturnField();
    Field field2;
    field2 = *field;
    delete field;
    if (field2.cells[2][2].IsMovable()) {
        std::cout << "Yes, movable!" << std::endl;
    }
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        field2.DrawCells(&window);
        window.display();
    }
    delete builder;
}