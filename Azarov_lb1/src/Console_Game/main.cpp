#include <iostream>
#include <BuilderField.h>
#include "Field.h"
#include "ViewField.h"
#include "unq_p.h"
#include "My_Exception.h"

int main() {
    BuilderField builder;
    unq_p<Field> field1,f2;

    //строительство
    builder.createEmptyField(20,10); //диапазон x = [1,20], y = [1,30]
    builder.buildRandomImpassableCells(20);
    builder.buildStartCell();
    builder.buildEndCell();
    builder.buildEndCell();

    field1 = builder.getField();

    //строительство
    /*builder.createEmptyField(20,10); //диапазон x = [1,20], y = [1,30]
    builder.buildRandomImpassableCells(20);
    builder.buildStartCell();
    builder.buildEndCell();
    builder.buildEndCell();

    f2 = builder.getField();

    *field1 = *f2;*/

    //отображение
    ViewField  view(field1.get());
    //ViewField  view2(f2.get());
    view.rendering();
    //view2.rendering();
    return 0;
}
