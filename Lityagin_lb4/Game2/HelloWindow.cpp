#include "HelloWindow.h"

void HelloWindow::Hello() {
    Texture texture;
    Texture texture2;
    Sprite sprite1;
    texture.loadFromFile(FloorPNG);
    RenderWindow window(VideoMode(120, 80), "Це шо, тайм сквэр?!");

    while(window.isOpen()){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                sprite1 = Sprite(texture);
                sprite1.setPosition(i * 40, j * 40);
                window.draw(sprite1);
            }
        }
        texture2.loadFromFile(PlayPNG);
        sprite1 = Sprite(texture2);
        sprite1.setPosition(40, 20);
        window.draw(sprite1);
        //window.clear();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if(40 <= event.mouseButton.x && event.mouseButton.x <= 80 && 20 <= event.mouseButton.y && event.mouseButton.y <= 60) {
                        window.close();
                        RulesBuilder<2> rulesBuilder;
                        RulesEnemy<3> rulesEnemy;
                        RulesThing<48> rulesThing;
                        Game<RulesBuilder<2>, RulesEnemy<3>, RulesThing<48>> game(rulesBuilder, rulesEnemy, rulesThing);
                        game.StartGame();
                    }
                }
            }
        }
        window.display();
    }
}
