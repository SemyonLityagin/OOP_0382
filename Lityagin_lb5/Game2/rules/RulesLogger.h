#ifndef GAME_RULESLOGGER_H
#define GAME_RULESLOGGER_H

#include "../log/Logger.h"
#include "../log/ConcreteLog.h"
#include "../log/FileLogger.h"
#include "../log/ConsoleLogger.h"

template <int T>
class RulesLogger{
private:
    int loggerID = T;
public:
    LoggerImplication* GetBaseLogger(){
        LoggerImplication* base;
        switch(loggerID) {
            case 0: {
                LoggerImplication *log = new ConcreteLog();
                base = new FileLogger(log);
                break;
            }
            case 1: {
                LoggerImplication *log = new ConcreteLog();
                base = new ConsoleLogger(log);
                break;
            }
            default: {
                LoggerImplication *log = new ConcreteLog();
                LoggerImplication *log1 = new FileLogger(log);
                base = new ConsoleLogger(log1);
            }
        }
        return base;
    }
};

#endif //GAME_RULESLOGGER_H
