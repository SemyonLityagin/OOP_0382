#ifndef GAME_LOGGERIMPLICATION_H
#define GAME_LOGGERIMPLICATION_H

#include "Subject.h"

class LoggerImplication{
public:
    virtual void Out(Subject* sub)=0;
    virtual ~LoggerImplication() = default;
};

#endif //GAME_LOGGERIMPLICATION_H
