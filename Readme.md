# Matrix implementation written in C

## About this
A tiny, low level C program which treats matrix.

## Feature
Functions supported are:
- adding two arrays
- displaying array data
- calculating matrix product

## Build a static library
```bash
git clone https://github.com/atoy322/matc.git
cd matc
make archive
```

## Usage
```C:main.c
#include"array.h"
#include"display.h"

int main() {
    // Allocate memory for array by args. (column=10, row=10)
    Iarray_t A = matcInitIArray(10, 10);
    Iarray_t B = matcInitIArray(10, 10);
    Iarray_t Dest = matcInitIArray(10, 10);

    // Set a value in the way follow
    A.array[0][0] = 1;
    B.array[9][9] = 1;

    // All arrays must have same shape and type.
    // Dest = A + B
    matcAddIArray(A, B, Dest);

    // Display array data
    matcDisplayIArray(Dest);

    // Free memory allocated by init function.
    matcDeinitIArray(A);
    matcDeinitIArray(B);
    matcDeinitIArray(Dest);

    return 0;
}
```
