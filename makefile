#Para escrever comentários ##
############################# Makefile ##########################
CC = gcc
CFLAGS = -g3 -Wall

all:
	$(CC) $(CFLAGS) -o tp1 *.c

clean:
	rm tp3
