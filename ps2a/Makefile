CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: sokoban

sokoban: Sokoban.o main.o
	$(CXX) $(CXXFLAGS) -o sokoban Sokoban.o main.o $(SFMLFLAGS)

Sokoban.o: Sokoban.cpp Sokoban.hpp
	$(CXX) $(CXXFLAGS) -c Sokoban.cpp

main.o: main.cpp Sokoban.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

lint: 
	cpplint *.hpp *.cpp

clean:
	rm -f *.o sokoban



