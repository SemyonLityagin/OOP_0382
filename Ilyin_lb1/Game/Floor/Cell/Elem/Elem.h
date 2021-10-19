#ifndef GAME_ELEM_H
#define GAME_ELEM_H

enum class Type_of_elem : unsigned short {
    EMPTY,
    FULL,
    PLAYER,
    ENEMY,
    ITEM,
    PLACE_OF_POWER
};

class Elem {
/*private:
    Type_of_elem _type;
    int step, _hp, _chi, _damage;*/

public:
    Elem(Elem&&) = default;
    virtual Elem& operator=(const Elem& other) = 0;
    virtual Elem& operator=(Elem&& other) = 0;
    virtual void setTexture(const std::string& filename) = 0;
    virtual sf::Sprite* getSprite() = 0;
    virtual Type_of_elem getType() = 0;
    virtual float getDamage() = 0;
    virtual void setDamage(float damage) = 0;
    virtual int getStep() = 0;
    virtual void setStep(int step) = 0;


};


#endif //GAME_ELEM_H
