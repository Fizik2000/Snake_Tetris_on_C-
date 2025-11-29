cmake_minimum_required(VERSION 3.16)


project(tetris_desktop)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(BACKEND
    desktop/backend/backend.h
    desktop/backend/erase_figure_in_field_back.cc
    desktop/backend/is_four_row_full.cc
    desktop/backend/is_neighbors_below.cc
    desktop/backend/is_neighbors_left.cc
    desktop/backend/is_neighbors_right.cc
    desktop/backend/rotate.cc
    desktop/backend/set_field_back_after_full_row.cc
    desktop/backend/set_figure_in_field_back.cc
    desktop/backend/set_figure.cc
)

add_library(logic STATIC ${BACKEND})

target_include_directories(logic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/desktop/backend
)

set(FRONTEND
    desktop/frontend.h
    desktop/gameFieldWidget.cc
    tetris_desktop.cc
    desktop/menu.cc
    desktop/set_figure_in_field.cc
    desktop/init_styles.cc
    desktop/erase_figure_in_field.cc
    desktop/set_field_after_full_row.cc
    )


add_executable(${PROJECT_NAME} ${FRONTEND})


target_link_libraries(${PROJECT_NAME} PRIVATE
    logic
    Qt6::Widgets
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/desktop/backend
)

include_directories(${Qt6Widgets_INCLUDE_DIRS})

