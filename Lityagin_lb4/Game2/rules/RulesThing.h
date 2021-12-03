#ifndef GAME_RULESTHING_H
#define GAME_RULESTHING_H

template <int T>
class RulesThing{
private:
    int value = T;
public:
    int GetValue(){
        if(value < 0){
            value = -value;
        }
        return value;
    }
    void SetValue(int value){
        this->value = value;
    }
    Thing** GetThing(){
        Thing** thing = new Thing*[GetValue()];
        int direction;
        int x = 0, y = 0;
        for(int i = 0; i < GetValue(); i++){
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
        }
        return thing;
    }
};

#endif //GAME_RULESTHING_H
