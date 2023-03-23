#ifndef ARRAY_H
#define ARRAY_H

#include<stdlib.h>
/* typedef struct {
    int col;
    int row;
    YYY ** array;
} XXXarray_t;


XXXarray_t matcInitXXXArray(int col, int row);
int matcDeinitXXXArray(XXXarray_t ary);
int matcAddXXXArray(XXXarray_t a, XXXarray_t b, XXXarray_t dest); */



typedef struct {
    int col;
    int row;
    int ** array;
} Iarray_t;


Iarray_t matcInitIArray(int col, int row);
int matcDeinitIArray(Iarray_t ary);
int matcAddIArray(Iarray_t a, Iarray_t b, Iarray_t dest);

typedef struct {
    int col;
    int row;
    float ** array;
} Farray_t;


Farray_t matcInitFArray(int col, int row);
int matcDeinitFArray(Farray_t ary);
int matcAddFArray(Farray_t a, Farray_t b, Farray_t dest);

typedef struct {
    int col;
    int row;
    double ** array;
} Darray_t;


Darray_t matcInitDArray(int col, int row);
int matcDeinitDArray(Darray_t ary);
int matcAddDArray(Darray_t a, Darray_t b, Darray_t dest);

typedef struct {
    int col;
    int row;
    long ** array;
} Larray_t;


Larray_t matcInitLArray(int col, int row);
int matcDeinitLArray(Larray_t ary);
int matcAddLArray(Larray_t a, Larray_t b, Larray_t dest);


#endif
