#ifndef GAME_DECORATOR_H
#define GAME_DECORATOR_H

#include "LoggerImplication.h"

class Decorator: public LoggerImplication{
protected:
    LoggerImplication* logger;
public:
    Decorator(LoggerImplication* log): logger(log){};
    ~Decorator() override;
    void Out(Subject* sub) override;
};

#endif //GAME_DECORATOR_H
