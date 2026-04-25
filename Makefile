CXXFLAGS := -std=c++20 -Wall -Werror
CXX := g++

main: main.cpp sudokuväli.h lahendaja.h
	$(CXX) $(CXXFLAGS) -o main main.cpp
	./main

clean:
	rm -f main