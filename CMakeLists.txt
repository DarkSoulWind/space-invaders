cmake_minimum_required(VERSION 3.12)

project(SpaceInvaders)
set(CXX_STANDARD C++20)
set(SOURCES src/main.cpp src/Entity.cpp src/Math.cpp src/RenderWindow.cpp src/Player.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(./include)

add_executable(SpaceInvaders ${SOURCES})
target_link_libraries(SpaceInvaders ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})