#include "ViewField.h"


ViewField::ViewField(Field* field) {
    m_field = field;
}

void ViewField::rendering() {
    for (int y = 0; y < m_field->getHeight()+2; y++) {
        for (int x = 0; x < m_field->getWidth()+2; x++) {

            switch (m_field->getCell(x,y)->getTypeCell()) {
                case TNormalCell:
                    std::cout << "  ";
                    break;
                case TEndCell:
                    std::cout << "\x1b[41m  \x1b[0m";
                    break;
                case TStartCell:
                    std::cout << "\x1b[42m  \x1b[0m";
                    break;
                case TImpassableCell:
                    std::cout << "\x1b[47m  \x1b[0m";
                    break;
            }
        }
        std::cout << std::endl;
    }
}