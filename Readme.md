# Matrix implementation written in C

## Feature

## Usage

```C:main.c
#include"array.h"
#include"display.h"

int main() {
    // Allocate memory for array by args. (column=10, row=10)
    t_int_array A = init_int_array(10, 10);
    t_int_array B = init_int_array(10, 10);
    t_int_array Dest = init_int_array(10, 10);

    // Set a value in the way follow
    A.array[0][0] = 1;
    B.array[9][9] = 1;

    // All arrays must have same shape and type.
    // Dest = A + B
    add_int_array(A, B, Dest);

    // Display array data
    display_int_array(Dest);

    // Free memory allocated by init function.
    deinit_int_array(A);
    deinit_int_array(B);
    deinit_int_array(Dest);
}
```
