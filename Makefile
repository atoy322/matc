.PHONY: clean


ifeq  ($(OS),)

main: main.o matrix.o display.o
	gcc main.o matrix.o display.o -o main

main.o: main.c
	gcc -c main.c

matrix.o: matrix.h matrix.c
	gcc -c matrix.c

display.o: display.h display.c
	gcc -c display.c

clean:
	rm *.o main

else ifeq ($(OS),Windows_NT)

main.exe: main.o matrix.o display.o
	gcc main.o matrix.o display.o -o main.exe

main.o: main.c
	gcc -c main.c

matrix.o: matrix.h matrix.c
	gcc -c matrix.c

display.o: display.h display.c
	gcc -c display.c

clean:
	-rm *.o main.exe

endif
