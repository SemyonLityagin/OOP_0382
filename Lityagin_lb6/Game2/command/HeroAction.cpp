#include "HeroAction.h"

HeroAction::HeroAction(Hero* gamer, Field* field, Logger* logger, LoggerImplication* base) {
    this->gamer = gamer;
    this->field = field;
    this->logger = logger;
    this->base = base;
}

void HeroAction::MoveHeroLeft() {
    coord = gamer->GetCoord();
    gamer->Move(field->GetCells(), coord[0]-1, coord[1]);
}

void HeroAction::MoveHeroUp() {
    coord = gamer->GetCoord();
    gamer->Move(field->GetCells(), coord[0], coord[1]-1);
}

void HeroAction::MoveHeroRight() {
    coord = gamer->GetCoord();
    gamer->Move(field->GetCells(), coord[0]+1, coord[1]);
}

void HeroAction::MoveHeroDown() {
    coord = gamer->GetCoord();
    gamer->Move(field->GetCells(), coord[0], coord[1]+1);
}

bool HeroAction::CheckDeath() {
    if(!gamer->IsAlive()){
        return true;
    }
    else{
        return false;
    }
}

bool HeroAction::CheckWin(){
    coord = gamer->GetCoord();
    if(coord[0] == 1 && coord[1] == 0){
        return true;
    }
    else{
        return false;
    }
}

HeroAction::~HeroAction() {
    delete gamer;
}

std::string HeroAction::GetData() {
    std::string data = "";
    data += std::to_string(gamer->GetType())+ "\n" + std::to_string(gamer->GetCoord()[0]) + "\n"+ std::to_string(gamer->GetCoord()[1]) + "\n"+ std::to_string(gamer->GetHealth()) + "\n"+ std::to_string(gamer->GetForce()) + "\n"+ std::to_string(gamer->GetMaxHealth()) + "\n"+ std::to_string(gamer->GetCoins());
    return data;
}

void HeroAction::GetStats(Hero *new_gamer, Field* new_field) {
    delete gamer;
    gamer = new_gamer;
    field = new_field;
    logger->GetInstance(gamer, base);
}

