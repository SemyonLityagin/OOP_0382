#ifndef GAME_RULESBUILDER_H
#define GAME_RULESBUILDER_H

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
