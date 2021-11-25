#ifndef GAME_CONCRETELOG_H
#define GAME_CONCRETELOG_H

#include "LoggerImplication.h"

class ConcreteLog: public LoggerImplication{
public:
    ConcreteLog(){};
    void Out(Subject* sub) override{};
};
#endif //GAME_CONCRETELOG_H
