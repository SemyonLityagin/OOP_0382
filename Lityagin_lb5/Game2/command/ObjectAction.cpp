#include "ObjectAction.h"

ObjectAction::ObjectAction(Unit** enemy, Thing** thing, int ENEMY, int THING, Logger *logger, Field *field) {
    this->enemy = enemy;
    this->thing = thing;
    this->ENEMY = ENEMY;
    this->THING = THING;
    this->logger = logger;
    this->field = field;
}

void ObjectAction::CheckObject() {
    logger->Update();
    int* coord;
    for(int i = 0; i < ENEMY; i++){
        if(!enemy[i]->IsAlive()){
            coord = enemy[i]->GetCoord();
            if(coord[0] != -1){
                field->GetCells()[coord[0]][coord[1]].SetObject(nullptr);
                enemy[i]->SetCoord(-1, -1);
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

void ObjectAction::MoveEnemy() {
    int* coords;
    int x;
    int y;
    int direction;
    srand(time(nullptr));
    for(int i = 0; i < ENEMY; i++){
        if(enemy[i]->IsAlive()) {
            direction = rand()%20;
            coords = enemy[i]->GetCoord();
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
            enemy[i]->Move(field->GetCells(), x, y);
        }
    }
}

ObjectAction::~ObjectAction() {
    for(int i = 0; i < ENEMY; i++){
        delete enemy[i];
    }
    delete [] enemy;
    for(int i = 0; i < THING; i++){
        delete thing[i];
    }
    delete [] thing;
    delete logger;
}
