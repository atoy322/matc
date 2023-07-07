#ifndef MATRIX_H
#define MATRIX_H

#include<stdlib.h>

typedef struct {
    int col;
    int row;
    double **array;
} matrix_t;


matrix_t matcInit(int row, int col);
int matcDeinit(matrix_t mat);
int matcCopy(matrix_t src, matrix_t dest);
int matcAdd(matrix_t a, matrix_t b, matrix_t dest);
int matcDot(matrix_t a, matrix_t b, matrix_t dest);
int matcEye(int n, matrix_t dest);

void matcPdot(int i, int c, matrix_t mat);
void matcQdot(int i, int j, matrix_t mat);
void matcRdot(int i, int j, int c, matrix_t mat);
int matcRref(matrix_t A);

#endif