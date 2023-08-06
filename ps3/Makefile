
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: ptree

ptree: main.o PTree.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.cpp PTree.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

PTree.o: PTree.cpp PTree.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o ptree

.PHONY: all clean
