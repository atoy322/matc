#ifndef ARRAY_H
#define ARRAY_H

#include<stdlib.h>

typedef struct {
    int col;
    int row;
    int ** array;
} int_array_t;

typedef struct {
    int col;
    int row;
    float ** array;
} float_array_t;

typedef struct {
    int col;
    int row;
    double ** array;
} double_array_t;

typedef struct {
    int col;
    int row;
    unsigned char ** array;
} uchar_array_t;

typedef struct {
    int col;
    int row;
    long ** array;
} long_array_t;

int_array_t init_int_array(int col, int row);
int deinit_int_array(int_array_t ary);
int add_int_array(int_array_t a, int_array_t b, int_array_t dest);

float_array_t init_float_array(int col, int row);
int deinit_float_array(float_array_t ary);
int add_float_array(float_array_t a, float_array_t b, float_array_t dest);

double_array_t init_double_array(int col, int row);
int deinit_double_array(double_array_t ary);
int add_double_array(double_array_t a, double_array_t b, double_array_t dest);

uchar_array_t init_uchar_array(int col, int row);
int deinit_uchar_array(uchar_array_t ary);
int add_uchar_array(uchar_array_t a, uchar_array_t b, uchar_array_t dest);

long_array_t init_long_array(int col, int row);
int deinit_long_array(long_array_t ary);
int add_long_array(long_array_t a, long_array_t b, long_array_t dest);


#endif
