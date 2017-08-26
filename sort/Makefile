CXX = g++
CXXFLAGS = -Wall -g -std=c++11

.PHONY: clean

TARGET = mergesort

all: $(TARGET).app

utils.o: utils.h utils.cpp
	$(CXX) $(CXXFLAGS) -c -o utils.o utils.cpp

mergesort.o: utils.h $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -c -o $(TARGET).o $(TARGET).cpp

$(TARGET).app: $(TARGET).o utils.o
	$(CXX) $(CXXFLAG) -o $@ $^

clean:
	rm *.o $(TARGET).app
