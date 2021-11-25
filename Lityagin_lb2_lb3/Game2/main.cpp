#include "Game.h"
#include "Drawing.h"

int main(){
    int evil;
    int thing;
    Game game = Game();
    std::cin >> evil;
    std::cin >> thing;
    game.StartGame(evil, thing);

    //Drawing::HelloWindow();
    return 0;
}