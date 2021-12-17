#include "Windows.h"

bool Windows::Hello() {
    Texture texture;
    Texture texture2;
    Sprite sprite1;
    texture.loadFromFile(FloorPNG);
    RenderWindow window(VideoMode(8*40, 6*40), ".:Catacombs:.", sf::Style::Close | sf::Style::Titlebar);

    while(window.isOpen()){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 6; j++){
                sprite1 = Sprite(texture);
                sprite1.setPosition(i * 40, j * 40);
                window.draw(sprite1);
            }
        }
        texture2.loadFromFile(PlayPNG);
        sprite1 = Sprite(texture2);
        sprite1.setPosition(140, 40);
        window.draw(sprite1);
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if(140 <= event.mouseButton.x && event.mouseButton.x <= 180 && 40 <= event.mouseButton.y && event.mouseButton.y <= 80) {
                        window.close();
                    }
                }
            }
        }
        window.display();
    }
    return true;
}

