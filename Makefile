CC = gcc
CFLAGS = -Wall -Wextra -pedantic

CFILES = main.c myallocator.c
OFILES = main.o myallocator.o

BINARY = main

.PHONY: all
all: $(BINARY)

$(BINARY): $(OFILES)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf $(BINARY) $(OFILES)

