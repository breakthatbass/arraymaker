CC=gcc
CFLAGS=-g -lm -std=c99 -pedantic
PREFIX=/usr/local
SRC_FILES=$(wildcard src/*.c algorithms/*.c)

ifndef NAME
    NAME=arraymaker
endif

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) -o $(NAME) $(SRC_FILES) $(CFLAGS)

install: $(NAME)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/$(NAME)

clean:
	rm $(NAME)
