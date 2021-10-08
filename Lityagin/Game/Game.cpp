#include "Game.h"
using namespace sf;

void Game::StartGame() {
    RenderWindow window(VideoMode(400, 400), "Game!");
    auto builder = new MapBuilderOne();
    auto director = MapDirector(builder);
    director.ConstructMap();
    Field* field = builder->ReturnField();
    Field field2;
    field2 = *field;
    delete field;
    Cell p1 = Cell();
    p1.SetTexture("/home/cruelcookie/CLionProjects/Game/texture/CellStart.png");
    p1.SetPosition(1,1);
    Cell p2;
    p2 = p1;
    p2.SetPosition(3, 4);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        field2.DrawCells(&window);
        window.draw(*p1.GetSprite());
        window.draw(*p2.GetSprite());
        window.display();
    }
    delete builder;
}