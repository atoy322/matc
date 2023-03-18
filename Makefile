build:
	gcc -c *.c
	gcc *.o -o test

archive:
	gcc -c array.c display.c
	ar r lib/libmatc.a array.o display.o
	cp array.h lib/include
	cp display.h lib/include
