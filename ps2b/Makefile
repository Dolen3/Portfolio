CC = g++
FLAGS = -Wall -Werror -pedantic -std=c++17
DEPS = Sokoban.h
OBJS = Sokoban.o
PROGRAM = Sokoban

.PHONY: all clean lint

all: $(PROGRAM)

$(PROGRAM): main.o $(OBJS)
	$(CC) $(FLAGS) -o $(PROGRAM) $^ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp $(DEPS)
	$(CC) $(FLAGS) -c $<

clean:
	rm *.o $(PROGRAM)

lint:
	cpplint *.cpp *.h