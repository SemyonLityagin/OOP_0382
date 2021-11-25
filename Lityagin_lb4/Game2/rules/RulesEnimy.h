#ifndef GAME_RULESENIMY_H
#define GAME_RULESENIMY_H

template <class T>
class RulesEnimy{
private:
    int value;
public:
    RulesEnimy(T value){
        this->value = (int)value;
    }
    int GetValue(){
        return value;
    }
    void SetValue(int value){
        this->value = value;
    }
};

#endif //GAME_RULESENIMY_H
