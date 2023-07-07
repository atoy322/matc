.PHONY: clean static


ifeq  ($(OS),)

main: main.o matrix.o display.o
	gcc main.o matrix.o display.o -o main

main.o: main.c
	gcc -c main.c

matrix.o: matrix.h matrix.c
	gcc -c matrix.c

display.o: display.h display.c
	gcc -c display.c

static: matrix.o display.o
	-mkdir libmatc
	-mkdir libmatc/lib
	-mkdir libmatc/include
	cp *.h libmatc/include
	ar r libmatc/lib/libmatc.a matrix.o display.o

clean:
	-rm *.o main
	-rm -r libmatc

else ifeq ($(OS),Windows_NT)

main.exe: main.o matrix.o display.o
	gcc main.o matrix.o display.o -o main.exe

main.o: main.c
	gcc -c main.c

matrix.o: matrix.h matrix.c
	gcc -c matrix.c

display.o: display.h display.c
	gcc -c display.c

static: matrix.o display.o
	-mkdir libmatc
	-mkdir libmatc/lib
	-mkdir libmatc/include
	cp *.h libmatc/include
	ar r libmatc/lib/libmatc.a matrix.o display.o

clean:
	-rm *.o main.exe

endif
