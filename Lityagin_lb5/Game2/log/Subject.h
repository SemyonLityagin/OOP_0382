#ifndef GAME_SUBJECT_H
#define GAME_SUBJECT_H

#include <iostream>
#include "Observer.h"

class Subject{
protected:
    Observer* observer = nullptr;
public:
    void SetObs(Observer* obs);
    void Notify();
    virtual std::string GetLog() = 0;
    friend std::ostream& operator<< (std::ostream &out, Subject* sub);
};

#endif //GAME_SUBJECT_H
