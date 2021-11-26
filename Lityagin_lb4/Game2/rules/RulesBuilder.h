#ifndef GAME_RULESBUILDER_H
#define GAME_RULESBUILDER_H

template <class T>
class RulesBuilder{
private:
    int builderID;
public:
    RulesBuilder(T value){
        builderID = (int)value;
    }
    int GetBuilderID(){
        return builderID;
    }
};

#endif //GAME_RULESBUILDER_H
