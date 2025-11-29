cmake_minimum_required(VERSION 3.16)
project(test)

option(ENABLE_COVERAGE "Enable code coverage" ON)

add_compile_options(--coverage)
add_link_options(--coverage)

# Подключаем модуль GoogleTest
include(GoogleTest)

# Способ 1: Используем системную установку
find_package(GTest REQUIRED)

# Способ 2: Или используем FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(SOURCES
  ../brick_game/snake/init_field_back.cc
  ../brick_game/snake/init_head_and_tail.cc
  ../brick_game/snake/set_apple_in_field_back.cc
  ../brick_game/snake/set_apple_rand.cc
  ../brick_game/snake/snake_move_hangling_back.cc
)

add_executable(test snake_tests.cc ${SOURCES})


target_link_libraries(test PRIVATE
  GTest::gtest_main  # Основная цель
  GTest::gmock       # Если нужен Google Mock
)

# Инициализация тестов GTest
gtest_discover_tests(test)


# Настройка покрытия кода
add_custom_target(coverage
COMMAND ./test
COMMAND lcov --ignore-errors mismatch --capture --directory . --demangle-cpp -c -d . --output-file filtered.info
COMMAND lcov --ignore-errors unused
             --remove filtered.info
        "*/tests/*"
        "*/usr/include/*"
        "*/googletest/*"
        "*/_deps/googletest-src/*"
        "*/gtest/*"
        "*/gmock/*"
        "*/external/*"
        "*/build/*"
          --ignore-errors mismatch
          --output-file coverage-filtered.info

# Шаг 3: Генерация отчета
COMMAND genhtml coverage-filtered.info --output-directory coverage-report
COMMAND open coverage-report/index.html
COMMENT "Отчет о покрытии готов"
EXCLUDE_FROM_ALL
)

