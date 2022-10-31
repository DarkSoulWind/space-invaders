cmake_minimum_required(VERSION 3.12)

set(CXX_STANDARD C++17)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_SOURCE_DIR src)
# file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR} *.cpp)
set(SOURCES src/Enemy.cpp src/Entity.cpp src/Laser.cpp src/main.cpp src/Math.cpp src/Player.cpp src/RenderWindow.cpp src/State.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
project(SpaceInvaders LANGUAGES CXX VERSION 1.0)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)
include_directories(lib/imgui)
include_directories(lib/imgui/backends)

add_executable(SpaceInvaders ${SOURCES} lib/imgui/backends/imgui_impl_sdl.cpp lib/imgui/backends/imgui_impl_sdlrenderer.cpp lib/imgui/imgui_demo.cpp lib/imgui/imgui_draw.cpp lib/imgui/imgui_tables.cpp lib/imgui/imgui_widgets.cpp lib/imgui/imgui.cpp)

target_link_libraries(SpaceInvaders ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# needed for imgui
target_link_libraries(SpaceInvaders "-framework OpenGl")