#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "map/MapBuilder/MapDirector.h"
#include "map/MapBuilder/FirstMapBuilder.h"
#include "map/MapBuilder/SecondMapBuilder.h"
#include "Drawing.h"

#include "./map/Units/Hero.h"
#include "./map/Units/Unit.h"
#include "./map/Units/Ent.h"
#include "./map/Units/Eye.h"
#include "./map/Units/Spider.h"
#include "./map/Things/Axe.h"
//#include "./map/Things/Coin.h"
#include "./map/Things/Candy.h"
#include "./map/Things/Thing.h"
#include "./map/Units/Spider.h"
#include "./map/Factory/EntFactory.h"
#include "./map/Factory/EyeFactory.h"
#include "./map/Factory/SpiderFactory.h"
#include "./map/Factory/ObjectFactory.h"
#include "./log/Observer.h"
#include "./log/Subject.h"
#include "./log/ConsoleLogger.h"
#include "./log/FileLogger.h"
#include "./log/Logger.h"
#include "./log/LoggerImplication.h"
#include "./log/Decorator.h"
#include "./log/ConcreteLog.h"
#include "./command/Manager.h"

template<typename R1, typename R2, typename R3, typename R4>
class Game{
private:
    Commander game;
    Command command;
    Manager* manager;
    Drawing* draw;
public:
    Game(R1 ruleBuilder, R2 ruleEnemy, R3 ruleThing, R4 ruleLogger){
        //create field
        Field* field = ruleBuilder.GetFieldFromBuilder();
        draw = new Drawing(field->GetCells());
        //create commander
        game = Commander();
        Command command = nothing;

        //check value of enemies and things
        if(ruleEnemy.GetValue() >= (Size-2*Size/3)){
            ruleEnemy.SetValue((int)(Size*Size*4/100));
        }
        if(ruleThing.GetValue() >= (Size-2*Size/3)){
            ruleThing.SetValue((int)(Size*Size*4/100));
        }
        int ENEMY = ruleEnemy.GetValue();
        int THING = ruleThing.GetValue();

        //create gamer
        Hero* gamer = new Hero();
        field->GetCells()[Size-1][Size-2].SetObject(gamer);

        //create enemy
        Unit** evil = CreateEvil(field->GetCells(), ENEMY, ruleEnemy);

        //create things
        Thing** thing = CreateThing(field->GetCells(), THING, ruleThing);

        //choose logger
        Logger* logger = Logger::GetInstance(gamer, ruleLogger.GetBaseLogger());

        //create manager
        ObjectAction* objAct = new ObjectAction(evil, thing, ENEMY, THING, logger, field, draw);
        HeroAction* heroAct = new HeroAction(gamer, field, logger, ruleLogger.GetBaseLogger());
        manager = new Manager(objAct, heroAct);
    };

    void StartGame(){
        if(Size < 6){
            throw std::invalid_argument("Size of field error!");
        }
        RenderWindow window(VideoMode(Size*40+120, Size*40), ".:Catacombs:.", sf::Style::Close | sf::Style::Titlebar);
        manager->SetWindow(&window);
        int* coord;
        while(window.isOpen()){
            window.clear();
            sf::Event event;
            while(window.pollEvent(event)){
                command = game.Moving(event);
                manager->DoIteration(command);
                manager->DoIteration(death);
                manager->DoIteration(win);
                command = nothing;
            }
            draw->DrawFieldOnWindow(&window);
            window.display();
        }
    };

    Unit** CreateEvil(Cell** cell, int EVIL, R2 ruleEnemy){
        Unit** evil = ruleEnemy.GetEnemy();
        int x = 0, y = 0;
        srand(time(NULL));
        for(int i = 0; i < EVIL; i++){
            while(!cell[x][y].IsMovable() || cell[x][y].GetObjectType() != empty) {
                x = rand() % (Size - 2) + 1;
                y = rand() % (Size - 2) + 1;
            }
            evil[i]->SetCoord(x, y);
            cell[x][y].SetObject(evil[i]);
        }
        return evil;
    };

    Thing** CreateThing(Cell** cell, int THING, R3 ruleThing){
        Thing** thing = ruleThing.GetThing();
        int x = 0, y = 0;
        for(int i = 0; i < THING; i++){
            while(!cell[x][y].IsMovable() || cell[x][y].GetObjectType() != empty) {
                x = rand() % (Size - 2) + 1;
                y = rand() % (Size - 2) + 1;
            }
            thing[i]->SetCoord(x, y);
            cell[x][y].SetObject(thing[i]);
        }
        return thing;
    }
    ~Game(){
        delete draw;
        delete manager;
    }
};

#endif //GAME_GAME_H
