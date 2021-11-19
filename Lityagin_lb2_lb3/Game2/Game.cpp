#include "Game.h"
#include "log/ConcreteLog.h"

void Game::StartGame(int EVIL, int THING) {
    //Music background;
    //background.setLoop(true);
    //background.openFromFile("../audio/Game.wav");
    //background.play();
    if((EVIL + THING) >= (Size-2*Size/3)*(Size-2*Size/3)){
        EVIL = 10;
        THING = 5;
    }
    //SoundBuffer sound;
    //sound.loadFromFile("../audio/footstep.wav");
    //Sound footstep;
    //footstep.setBuffer(sound);

    RenderWindow window(VideoMode(Size*40+100, Size*40), "Це шо, тайм сквэр?!");
    Drawing draw = Drawing();

    //create field
    auto* builder = new FirstMapBuilder();
    auto director = MapDirector(builder);
    director.ConstructMap();
    Field* field = builder->ReturnField();
    delete builder;

    //create gamer
    Hero* gamer = new Hero();
    field->GetCells()[Size-1][Size-2].SetObject(gamer);
    //create enemy
    Unit** evil = CreateEvil(field->GetCells(), EVIL);
    //create things
    Thing** thing = CreateThing(field->GetCells(), THING);
    LoggerImplication* log = new ConcreteLog();
    LoggerImplication* log1 = new FileLogger(log);
    LoggerImplication* log2 = new ConsoleLogger(log1);
    Logger* logger = Logger::GetInstance(gamer, log2);
    logger->Update();

    Move::Movement(&window, field, gamer, evil, thing, &draw, EVIL, THING, logger);

    delete field;
    for(int i = 0; i < EVIL; i++){
        delete evil[i];
    }
    delete [] evil;
    for(int i = 0; i < THING; i++){
        delete thing[i];
    }
    delete [] thing;
    delete gamer;
    delete logger;
    delete log;
}

Unit** Game::CreateEvil(Cell** cell, int EVIL) {
    Unit** evil = new Unit*[EVIL];
    auto* eyeFactory = new EyeFactory;
    auto* entFactory = new EntFactory;
    auto* spiderFactory = new SpiderFactory;
    int direction;
    int x = 0, y = 0;
    srand(time(NULL));
    for(int i = 0; i < EVIL; i++){
        direction = rand()%9;
        if(direction < 3){
            evil[i] = eyeFactory->CreateUnit();
        }
        else if(direction < 6){
            evil[i] = entFactory->CreateUnit();
        }
        else if(direction < 9){
            evil[i] = spiderFactory->CreateUnit();
        }
        while(!cell[x][y].IsMovable() || cell[x][y].GetObjectType() != empty) {
            x = rand() % (Size - 2) + 1;
            y = rand() % (Size - 2) + 1;
        }
        evil[i]->SetCoord(x, y);
        cell[x][y].SetObject(evil[i]);
    }
    delete eyeFactory;
    delete entFactory;
    delete spiderFactory;
    return evil;
}

Thing** Game::CreateThing(Cell** cell, int THING) {
    Thing** thing = new Thing*[THING];
    int direction;
    int x = 0, y = 0;
    for(int i = 0; i < THING; i++){
        direction = rand()%9;
        if(direction < 3){
            thing[i] = new Candy();
        }
        else if(direction < 6){
            thing[i] = new Axe();
        }
        else if(direction < 9){
            thing[i] = new Coin();
        }
        while(!cell[x][y].IsMovable() || cell[x][y].GetObjectType() != empty) {
            x = rand() % (Size - 2) + 1;
            y = rand() % (Size - 2) + 1;
        }
        thing[i]->SetCoord(x, y);
        cell[x][y].SetObject(thing[i]);
    }
    return thing;
}



