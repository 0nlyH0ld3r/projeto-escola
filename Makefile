CC      := gcc
CFLAGS  := -Iheaders -Wall -Wextra
SRCS    := $(wildcard src/*.c)
OBJS    := $(SRCS:src/%.c=build/%.o)
TARGET  := build/app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean
