#ifndef GAME_FILELOGGER_H
#define GAME_FILELOGGER_H

#include <fstream>
#include <iostream>
#include "Subject.h"
#include "Decorator.h"

class FileLogger:public Decorator{
private:
    std::ofstream output;
public:
    FileLogger(LoggerImplication* log): Decorator(log){
        output.open("/home/cruelcookie/CLionProjects/Game2/log/log.txt");
        if (output.fail())
        {
            throw std::iostream::failure("Cannot open file: log.txt");
        }
    };
    ~FileLogger() override;
    void Out(Subject* sub) override;
};

#endif //GAME_FILELOGGER_H
