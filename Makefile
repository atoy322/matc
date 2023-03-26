static: libmatc/include libmatc/lib
	gcc -c array.c display.c
	ar r libmatc/lib/libmatc.a array.o display.o
	cp array.h libmatc/include
	cp display.h libmatc/include
	cp matc.h libmatc/include

shared: libmatc/include libmatc/lib
	gcc -c array.c display.c
	gcc array.o display.o -shared -o libmatc/lib/libmatc.so
	cp array.h libmatc/include
	cp display.h libmatc/include
	cp matc.h libmatc/include

build_windows:
	gcc -c *.c
	gcc *.o -o test.exe

build_linux:
	gcc -c *.c
	gcc *.o -o test

libmatc:
	mkdir libmatc

libmatc/include: libmatc
	mkdir "libmatc/include"

libmatc/lib: libmatc
	mkdir "libmatc/lib"

clean:
	rm -rf libmatc
	rm *.o
