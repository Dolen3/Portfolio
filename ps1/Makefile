CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
DEP = FibLFSR.h
OBJS = FibLFSR.o PhotoMagic.o

all:ps1b

ps1b: $(OBJS)
	$(CC) -o ps1b $(OBJS) $(LFLAGS)
$(objects): %.o: %.cpp $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@ $(LFLAGS)

cleanall : cleanobj
	rm ps1b

cleanobj :
	rm *.o