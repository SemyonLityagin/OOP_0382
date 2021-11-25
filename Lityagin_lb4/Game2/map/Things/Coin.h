#include "Thing.h"

class Coin: public Thing{
private:
    int value;
    ObjectType type;
    bool is_available;
    int coord[2] = {-1,-1};
public:
    Coin(int value = 1, ObjectType type = coin, bool is_available = true);
    int GetData() override;
    void SetCoord(int x, int y) override;
    int* GetCoord() override;
    ObjectType GetType() override;
    bool IsAvailable() override;
    std::string GetLog() override;

};