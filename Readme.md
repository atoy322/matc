# Matrix implementation written in C

## About this
A tiny, low level C program which treats matrix.

**Warning**
This project is in development.

## Features
Functions supported are:
- adding two arrays
- displaying array data
- calculating matrix product

## How to build a static or shared library
```shell
git clone https://github.com/atoy322/matc.git
cd matc
make static
# make shared
```

## How to use
```C:main.c
#include <matc.h>

int main() {
    // Allocate memory for array. (column=10, row=10)
    // "I" refers to int: ("F"=float, "D"=double, "L"=long)
    Iarray_t A = matcInitIArray(10, 10);
    Iarray_t B = matcInitIArray(10, 10);
    Iarray_t Dest = matcInitIArray(10, 10);

    // Set a value in the way follow.
    A.array[0][0] = 1;
    B.array[9][9] = 1;

    // All arrays must have same shape and type.
    // Dest = A + B
    matcAddIArray(A, B, Dest);

    // Calculate matrix product.
    matcDotIArray(A, B, Dest);

    // Display array data.
    matcDisplayIArray(Dest);

    // Free memory allocated by init function.
    matcDeinitIArray(A);
    matcDeinitIArray(B);
    matcDeinitIArray(Dest);

    return 0;
}
```

and then
```shell
gcc -c {your c program}.c -I./libmatc/include
gcc {your c program}.o -o main.exe -L./libmatc/lib/libmatc.a -lmatc 
```
