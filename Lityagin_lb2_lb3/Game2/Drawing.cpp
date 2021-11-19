#include "Drawing.h"
#include "Game.h"

Drawing::Drawing() {
    textureCell[0].loadFromFile(EnterPNG);
    textureCell[1].loadFromFile(FloorPNG);
    textureCell[2].loadFromFile(WallPNG);
    textureCell[3].loadFromFile(ExitPNG);
    textureObject[0].loadFromFile(HeroPNG);
    textureObject[1].loadFromFile(EyePNG);
    textureObject[2].loadFromFile(SpiderPNG);
    textureObject[3].loadFromFile(EntPNG);
    textureObject[4].loadFromFile(AxePNG);
    textureObject[5].loadFromFile(CandyPNG);
    textureObject[6].loadFromFile(CoinPNG);
}

void Drawing::DrawFieldOnWindow(Cell** cells, RenderWindow *window) {
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            cellType = cells[i][j].GetType();
            objectType = cells[i][j].GetObjectType();

            sprite = Sprite(textureCell[cellType]);
            sprite.setPosition(i * 40, j * 40);
            window->draw(sprite);

            if(objectType != empty){
                sprite = Sprite(textureObject[objectType]);
                sprite.setPosition(i * 40, j * 40);
                window->draw(sprite);
            }
            if(objectType == hero){
                if (!font.loadFromFile("../texture/HallFont.ttf"))
                {
                    std::cout << "i don't know this";
                }
                text.setFont(font);
                text.setString("HP: " + std::to_string(cells[i][j].GetObject()->GetHealth()));
                text.setCharacterSize(40);
                text.setColor(Color::Cyan);
                text.setStyle( Text::Underlined);
                text.setPosition(Size*40 + 5, 10);
                window->draw(text);
                text.setString("Force: " + std::to_string(cells[i][j].GetObject()->GetForce()));
                text.setPosition(Size*40 + 5, 60);
                window->draw(text);
            }
        }
    }
}
/*
void Drawing::HelloWindow() {
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
                    if(40 <= event.mouseButton.x <= 80 && 20 <= event.mouseButton.y <= 60 );
                    Game game = Game();
                    game.StartGame(10, 3);
                }
            }
        }
        window.display();
    }
}
*/
