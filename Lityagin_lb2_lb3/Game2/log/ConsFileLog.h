#ifndef GAME_CONSFILELOG_H
#define GAME_CONSFILELOG_H

#include <iostream>
#include <fstream>
#include "Subject.h"
#include "LoggerImplication.h"

class ConsFileLog:public LoggerImplication{
private:
    std::ofstream output;
public:
    ConsFileLog(const std::string& fileName);
    ~ConsFileLog() override;
    void Out(Subject* sub) override;
};

#endif //GAME_CONSFILELOG_H
