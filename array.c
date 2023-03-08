#include"./array.h"



/* Integer Array */

t_int_array init_int_array(int col, int row) {
    t_int_array X;
    X.col = col;
    X.row = row;

    X.array = (int **)calloc(row, sizeof(int *));
    for(int y=0; y<row; y++) {
        X.array[y] = (int *)calloc(col, sizeof(int));
    }

    return X;
}

int deinit_int_array(t_int_array ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_int_array(t_int_array a, t_int_array b, t_int_array dest) { 
    if((a.col != b.col)||(a.row != b.row)||(dest.col != a.col)||(dest.row != b.row)) {
        return -1;
    } else {
        for(int y=0; y<a.row; y++) {
            for(int x=0; x<a.col; x++) {
                dest.array[y][x] = a.array[y][x] + b.array[y][x];
            }
        }
    }
    return 0;
}

/* Float Array */

t_float_array init_float_array(int col, int row) {
    t_float_array X;
    X.col = col;
    X.row = row;

    X.array = (float **)calloc(row, sizeof(float *));
    for(int y=0; y<row; y++) {
        X.array[y] = (float *)calloc(col, sizeof(float));
    }

    return X;
}

int deinit_float_array(t_float_array ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_float_array(t_float_array a, t_float_array b, t_float_array dest) { 
    if((a.col != b.col)||(a.row != b.row)||(dest.col != a.col)||(dest.row != b.row)) {
        return -1;
    } else {
        for(int y=0; y<a.row; y++) {
            for(int x=0; x<a.col; x++) {
                dest.array[y][x] = a.array[y][x] + b.array[y][x];
            }
        }
    }
    return 0;
}
