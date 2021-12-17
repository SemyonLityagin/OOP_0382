#include "ObjectAction.h"

ObjectAction::ObjectAction(Unit** enemy, Thing** thing, int ENEMY, int THING, Logger *logger, Field *field, Drawing* draw) {
    this->enemy = enemy;
    this->thing = thing;
    this->ENEMY = ENEMY;
    this->THING = THING;
    this->logger = logger;
    this->field = field;
    this->draw = draw;
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
    delete field;
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

std::string ObjectAction::GetData() {
    std::string data = "";
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            Cell cell =  field->GetCells()[i][j];
            data += std::to_string(cell.GetType());
            if(j == Size-1 && i == Size-1){
                data += "\n";
            }
            else{
                data += "\n";
            }
        }
    }
    data += std::to_string(THING) + "\n";
    for(int i = 0; i < THING; i++){
        data+= std::to_string(thing[i]->GetType()) + "\n"+ std::to_string(thing[i]->GetCoord()[0]) + "\n"+ std::to_string(thing[i]->GetCoord()[1]) + "\n";
    }
    data += std::to_string(ENEMY) + "\n";
    for(int i = 0; i < ENEMY; i++){
        data+= std::to_string(enemy[i]->GetType()) + "\n"+ std::to_string(enemy[i]->GetCoord()[0]) + "\n"+ std::to_string(enemy[i]->GetCoord()[1]) +  + "\n"+ std::to_string(enemy[i]->GetHealth()) + "\n";
    }
    return data;
}
void ObjectAction::GetStats(Unit **new_enemy, Thing **new_thing, int new_ENEMY, int new_THING, Field *new_field) {
    std::swap(field, new_field);
    delete new_field;
    ENEMY = new_ENEMY;
    THING = new_THING;

    for(int i = 0; i < ENEMY; i++){
        delete enemy[i];
    }
    delete [] enemy;
    for(int i = 0; i < THING; i++){
        delete thing[i];
    }
    delete [] thing;
    enemy = new_enemy;
    thing = new_thing;
    draw->UpdateCells(field->GetCells());
}
