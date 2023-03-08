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

t_int_array init_int_array(int col, int row);
int deinit_int_array(t_int_array ary);
int add_int_array(t_int_array a, t_int_array b, t_int_array dest);

t_float_array init_float_array(int col, int row);
int deinit_float_array(t_float_array ary);
int add_float_array(t_float_array a, t_float_array b, t_float_array dest);


#endif
