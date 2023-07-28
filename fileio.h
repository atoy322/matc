#ifndef FILEIO_H
#define FILEIO_H

#include<stdio.h>
#include"./matrix.h"

int matcDump(FILE *fp, matrix_t mat, char name);
int matcLoad(FILE *fp, matrix_t mat, char name);

#endif
