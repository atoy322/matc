#ifndef ARRAY_H
#define ARRAY_H

#include<stdlib.h>
/* typedef struct {
    int col;
    int row;
    YYY ** array;
} XXXarray_t;


XXXarray_t matcInitXXXArray(int row, int col);
int matcDeinitXXXArray(XXXarray_t ary);
int matcAddXXXArray(XXXarray_t a, XXXarray_t b, XXXarray_t dest);
int matcDotXXXArray(XXXarray_t a, XXXarray_t b, XXXarray_t dest); */


typedef struct {
    int col;
    int row;
    int ** array;
} Iarray_t;


Iarray_t matcInitIArray(int row, int col);
int matcDeinitIArray(Iarray_t ary);
int matcAddIArray(Iarray_t a, Iarray_t b, Iarray_t dest);
int matcDotIArray(Iarray_t a, Iarray_t b, Iarray_t dest);

typedef struct {
    int col;
    int row;
    float ** array;
} Farray_t;


Farray_t matcInitFArray(int row, int col);
int matcDeinitFArray(Farray_t ary);
int matcAddFArray(Farray_t a, Farray_t b, Farray_t dest);
int matcDotFArray(Farray_t a, Farray_t b, Farray_t dest);

typedef struct {
    int col;
    int row;
    double ** array;
} Darray_t;


Darray_t matcInitDArray(int row, int col);
int matcDeinitDArray(Darray_t ary);
int matcAddDArray(Darray_t a, Darray_t b, Darray_t dest);
int matcDotDArray(Darray_t a, Darray_t b, Darray_t dest);

typedef struct {
    int col;
    int row;
    long ** array;
} Larray_t;


Larray_t matcInitLArray(int row, int col);
int matcDeinitLArray(Larray_t ary);
int matcAddLArray(Larray_t a, Larray_t b, Larray_t dest);
int matcDotLArray(Larray_t a, Larray_t b, Larray_t dest);


#endif
