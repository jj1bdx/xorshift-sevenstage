# Makefile for xorshift-sevenstage
# Written by Kenji Rikitake
# License: CC0 / public domain

CC = clang
CFLAGS = -O0 -g -Wall

SOURCES = xorshift-sevenstage.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = xorshift-sevenstage

all: $(OBJECTS) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *~
