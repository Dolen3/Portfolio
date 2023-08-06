CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
LDFLAGS = -lsfml-system

SRCS = main.cpp EDistance.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = EDistance

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

lint:
	cpplint *.cpp *.h

clean:
	rm -f $(OBJS) $(TARGET)
