#
#Simple Makefile for Demo
#
SOURCE := $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

CC=g++

CXXFLAGS = -Wall -std=c++14

TARGET = murmurHash

.PHONY : all clean rebuild

all:$(TARGET)

rebuild: clean all

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) 
clean:
	rm -rf *.o *.gch $(TARGET)
