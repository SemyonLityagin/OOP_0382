#ifndef GAME_CONSOLELOGGER_H
#define GAME_CONSOLELOGGER_H

#include <iostream>
#include "Subject.h"
#include "LoggerImplication.h"

class ConsoleLogger:public LoggerImplication{
public:
    void Out(Subject* sub) override;
};

#endif //GAME_CONSOLELOGGER_H
