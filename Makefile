.PHONY: clean static shared


ifeq  ($(OS),)

main: main.o matrix.o display.o
	gcc main.o matrix.o display.o -o main -g

main.o: main.c
	gcc -c main.c -g

matrix.o: matrix.h matrix.c
	gcc -c matrix.c -g

display.o: display.h display.c
	gcc -c display.c -g

static: matrix.o display.o
	-mkdir libmatc
	-mkdir libmatc/lib
	-mkdir libmatc/include
	cp *.h libmatc/include
	ar r libmatc/lib/libmatc.a matrix.o display.o

shared: matrix.o display.o
	-mkdir libmatc
	-mkdir libmatc/lib
	-mkdir libmatc/include
	cp *.h libmatc/include
	gcc matrix.o display.o -o libmatc/lib/libmatc.so -shared

clean:
	-rm *.o main
	-rm -r libmatc

else ifeq ($(OS),Windows_NT)

main.exe: main.o matrix.o display.o
	gcc main.o matrix.o display.o -o main.exe -g

main.o: main.c
	gcc -c main.c -g

matrix.o: matrix.h matrix.c
	gcc -c matrix.c -g

display.o: display.h display.c
	gcc -c display.c -g

static: matrix.o display.o
	-mkdir libmatc
	-mkdir libmatc\lib
	-mkdir libmatc\include
	cp *.h libmatc\include
	ar r libmatc/lib/libmatc.a matrix.o display.o

shared: matrix.o display.o
	-mkdir libmatc
	-mkdir libmatc\lib
	-mkdir libmatc\include
	cp *.h libmatc\include
	gcc matrix.o display.o -o libmatc/lib/libmatc.so -shared

clean:
	-rm *.o main.exe
	-rm -r libmatc

endif
