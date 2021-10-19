#ifndef CONSOLE_GAME_ICELL_H
#define CONSOLE_GAME_ICELL_H

#include "IItem.h"
#include "ICreature.h"
#include "unq_p.h"

enum TypeCell {
    TNormalCell,
    TStartCell,
    TEndCell,
    TImpassableCell
};

class ICell {
public:
    //Возможность положить/просм/взять предмет (зелье, мечь, броня)
    virtual void putItem(unq_p<IItem> item) = 0;
    virtual IItem* topItem() = 0;
    virtual unq_p<IItem> popItem() = 0;

    //возможность какого-то существа(nps,enemies, character) наступить на/уйти с клетки
    virtual void standOnCreature(unq_p<ICreature> creature) = 0;
    virtual ICreature* getCreature() = 0;
    virtual unq_p<ICreature> leaveCreature() = 0;

    //фун. возвращает тип обьекта через enum TypeCell
    virtual TypeCell getTypeCell() const = 0 ;

    //возфращает указатель на копию обьекта в дин. памяти
    virtual unq_p<ICell> clone() = 0;

    //виртуальный деструктор , чтобы коректно удалялись наследники
    virtual ~ICell() = default;
};

#endif //CONSOLE_GAME_ICELL_H
