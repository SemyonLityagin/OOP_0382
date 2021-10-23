#include "Thing.h"

class Coin: public Thing{
private:
    int value;
    int coord[2] = {-1,-1};
public:
    Coin(int value = 1);
    void Interaction(Hero* obj) override;
};