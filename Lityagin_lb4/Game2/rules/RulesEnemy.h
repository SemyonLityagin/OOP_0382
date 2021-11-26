#ifndef GAME_RULESENEMY_H
#define GAME_RULESENEMY_H

template <class T>
class RulesEnemy{
private:
    int value;
public:
    RulesEnemy(T value){
        this->value = (int)value;
    }
    int GetValue(){
        return value;
    }
    void SetValue(int value){
        this->value = value;
    }
};

#endif //GAME_RULESENEMY_H
