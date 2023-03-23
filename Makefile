build_windows:
	gcc -c *.c
	gcc *.o -o test.exe

build_linux:
	gcc -c *.c
	gcc *.o -o test

archive: lib/include
	gcc -c array.c display.c
	ar r lib/libmatc.a array.o display.o
	cp array.h lib/include
	cp display.h lib/include

lib:
	mkdir lib

lib/include: lib
	mkdir "lib/include"

clean:
	rm -rf lib
	rm *.o
