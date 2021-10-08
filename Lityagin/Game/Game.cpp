#include "Game.h"
using namespace sf;

void Game::StartGame() {
    RenderWindow window(VideoMode(400, 400), "Game!");
    auto builder = new MapBuilderOne();
    auto director = MapDirector(builder);
    director.ConstructMap();
    Field* field = builder->ReturnField();
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        field->DrawCells(&window);
        window.display();
    }
    delete builder;
}