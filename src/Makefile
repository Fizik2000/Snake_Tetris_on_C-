CFLAGS = -Wall -Wextra -Werror -std=c11 -g # -pedantic -fsanitize=address -fsanitize=undefined
CСFLAGS = -std=c++20 -Wall -Wextra -Werror
NCURSESFLAGS = -lncurses
CHECKFLAGS = -lcheck -lm -lpthread -lrt -lsubunit

LDFLAGS = -lgtest -lgtest_main -lpthread
COVARAGE_FLAFS = -Icontainers --coverage -O0 -g

TETRIS_CLI_SOURCE = brick_game/tetris/*.c gui/tetris/cli/*.c
TETRIS_CLI = gui/tetris/tetris_cli.c

.PHONY: dvi

# clean, dist.
all: install

games_folder:
	mkdir -p games

install: install_tetris_cli install_tetris_desktop install_snake_cli install_snake_desktop

install_tetris_library:
	gcc $(CFLAGS) -c brick_game/tetris/*.c $(NCURSESFLAGS)
	mkdir -p tetris_cli_build/tetris_library/
	cp *.o tetris_cli_build/tetris_library/
	cd tetris_cli_build/ && touch high_score.txt
	echo 0 > tetris_cli_build/high_score.txt
	rm -rf *.o
	ar cr tetris_cli_build/tetris_library.a tetris_cli_build/tetris_library/*.o

install_tetris_cli_interface:
	gcc $(CFLAGS) -c $(TETRIS_CLI_SOURCE) $(NCURSESFLAGS)
	mkdir -p tetris_cli_build/tetris_interface
	cp *.o tetris_cli_build/tetris_interface
	rm -rf *.o
	ar cr tetris_cli_build/tetris_interface.a tetris_cli_build/tetris_interface/*.o

install_tetris_cli: games_folder install_tetris_library install_tetris_cli_interface
	gcc $(CFLAGS) $(TETRIS_CLI) tetris_cli_build/tetris_interface.a -o tetris_cli_build/tetris_cli.o $(NCURSESFLAGS)
	mv tetris_cli_build games

play_tetris_cli:
	./games/tetris_cli_build/tetris_cli.o

install_snake_library:
	g++ $(CCFLAGS) -c brick_game/snake/*.cc $(NCURSESFLAGS)
	mkdir -p snake_cli_build/snake_library/
	cp *.o snake_cli_build/snake_library/
	cd snake_cli_build/ && touch high_score.txt
	echo 0 > snake_cli_build/high_score.txt
	rm -rf *.o
	ar cr snake_cli_build/snake_library.a snake_cli_build/snake_library/*.o

install_snake_cli_interface:
	g++ $(CCFLAGS) -c brick_game/snake/*.cc gui/snake/cli/*.cc $(NCURSESFLAGS)
	mkdir -p snake_cli_build/snake_interface
	cp *.o snake_cli_build/snake_interface
	rm -rf *.o
	ar cr snake_cli_build/snake_interface.a snake_cli_build/snake_interface/*.o

install_snake_cli: games_folder install_snake_library install_snake_cli_interface
	g++ $(CCFLAGS) gui/snake/snake_cli.cc snake_cli_build/snake_interface.a -o snake_cli_build/snake_cli.o $(NCURSESFLAGS)
	mv snake_cli_build games

play_snake_cli:
	./games/snake_cli_build/snake_cli.o

install_tetris_desktop: games_folder
	cd gui/tetris && \
	mkdir -p tetris_desktop_build && \
	cd tetris_desktop_build && \
	touch high_score.txt && \
	echo 0 > high_score.txt && \
	cmake .. && \
	cmake --build . && \
	echo "install tetris_desktop done"
	mv gui/tetris/tetris_desktop_build games

play_tetris_desktop:
	./games/tetris_desktop_build/tetris_desktop

install_snake_desktop: games_folder
	cd gui/snake && \
	mkdir -p snake_desktop_build && \
	cd snake_desktop_build && \
	touch high_score.txt && \
	echo 0 > high_score.txt && \
	cmake .. && \
	cmake --build . && \
	echo "install snake_desktop done"
	mv gui/snake/snake_desktop_build games

play_snake_desktop:
	./games/snake_desktop_build/snake_desktop

uninstall:
	rm -rf games

clean: uninstall
	rm -rf dvi/documantation.aux
	rm -rf dvi/documantation.log
	rm -rf dvi/documantation.pdf
	rm -rf snake-1-0.tar.gz
	rm -rf games
	rm -rf tetris_cli_build
	rm -rf snake_cli_build
	cd tests && rm -rf build 
	
dvi: dvi/documantation.tex
	xelatex -output-directory=dvi dvi/documantation.tex
	evince dvi/documantation.pdf

dist:
	mkdir -p for_dist
	cp Makefile  brick_game/snake/*.cc brick_game/snake/*.h gui/snake/cli/*.cc gui/snake/cli/*.h  gui/snake/snake_cli.cc for_dist
	tar -czvf snake-1-0.tar.gz for_dist
	rm -rf for_dist


clang:
	clang-format -i brick_game/tetris/*.h brick_game/tetris/*.c
	clang-format -i brick_game/snake/*.h brick_game/snake/*.cc
	clang-format -i gui/tetris/cli/*.h gui/tetris/cli/*.c gui/tetris/tetris_cli.c
	clang-format -i gui/tetris/desktop/*.h gui/tetris/desktop/*.cc gui/tetris/tetris_desktop.cc
	clang-format -i gui/snake/cli/*.h gui/snake/cli/*.cc gui/snake/snake_cli.cc
	clang-format -i gui/snake/desktop/*.h gui/snake/desktop/*.cc gui/snake/snake_desktop.cc
	clang-format -i tests/snake_tests.cc

tetris_test: install_tetris_library
	checkmk tests/tetris_tests.check > tests/tetris_tests.c
	clang-format -i tests/tetris_tests.c
	gcc $(CFLAGS) tests/tetris_tests.c tetris_cli_build/tetris_library.a -o tests/tetris_tests.o $(NCURSESFLAGS) $(CHECKFLAGS)
	./tests/tetris_tests.o
	cd tests && rm -rf tetris_tests.c
	cd tests && rm -rf *.o

tetris_report: install_tetris_library
	checkmk clean_mode=1 tests/tetris_tests.check > tests/tetris_tests.c
	clang-format -i tests/tetris_tests.c
	gcc $(CFLAGS) --coverage tests/tetris_tests.c brick_game/tetris/*.c -o tests/tetris_tests.o $(NCURSESFLAGS) $(CHECKFLAGS)
	./tests/tetris_tests.o
	cd tests && lcov -t "Test_report" -o test_report.info -c -d .
	cd tests && lcov --remove test_report.info 'tetris_tests.c' --output-file test_report.info
	cd tests && rm -rf report *.gcno *.gcda *.info
	cd tests && rm -rf tetris_tests.c tetris_tests.o

test:
	cd tests && mkdir -p build
	cd tests && cd build && cmake ..
	cd tests && cd build && make
	cd tests && ./build/test

gcov_report:
	cd tests && rm -rf build
	cd tests && mkdir build
	cd tests && cd build
	cd tests && cd build && cmake -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
	cd tests && cd build && make test
	cd tests && cd build && make coverage
