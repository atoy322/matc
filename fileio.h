#ifndef FILEIO_H
#define FILEIO_H

#include<stdio.h>
#include"./matrix.h"

int matcDump(FILE *, matrix_t, char);
int matcLoad(FILE *, matrix_t, char);

#endif
