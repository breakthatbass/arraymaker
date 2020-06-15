CC=gcc
CFLAGS=-lm -std=c99 -pedantic
PREFIX=/usr/local
ifndef NAME
    NAME=arraymaker
endif

all: arraymaker

arraymaker: main.c count_lines.c create_file.c load_array.c algorithms/shellsort.c algorithms/bubblesort.c
	$(CC) -o $(NAME) main.c count_lines.c create_file.c load_array.c algorithms/shellsort.c algorithms/bubblesort.c $(CFLAGS)

install: arraymaker
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/$(NAME)

clean:
	rm $(NAME)
