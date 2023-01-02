PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`
CC=gcc

gp: main.c
	$(CC) $(CFLAGS) -o sdlTemp main.c $(LIBS)
