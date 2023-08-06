CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: TextWriter TestRand

TextWriter: TextWriter.o RandWriter.o
	$(CXX) $(CXXFLAGS) -o TextWriter TextWriter.o RandWriter.o

TestRand: test.o RandWriter.o
	$(CXX) $(CXXFLAGS) -o TestRand test.o RandWriter.o

TextWriter.o: TextWriter.cpp RandWriter.h
	$(CXX) $(CXXFLAGS) -c TextWriter.cpp

test.o: test.cpp RandWriter.h
	$(CXX) $(CXXFLAGS) -c test.cpp

RandWriter.o: RandWriter.cpp RandWriter.h
	$(CXX) $(CXXFLAGS) -c RandWriter.cpp

lint:
	cpplint *.cpp *.h

clean:
	rm -f TextWriter TestRand *.o

