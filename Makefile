CC=g++
LD=g++

TARGET=bin/haiku

CFLAGS=-I./include -g -Wall -lm -o $(TARGET)
LDFLAGS=-lm

SRCS=haiku.cpp poem.cpp poem_generator.cpp word.cpp

OBJS=$(addsuffix .o, $(SRCS))
MOBJS=$(addprefix bin/, $(OBJS))

$(TARGET): $(OBJS)
	$(LD) $(MOBJS) -o $(TARGET) $(LDFLAGS)

%.cpp.o: src/%.cpp
	$(CC) -c $(CFLAGS) $< -o bin/$@

clean:
	rm -f bin/* $(TARGET)
