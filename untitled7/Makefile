.PHONY: all clean
CFLAGS=-std=c18 -pedantic -Wall -Werror
CC=gcc
all: untiled7

main.o: main.c
			gcc -c -o main.o main.c

image.o: image.c
			$(CC) -c $(CFLAGS) $< -o $@

Check.o: Check.c
			$(CC) -c $(CFLAGS) $< -o $@

Open_file.o: Open_file.c
			$(CC) -c $(CFLAGS) $< -o $@

Read_Write_file.o: Read_Write_file.c
			$(CC) -c $(CFLAGS) $< -o $@

Save_file.o: Save_file.c
			$(CC) -c $(CFLAGS) $< -o $@

Speaks.o: Speaks.c
			$(CC) -c $(CFLAGS) $< -o $@

util.o: util.c
			$(CC) -c $(CFLAGS) $< -o $@

untiled7: main.o image.o Open_file.o Check.o Read_Write_file.o Save_file.o Speaks.o util.o
			$(CC) -o untiled7 $^

clean: rm -rf untiled7 *.o