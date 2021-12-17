#include "Windows.h"
#include "Game.h"
#include "rules/RulesBuilder.h"
#include "rules/RulesThing.h"
#include "rules/RulesEnemy.h"
#include "rules/RulesLogger.h"

int main(){
    if(Windows::Hello()){
        RulesBuilder<2> rulesBuilder;
        RulesEnemy<1> rulesEnemy;
        RulesThing<0> rulesThing;
        RulesLogger<1> rulesLogger;
        Game<RulesBuilder<2>, RulesEnemy<1>, RulesThing<0>, RulesLogger<1>> game(rulesBuilder, rulesEnemy, rulesThing, rulesLogger);
        game.StartGame();
    }
    return 0;
}