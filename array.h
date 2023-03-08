#ifndef ARRAY_H
#define ARRAY_H

#include<stdlib.h>

typedef struct {
    int col;
    int row;
    int ** array;
} t_int_array;

typedef struct {
    int col;
    int row;
    float ** array;
} t_float_array;

typedef struct {
    int col;
    int row;
    double ** array;
} t_double_array;

typedef struct {
    int col;
    int row;
    unsigned char ** array;
} t_uchar_array;

typedef struct {
    int col;
    int row;
    long ** array;
} t_long_array;

t_int_array init_int_array(int col, int row);
int deinit_int_array(t_int_array ary);
int add_int_array(t_int_array a, t_int_array b, t_int_array dest);

t_float_array init_float_array(int col, int row);
int deinit_float_array(t_float_array ary);
int add_float_array(t_float_array a, t_float_array b, t_float_array dest);

t_double_array init_double_array(int col, int row);
int deinit_double_array(t_double_array ary);
int add_double_array(t_double_array a, t_double_array b, t_double_array dest);

t_uchar_array init_uchar_array(int col, int row);
int deinit_uchar_array(t_uchar_array ary);
int add_uchar_array(t_uchar_array a, t_uchar_array b, t_uchar_array dest);

t_long_array init_long_array(int col, int row);
int deinit_long_array(t_long_array ary);
int add_long_array(t_long_array a, t_long_array b, t_long_array dest);


#endif
