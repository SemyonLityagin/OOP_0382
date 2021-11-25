#include "Game.h"
#include "./rules/RulesBuilder.h"
#include "Drawing.h"
#include "rules/RulesThing.h"
#include "rules/RulesEnimy.h"

int main(){
    int evil;
    int thing;
    int builder;
    std::cout << "Input number for choose builder" << std::endl;
    std::cin >> builder;
    RulesBuilder<int> rulesBuilder(builder);
    std::cout << "Input number for choose value of enimies" << std::endl;
    std::cin >> evil;
    RulesEnimy<int> rulesEnimy(evil);
    std::cout << "Input number for choose value of things" << std::endl;
    std::cin >> thing;
    RulesThing<int> rulesThing(thing);
    Game<RulesBuilder<int>, RulesEnimy<int>, RulesThing<int>> game(rulesBuilder, rulesEnimy, rulesThing);
    game.StartGame();

    //Drawing::HelloWindow();
    return 0;
}