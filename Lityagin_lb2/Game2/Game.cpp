#include "Game.h"
using namespace sf;

#define EVIL 3

void Game::StartGame() {
    RenderWindow window(VideoMode(Size*40, Size*40), "Це шо, тайм сквэр?!");
    int* coord;
    bool pressed = false;

    //create field
    auto* builder = new FirstMapBuilder();
    auto director = MapDirector(builder);
    director.ConstructMap();
    Field* field = builder->ReturnField();
    delete builder;

    //create gamer
    auto* heroFactory = new HeroFactory;
    Unit* gamer = heroFactory->CreateUnit();
    field->GetCells()[Size-1][Size-2].SetObject(gamer);
    delete heroFactory;

    Unit* evil[EVIL];

    auto* eyeFactory = new EyeFactory;
    evil[0] = eyeFactory->CreateUnit();
    evil[0]->SetCoord(5, 5);
    field->GetCells()[5][5].SetObject(evil[0]);
    delete eyeFactory;

    auto* entFactory = new EntFactory;
    evil[1] = entFactory->CreateUnit();
    evil[1]->SetCoord(7, 5);
    field->GetCells()[7][5].SetObject(evil[1]);
    delete entFactory;

    auto* spiderFactory = new SpiderFactory;
    evil[2] = spiderFactory->CreateUnit();
    evil[2]->SetCoord(Size-2, Size-2);
    field->GetCells()[Size-2][Size-2].SetObject(evil[1]);
    delete spiderFactory;

    while(window.isOpen()){
        window.clear();
        DrawFieldOnWindow(field->GetCells(), &window);
        coord = gamer->GetCoord();
        sf::Event event;
        while(window.pollEvent(event)){
            if(coord[0] == 1, coord[1] == 0){
                window.close();
            }
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.key.code == sf::Keyboard::A && pressed == false){
                pressed = true;
                MoveHero(field, gamer, coord[0]-1, coord[1]);
                MoveEvil(field, evil);
                if(!gamer->IsAlive()){
                    window.close();
                }
            }
            if(event.key.code == sf::Keyboard::W && pressed == false){
                pressed = true;
                MoveHero(field, gamer, coord[0], coord[1]-1);
                MoveEvil(field, evil);
                if(!gamer->IsAlive()){
                    window.close();
                }
            }
            if(event.key.code == sf::Keyboard::D && pressed == false){
                pressed = true;
                MoveHero(field, gamer, coord[0]+1, coord[1]);
                MoveEvil(field, evil);
                if(!gamer->IsAlive()){
                    window.close();
                }
            }
            if(event.key.code == sf::Keyboard::S && pressed == false){
                pressed = true;
                MoveHero(field, gamer, coord[0], coord[1]+1);
                MoveEvil(field, evil);
                if(!gamer->IsAlive()){
                    window.close();
                }
            }
            if(event.type == Event::KeyReleased){
                pressed = false;
            }
            for(int i = 0; i < EVIL; i++){
                if(!evil[i]->IsAlive()){
                    coord = evil[i]->GetCoord();
                    if(coord[0] != -1){
                        field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
                    }
                    evil[i]->SetCoord(-1, -1);
                }
            }
        }
        window.display();
    }
    delete field;
    for(int i = 0; i < EVIL; i++){
        delete evil[i];
    }
}

void Game::MoveHero(Field* field, Unit* hero, int x, int y){
    hero->Move(field, x, y);
}

void Game::MoveEvil(Field* field, Unit** evils) {
    int* coords;
    int x;
    int y;
    int direction;
    for(int i = 0; i < EVIL; i++){
        direction = rand()%20;
        if(evils[i]->IsAlive()) {
            coords = evils[i]->GetCoord();
            if (direction < 5) {
                x = coords[0] + 1;
                y = coords[1];
            } else if (direction < 10) {
                x = coords[0] - 1;
                y = coords[1];
            } else if (direction < 15) {
                x = coords[0];
                y = coords[1] + 1;
            } else if (direction < 20) {
                x = coords[0];
                y = coords[1] - 1;
            }
            evils[i]->Move(field, x, y);
            if (field->GetCells()[x][y].GetObjectType() == hero) {
                evils[i]->Interaction(field->GetCells()[x][y].GetObject());
            }
        }
    }
}

void Game::DrawFieldOnWindow(Cell** cells, sf::RenderWindow *window) {
    Texture texture[11];
    texture[0].loadFromFile(EnterPNG);
    texture[1].loadFromFile(FloorPNG);
    texture[2].loadFromFile(WallPNG);
    texture[3].loadFromFile(ExitPNG);
    texture[4].loadFromFile(HeroPNG);
    texture[5].loadFromFile(EyePNG);
    texture[6].loadFromFile(SpiderPNG);
    texture[7].loadFromFile(EntPNG);
    texture[8].loadFromFile(AxePNG);
    texture[9].loadFromFile(CandyPNG);
    texture[10].loadFromFile(CoinPNG);
    Sprite sprite;
    CellTypes cellType;
    ObjectType objectType;
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            cellType = cells[i][j].GetType();
            objectType = cells[i][j].GetObjectType();

            sprite = Sprite(texture[cellType]);
            sprite.setPosition(i * 40, j * 40);
            window->draw(sprite);

            if(objectType != empty){
                sprite = Sprite(texture[objectType+4]);
                sprite.setPosition(i * 40, j * 40);
                window->draw(sprite);
            }
        }
    }
}
