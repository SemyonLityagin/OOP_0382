cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Game map/MapBuilder/Field/Cell/Cell.h map/MapBuilder/Field/Cell/Cell.cpp map/MapBuilder/Field/Field.h map/MapBuilder/Field/Field.cpp map/MapBuilder/MapBuilder.h map/MapBuilder/MapBuilder.cpp map/MapBuilder/MapDirector.h map/MapBuilder/MapDirector.cpp map/MapBuilder/FirstMapBuilder.h map/MapBuilder/FirstMapBuilder.cpp Game.cpp Game.h main.cpp map/MapBuilder/Field/Cell/IntObj.h map/MapBuilder/Field/Cell/IntObj.cpp)

target_link_libraries(Game sfml-graphics sfml-audio)