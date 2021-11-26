#ifndef GAME_RULESTHING_H
#define GAME_RULESTHING_H

template <class T>
class RulesThing{
private:
    int value;
public:
    RulesThing(T value){
        this->value = (int)value;
    }
    int GetValue(){
        return value;
    }
    void SetValue(int value){
        this->value = value;
    }
};

#endif //GAME_RULESTHING_H
