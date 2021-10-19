cmake_minimum_required(VERSION 3.20)
project(Console_Game)

set(CMAKE_CXX_STANDARD 23)


add_executable(Console_Game main.cpp
        Classes/Field/Field.cpp
        Classes/Field/Field.h
        Classes/BuilderField/BuilderField.cpp
        Classes/BuilderField/BuilderField.h
        Classes/Cells/ICell.h
        Classes/Cells/NormalCell/NormalCell.cpp Classes/Cells/NormalCell/NormalCell.h
        Classes/СellСontents/Items/IItem.h
        Classes/СellСontents/Сreatures/ICreature.h
        Classes/Cells/StartCell/StartCell.cpp Classes/Cells/StartCell/StartCell.h
        Classes/Cells/EndCell/EndCell.cpp Classes/Cells/EndCell/EndCell.h
        unq_p.h My_Exception.h
        Classes/ViewField/ViewField.cpp Classes/ViewField/ViewField.h)

target_include_directories(
        Console_Game                           # Цель, при сборке которой учитываются указанные пути к заголовочным файлам
        PUBLIC                                # область видимости (PRIVATE, INTERFACE или PUBLIC)
        Classes/Field/
        Classes/BuilderField/
        Classes/Cells/NormalCell
        Classes/Cells/
        Classes/СellСontents/Items
        Classes/СellСontents/Сreatures/
        Classes/Cells/StartCell/
        Classes/Cells/EndCell/
        ./
        Classes/ViewField/
)