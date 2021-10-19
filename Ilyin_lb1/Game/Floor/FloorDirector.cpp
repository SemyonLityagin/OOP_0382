#include "FloorDirector.h"

FloorDirector::FloorDirector(FloorBuilder* b){
    this->builder = b;
};

void FloorDirector::setBuilder(FloorBuilder* b){
    this->builder = b;
};

void FloorDirector::Builder_FloorBuilderTree(){
    this->builder->GeneratNormalCells();
    this->builder->GeneratWallCells();
    this->builder->GeneratEntryCell();
    this->builder->GeneratExitCell();
};