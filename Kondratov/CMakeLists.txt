cmake_minimum_required(VERSION 3.17)
project(SFMLProj)

set(CMAKE_CXX_STANDARD 20)

add_executable(SFMLProj main.cpp game/field/Field.cpp game/field/Field.h game/cell/Cell.cpp game/cell/Cell.h game/Game.cpp game/Game.h game/field/FieldBuilder.cpp game/field/FieldBuilder.h game/field/PlainFieldBuilder.cpp game/field/PlainFieldBuilder.h game/field/FieldDirector.cpp game/field/FieldDirector.h game/objects/CellObject.cpp game/objects/CellObject.h game/player/Player.cpp game/player/Player.h game/objects/enemies/Enemy.cpp game/objects/enemies/Enemy.h game/objects/enemies/MudGolem.cpp game/objects/enemies/MudGolem.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Applications/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Applications/SFML/include)
target_link_libraries(SFMLProj sfml-system sfml-window sfml-graphics sfml-audio)
