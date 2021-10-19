#include "GameStart.h"
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));//527, 55, 123
    GameStart::StartGame();
    return 0;
}