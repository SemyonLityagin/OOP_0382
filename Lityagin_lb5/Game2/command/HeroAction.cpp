#include "HeroAction.h"

HeroAction::HeroAction(Hero* gamer, Field* field) {
    this->gamer = gamer;
    this->field = field;
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

