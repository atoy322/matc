#ifndef ARRAY_H
#define ARRAY_H

#include<stdlib.h>

typedef struct {
    int W;
    int H;
    int ** array;
} t_int_array;

t_int_array init_int_array(int W, int H);
int deinit_int_array(t_int_array ary);
int add_int_array(t_int_array a, t_int_array b, t_int_array dest);

#endif
