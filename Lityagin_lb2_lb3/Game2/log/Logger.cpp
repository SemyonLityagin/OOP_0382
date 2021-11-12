#include "Logger.h"

Logger* Logger::logger= nullptr;
Logger* Logger::GetInstance(Subject* sub, LoggerImplication* log)
{
    if(logger==nullptr){
        logger = new Logger(sub, log);
    }
    logger->subject->SetObs(logger);
    return logger;
}
void Logger::Update(){
    log->Out(subject);
}

