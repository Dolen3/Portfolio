CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Checkers.cpp
OBJS = $(SRCS:.cpp=.o)

all: checkers

checkers: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system -o checkers

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Checkers.o: Checkers.cpp Checkers.h
	$(CXX) $(CXXFLAGS) -c Checkers.cpp

lint:
	cpplint *.cpp *.h

clean:
	rm -f checkers $(OBJS)
