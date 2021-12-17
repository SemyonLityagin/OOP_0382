#ifndef GAME_RULESBUILDER_H
#define GAME_RULESBUILDER_H

#include "../map/MapBuilder/MapBuilder.h"
#include "../map/MapBuilder/MapDirector.h"
#include "../map/MapBuilder/FirstMapBuilder.h"
#include "../map/MapBuilder/SecondMapBuilder.h"

template <int T>
class RulesBuilder{
private:
    int builderID = T;
public:
    Field* GetFieldFromBuilder(){
        MapBuilder* builder;
        if(builderID%2){
            builder = new FirstMapBuilder();
        }
        else{
            builder = new SecondMapBuilder();
        }
        auto director = MapDirector(builder);
        director.ConstructMap();
        Field* field = builder->ReturnField();
        delete builder;
        return field;
    }
};

#endif //GAME_RULESBUILDER_H
