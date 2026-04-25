CXXFLAGS := -std=c++20 -Wall -Werror

main: main.cpp sudokuväli.h
	g++ -o main main.cpp sudokuväli.h
	./main

clean:
	rm -f main