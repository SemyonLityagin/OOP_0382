cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Game main.cpp Floor/Cell/Cell.cpp Floor/Cell/Cell.h Floor/Floor.cpp Floor/Floor.h Floor/FloorBuilder.h Floor/FloorBuilderTree.cpp Floor/FloorBuilderTree.h Floor/FloorDirector.cpp Floor/FloorDirector.h GameStart.cpp GameStart.h)

target_link_libraries(Game sfml-graphics sfml-audio)