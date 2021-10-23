cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Game map/MapBuilder/Field/Cell/Cell.h map/MapBuilder/Field/Cell/Cell.cpp map/MapBuilder/Field/Field.h map/MapBuilder/Field/Field.cpp map/MapBuilder/MapBuilder.h map/MapBuilder/MapBuilder.cpp map/MapBuilder/MapDirector.h map/MapBuilder/MapDirector.cpp map/MapBuilder/FirstMapBuilder.h map/MapBuilder/FirstMapBuilder.cpp Game.cpp Game.h main.cpp map/MapBuilder/Field/Cell/Object.h map/MapBuilder/Field/Cell/Object.cpp map/Units/Unit.h map/Units/Unit.cpp map/Units/Eye.h map/Factory/EyeFactory.h map/Things/Thing.h map/Things/Thing.cpp map/Factory/EyeFactory.cpp map/Factory/ObjectFactory.h map/Units/Eye.cpp map/Units/Spider.h map/Units/Spider.cpp map/Units/Ent.cpp map/Units/Ent.h map/Factory/ObjectFactory.cpp map/Factory/EntFactory.h map/Factory/EntFactory.cpp map/Factory/SpiderFactory.h map/Factory/SpiderFactory.cpp map/Units/Hero.h map/Units/Hero.cpp map/Factory/HeroFactory.h map/Factory/HeroFactory.cpp map/Things/Candy.h map/Things/Candy.cpp map/Things/Axe.h map/Things/Axe.cpp map/Things/Coin.cpp map/Things/Coin.h)

target_link_libraries(Game sfml-graphics sfml-audio)