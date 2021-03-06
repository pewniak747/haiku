CC=g++
LD=g++

TARGET=bin/haiku

CFLAGS=-I./include -L./lib -g -Wall -lm -lpthread -lxerces-c -o $(TARGET)
LDFLAGS=-lm -lxerces-c

SRCS=haiku.cpp poem.cpp poem_generator.cpp word.cpp poem_template.cpp word_template.cpp line_template.cpp line.cpp renderer.cpp

OBJS=$(addsuffix .o, $(SRCS))
MOBJS=$(addprefix bin/, $(OBJS))

$(TARGET): $(OBJS)
	$(LD) $(MOBJS) -o $(TARGET) $(LDFLAGS)

%.cpp.o: src/%.cpp
	$(CC) -c $(CFLAGS) $< -o bin/$@

clean:
	rm -f bin/* $(TARGET)
