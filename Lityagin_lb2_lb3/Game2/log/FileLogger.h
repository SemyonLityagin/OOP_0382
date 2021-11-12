#ifndef GAME_FILELOGGER_H
#define GAME_FILELOGGER_H

#include <fstream>
#include <iostream>
#include "Subject.h"
#include "LoggerImplication.h"

class FileLogger:public LoggerImplication{
private:
    std::ofstream output;
public:
    FileLogger(const std::string& fileName);
    ~FileLogger() override;
    void Out(Subject* sub) override;
};

#endif //GAME_FILELOGGER_H
