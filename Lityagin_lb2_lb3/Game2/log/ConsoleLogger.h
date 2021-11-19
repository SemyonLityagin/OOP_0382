#ifndef GAME_CONSOLELOGGER_H
#define GAME_CONSOLELOGGER_H

#include <iostream>
#include "Subject.h"
#include "Decorator.h"

class ConsoleLogger:public Decorator{
public:
    ConsoleLogger(LoggerImplication* log): Decorator(log){};
    ~ConsoleLogger() override;
    void Out(Subject* sub) override;
};

#endif //GAME_CONSOLELOGGER_H
