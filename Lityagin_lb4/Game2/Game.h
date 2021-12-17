#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "map/MapBuilder/Field/Cell/Cell.h"
#include "map/MapBuilder/Field/Field.h"
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
#include "./map/Things/Coin.h"
#include "./map/Things/Candy.h"
#include "./map/Things/Thing.h"
#include "./map/Units/Spider.h"
#include "./map/Factory/EntFactory.h"
#include "./map/Factory/EyeFactory.h"
#include "./map/Factory/SpiderFactory.h"
#include "./map/Factory/ObjectFactory.h"
#include "./Moving/Moving.h"
#include "./log/Observer.h"
#include "./log/Subject.h"
#include "./log/ConsoleLogger.h"
#include "./log/FileLogger.h"
#include "./log/Logger.h"
#include "./log/LoggerImplication.h"
#include "./log/Decorator.h"
#include "./log/ConcreteLog.h"

template<typename R1, typename R2, typename R3>
class Game{
private:
    Hero* gamer;
    Field* field;
    Unit** evil;
    Thing** thing;
    LoggerImplication* base;
    Logger *logger;
    int ENEMY;
    int THING;
public:
    Game(R1 ruleBuilder, R2 ruleEnemy, R3 ruleThing){
        //create field
        field = ruleBuilder.GetFieldFromBuilder();

        //check value of enemies and things
        if((ruleEnemy.GetValue() + ruleThing.GetValue()) >= (Size-2*Size/3)*(Size-2*Size/3)){
            ruleEnemy.SetValue((int)(Size*Size*4/100));
            ruleThing.SetValue((int)(Size*Size*2/100));
        }

        ENEMY = ruleEnemy.GetValue();
        THING = ruleThing.GetValue();
        //create gamer
        gamer = new Hero();
        field->GetCells()[Size-1][Size-2].SetObject(gamer);
        //create enemy
        evil = CreateEvil(field->GetCells(), ENEMY, ruleEnemy);
        //create things
        thing = CreateThing(field->GetCells(), THING, ruleThing);
    };
    void StartGame(){
        //choose logger
        std::cout << "Выберите тип логгера" << std::endl;
        int type;
        std::cin >> type;
        switch(type) {
            case 0: {
                LoggerImplication *log = new ConcreteLog();
                base = new FileLogger(log);
            }
            case 1: {
                LoggerImplication *log = new ConcreteLog();
                base = new ConsoleLogger(log);
            }
            default: {
                LoggerImplication *log = new ConcreteLog();
                LoggerImplication *log1 = new FileLogger(log);
                base = new ConsoleLogger(log1);
            }
        }
        logger = Logger::GetInstance(gamer, base);
        logger->Update();

        Move::Movement(field, gamer, evil, thing, ENEMY, THING, logger);
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
        delete field;
        for(int i = 0; i < ENEMY; i++){
            delete evil[i];
        }
        delete [] evil;
        for(int i = 0; i < THING; i++){
            delete thing[i];
        }
        delete [] thing;
        delete gamer;
        delete logger;
    }
};

#endif //GAME_GAME_H
