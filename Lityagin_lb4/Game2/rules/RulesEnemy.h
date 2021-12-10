#ifndef GAME_RULESENEMY_H
#define GAME_RULESENEMY_H

template <int T>
class RulesEnemy{
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
    Unit** GetEnemy(){
        Unit** evil = new Unit*[GetValue()];
        auto* eyeFactory = new EyeFactory;
        auto* entFactory = new EntFactory;
        auto* spiderFactory = new SpiderFactory;
        int direction;
        srand(time(NULL));
        for(int i = 0; i < value; i++){
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
        }
        delete eyeFactory;
        delete entFactory;
        delete spiderFactory;
        return evil;
    }
};

#endif //GAME_RULESENEMY_H
