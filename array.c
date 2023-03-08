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

/* Double Array */

t_double_array init_double_array(int col, int row) {
    t_double_array X;
    X.col = col;
    X.row = row;

    X.array = (double **)calloc(row, sizeof(double *));
    for(int y=0; y<row; y++) {
        X.array[y] = (double *)calloc(col, sizeof(double));
    }

    return X;
}

int deinit_double_array(t_double_array ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_double_array(t_double_array a, t_double_array b, t_double_array dest) { 
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

/* Unsigned char Array */

t_uchar_array init_uchar_array(int col, int row) {
    t_uchar_array X;
    X.col = col;
    X.row = row;

    X.array = (unsigned char **)calloc(row, sizeof(unsigned char *));
    for(int y=0; y<row; y++) {
        X.array[y] = (unsigned char *)calloc(col, sizeof(unsigned char));
    }

    return X;
}

int deinit_uchar_array(t_uchar_array ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_uchar_array(t_uchar_array a, t_uchar_array b, t_uchar_array dest) { 
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

/* Long Array */

t_long_array init_long_array(int col, int row) {
    t_long_array X;
    X.col = col;
    X.row = row;

    X.array = (long **)calloc(row, sizeof(long *));
    for(int y=0; y<row; y++) {
        X.array[y] = (long *)calloc(col, sizeof(long));
    }

    return X;
}

int deinit_long_array(t_long_array ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_long_array(t_long_array a, t_long_array b, t_long_array dest) { 
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
