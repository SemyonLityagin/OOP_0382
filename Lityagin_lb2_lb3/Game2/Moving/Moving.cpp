#include "Moving.h"
using namespace sf;

void Move::Movement(RenderWindow *window, Field *field, Hero *gamer, Unit **evil, Thing **thing, Drawing* draw, int EVIL, int THING, Logger* logger) {
    int* coord;
    bool pressed = false;
    while(window->isOpen()){
        window->clear();
        draw->DrawFieldOnWindow(field->GetCells(), window);
        coord = gamer->GetCoord();
        sf::Event event;
        while(window->pollEvent(event)){
            if(coord[0] == 1 && coord[1] == 0){
                window->close();
            }
            if(event.type == sf::Event::Closed) {
                window->close();
            }
            if(!gamer->IsAlive()){
                window->close();
                std::cout << "hero dead";
            }
            if(event.key.code == sf::Keyboard::A && !pressed){
                pressed = true;
                MoveHero(field, gamer, coord[0]-1, coord[1]);
                Move::CheckObject(evil, thing, EVIL, THING, field);
                //footstep.play();
                MoveEvil(field, evil, EVIL);
                logger->Update();
            }
            if(event.key.code == sf::Keyboard::W && !pressed){
                pressed = true;
                MoveHero(field, gamer, coord[0], coord[1]-1);
                Move::CheckObject(evil, thing, EVIL, THING, field);
                //footstep.play();
                MoveEvil(field, evil, EVIL);
                logger->Update();
            }
            if(event.key.code == sf::Keyboard::D && !pressed){
                pressed = true;
                MoveHero(field, gamer, coord[0]+1, coord[1]);
                Move::CheckObject(evil, thing, EVIL, THING, field);
                //footstep.play();
                MoveEvil(field, evil, EVIL);
                logger->Update();
            }
            if(event.key.code == sf::Keyboard::S && !pressed){
                pressed = true;
                MoveHero(field, gamer, coord[0], coord[1]+1);
                Move::CheckObject(evil, thing, EVIL, THING, field);
                //footstep.play();
                MoveEvil(field, evil, EVIL);
                logger->Update();
            }
            if(event.type == Event::KeyReleased){
                pressed = false;
            }
        }
        window->display();
    }
}

void Move::MoveHero(Field* field, Unit* hero, int x, int y){
    hero->Move(field, x, y);
}

void Move::CheckObject(Unit** evil, Thing** thing, int EVIL, int THING, Field* field){
    int* coord;
    for(int i = 0; i < EVIL; i++){
        if(!evil[i]->IsAlive()){
            coord = evil[i]->GetCoord();
            if(coord[0] != -1){
                field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
                evil[i]->SetCoord(-1, -1);
            }
        }
    }
    for(int i = 0; i < THING; i++){
        if(!thing[i]->IsAvailable()){
            coord = thing[i]->GetCoord();
            if(coord[0] != -1){
                field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
                thing[i]->SetCoord(-1, -1);
            }
        }
    }

}

void Move::MoveEvil(Field* field, Unit** evils, int EVIL) {
    int* coords;
    int x;
    int y;
    int direction;
    srand(time(nullptr));
    for(int i = 0; i < EVIL; i++){
        if(evils[i]->IsAlive()) {
            direction = rand()%20;
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

