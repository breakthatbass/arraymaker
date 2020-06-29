CC=gcc
CFLAGS=-lm -std=c99 -pedantic
PREFIX=/usr/local
ifndef NAME
    NAME=arraymaker
endif

all: arraymaker

arraymaker: src/main.c src/count_lines.c src/create_file.c src/load_array.c src/helpers.c algorithms/shellsort.c algorithms/bubblesort.c algorithms/gnomesort.c algorithms/insertionsort.c
	$(CC) -o $(NAME) src/main.c src/count_lines.c src/create_file.c src/load_array.c src/helpers.c algorithms/shellsort.c algorithms/bubblesort.c algorithms/gnomesort.c algorithms/insertionsort.c $(CFLAGS)

install: arraymaker
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/$(NAME)

clean:
	rm $(NAME)
