cmake_minimum_required(VERSION 3.16)


project(snake_desktop)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(BACKEND
    ../../brick_game/snake/backend.h
    ../../brick_game/snake/init_field_back.cc
    ../../brick_game/snake/set_apple_in_field_back.cc
    ../../brick_game/snake/set_apple_rand.cc
    ../../brick_game/snake/snake_move_hangling_back.cc
    ../../brick_game/snake/init_head_and_tail.cc
)

add_library(snake_logic STATIC ${BACKEND})

target_include_directories(snake_logic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../brick_game/snake
)

set(FRONTEND
    snake_desktop.cc
    desktop/frontend.h
    desktop/gameFieldWidget.cc
    desktop/menuWidget.cc
    )


add_executable(${PROJECT_NAME} ${FRONTEND})


target_link_libraries(${PROJECT_NAME} PRIVATE
    snake_logic
    Qt6::Widgets
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../brick_game/snake
)

include_directories(${Qt6Widgets_INCLUDE_DIRS})

