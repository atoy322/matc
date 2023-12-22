#ifndef DISPLAY_H
#define DISPLAY_H

#include<stdio.h>
#include<string.h>
#include"./matrix.h"


#ifdef __cplusplus
extern "C" {
#endif

void matcDisplay(matrix_t mat);
void matcDisplayf(const char *fmt, matrix_t mat);

#ifdef __cplusplus
}
#endif

#endif
