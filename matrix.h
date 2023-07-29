#ifndef MATRIX_H
#define MATRIX_H

#include<stdlib.h>
#include<stdarg.h>

#define matcDtype double // double or float

typedef struct {
    int col;
    int row;
    matcDtype **array;
} matrix_t;


matrix_t matcInit(int row, int col);
int matcDeinit(matrix_t mat);
int matcDeinitn(int n, matrix_t mat1, ...);

int matcCopy(matrix_t src, matrix_t dest);

int matcAdd(matrix_t a, matrix_t b, matrix_t dest);

int matcDot(matrix_t a, matrix_t b, matrix_t dest);

int matcEye(int n, matrix_t dest);

void matcPdot(int i, double c, matrix_t mat);
void matcQdot(int i, int j, matrix_t mat);
void matcRdot(int i, int j, double c, matrix_t mat);

int matcRref(matrix_t A);

int matcColadd(matrix_t A, matrix_t B, matrix_t dest);

int matcInv(matrix_t A, matrix_t dest);

int matcDet3x3(matrix_t m33, double *det);

int matcDet(matrix_t mat, double *det);

#endif
