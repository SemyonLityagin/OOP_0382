#include "NormalCell.h"

NormalCell::NormalCell(bool passable) {
    m_passable = passable;
}

void NormalCell::putItem(unq_p<IItem> item) {
    if (m_passable){
        if (m_item == nullptr){
            m_item = std::move(item);
        } else {throw "Cell already have item";}
    }else {throw "Cell is not passable";}
}

IItem* NormalCell::topItem(){
    return m_item.get();
}

unq_p<IItem> NormalCell::popItem(){
    return std::move(m_item);
}


void NormalCell::standOnCreature(unq_p<ICreature> creature){
    if (m_passable){
        if (m_creature == nullptr){
            m_creature = std::move(creature);
        } else {throw "Cell already have creature";}
    }else {throw "Cell is not passable";}
}

ICreature* NormalCell::getCreature() {
    return m_creature.get();
}

unq_p<ICreature> NormalCell::leaveCreature() {
    return std::move(m_creature);
}

TypeCell NormalCell::getTypeCell() const {
    if (m_passable) {
        return TNormalCell;
    } else {
        return TImpassableCell;
    }
}

unq_p<ICell> NormalCell::clone() {
    return _universal_clone<NormalCell>();
}




