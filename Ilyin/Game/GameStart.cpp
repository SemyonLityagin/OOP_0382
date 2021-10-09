#include "GameStart.h"

void GameStart::StartGame() {
    sf::RenderWindow window(sf::VideoMode(WIDTH_OF_FLOOR*WIDTH, HEIGTH_OF_FLOOR*WIDTH), "OOP: Lab 1");
    auto builder = new FloorBuilderTree();
    auto director = FloorDirector(builder);
    director.Builder_FloorBuilderTree();
    Floor* floor = builder->getFloor();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        floor->Draw_Floor(&window);
        window.display();
    }
    delete builder;
}
