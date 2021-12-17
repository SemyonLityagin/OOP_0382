#ifndef GAME_LOADERROR_H
#define GAME_LOADERROR_H

#include "iostream"

enum objError {cellEr, thingEr, enemyEr, heroEr};
enum Error {typeEr, posEr, hpEr, forceEr, mhpEr, coinEr, numbEr};

class LoadError{
private:
    std::string m_error = "Not correct data for ";
public:
    LoadError(std::string error): m_error(error){};
    LoadError(objError obj, Error except);
    const char* getError();
};
#endif //GAME_LOADERROR_H
