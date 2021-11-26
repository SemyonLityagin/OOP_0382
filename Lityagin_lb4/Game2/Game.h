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
    R1 ruleBuilder;
    R2 ruleEnemy;
    R3 ruleThing;
public:
    Game(R1 rule1, R2 rule2, R3 rule3) : ruleBuilder(rule1), ruleEnemy(rule2), ruleThing(rule3){};
    void StartGame(){
        //Music background;
        //background.setLoop(true);
        //background.openFromFile("../audio/Game.wav");
        //background.play();
        if((ruleEnemy.GetValue() + ruleThing.GetValue()) >= (Size-2*Size/3)*(Size-2*Size/3)){
            ruleEnemy.SetValue((int)(Size*Size*4/100));
            ruleThing.SetValue((int)(Size*Size*2/100));
            std::cout << ruleEnemy.GetValue();
        }
        //SoundBuffer sound;
        //sound.loadFromFile("../audio/footstep.wav");
        //Sound footstep;
        //footstep.setBuffer(sound);

        //create field
        MapBuilder* builder;
        if(ruleBuilder.GetBuilderID()%2){
            builder = new FirstMapBuilder();
        }
        else{
            builder = new SecondMapBuilder();
        }
        auto director = MapDirector(builder);
        director.ConstructMap();
        Field* field = builder->ReturnField();
        delete builder;

        //create gamer
        Hero* gamer = new Hero();
        field->GetCells()[Size-1][Size-2].SetObject(gamer);
        //create enemy
        Unit** evil = CreateEvil(field->GetCells(), ruleEnemy.GetValue());
        //create things
        Thing** thing = CreateThing(field->GetCells(), ruleThing.GetValue());

        //choose logger
        std::cout << "Выберите тип логгера" << std::endl;
        int type;
        LoggerImplication* base;
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
        Logger *logger = Logger::GetInstance(gamer, base);
        logger->Update();

        Move::Movement(field, gamer, evil, thing, ruleEnemy.GetValue(), ruleThing.GetValue(), logger);

        delete field;
        for(int i = 0; i < ruleEnemy.GetValue(); i++){
            delete evil[i];
        }
        delete [] evil;
        for(int i = 0; i < ruleThing.GetValue(); i++){
            delete thing[i];
        }
        delete [] thing;
        delete gamer;
        delete logger;
    };
    Unit** CreateEvil(Cell** cell, int EVIL){
        Unit** evil = new Unit*[EVIL];
        auto* eyeFactory = new EyeFactory;
        auto* entFactory = new EntFactory;
        auto* spiderFactory = new SpiderFactory;
        int direction;
        int x = 0, y = 0;
        srand(time(NULL));
        for(int i = 0; i < EVIL; i++){
            direction = rand()%9;
            if(direction < 3){
                evil[i] = eyeFactory->CreateUnit();
            }
            else if(direction < 6){
                evil[i] = entFactory->CreateUnit();
            }
            else if(direction < 9){
                evil[i] = spiderFactory->CreateUnit();
            }
            while(!cell[x][y].IsMovable() || cell[x][y].GetObjectType() != empty) {
                x = rand() % (Size - 2) + 1;
                y = rand() % (Size - 2) + 1;
            }
            evil[i]->SetCoord(x, y);
            cell[x][y].SetObject(evil[i]);
        }
        delete eyeFactory;
        delete entFactory;
        delete spiderFactory;
        return evil;
    };

    Thing** CreateThing(Cell** cell, int THING){
        Thing** thing = new Thing*[THING];
        int direction;
        int x = 0, y = 0;
        for(int i = 0; i < THING; i++){
            direction = rand()%9;
            if(direction < 3){
                thing[i] = new Candy();
            }
            else if(direction < 6){
                thing[i] = new Axe();
            }
            else if(direction < 9){
                thing[i] = new Coin();
            }
            while(!cell[x][y].IsMovable() || cell[x][y].GetObjectType() != empty) {
                x = rand() % (Size - 2) + 1;
                y = rand() % (Size - 2) + 1;
            }
            thing[i]->SetCoord(x, y);
            cell[x][y].SetObject(thing[i]);
        }
        return thing;
    }
};

#endif //GAME_GAME_H
