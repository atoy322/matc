#include"./array.h"



/* Integer Array */

int_array_t init_int_array(int col, int row) {
    int_array_t X;
    X.col = col;
    X.row = row;

    X.array = (int **)calloc(row, sizeof(int *));
    for(int y=0; y<row; y++) {
        X.array[y] = (int *)calloc(col, sizeof(int));
    }

    return X;
}

int deinit_int_array(int_array_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_int_array(int_array_t a, int_array_t b, int_array_t dest) { 
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

float_array_t init_float_array(int col, int row) {
    float_array_t X;
    X.col = col;
    X.row = row;

    X.array = (float **)calloc(row, sizeof(float *));
    for(int y=0; y<row; y++) {
        X.array[y] = (float *)calloc(col, sizeof(float));
    }

    return X;
}

int deinit_float_array(float_array_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_float_array(float_array_t a, float_array_t b, float_array_t dest) { 
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

double_array_t init_double_array(int col, int row) {
    double_array_t X;
    X.col = col;
    X.row = row;

    X.array = (double **)calloc(row, sizeof(double *));
    for(int y=0; y<row; y++) {
        X.array[y] = (double *)calloc(col, sizeof(double));
    }

    return X;
}

int deinit_double_array(double_array_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_double_array(double_array_t a, double_array_t b, double_array_t dest) { 
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

uchar_array_t init_uchar_array(int col, int row) {
    uchar_array_t X;
    X.col = col;
    X.row = row;

    X.array = (unsigned char **)calloc(row, sizeof(unsigned char *));
    for(int y=0; y<row; y++) {
        X.array[y] = (unsigned char *)calloc(col, sizeof(unsigned char));
    }

    return X;
}

int deinit_uchar_array(uchar_array_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_uchar_array(uchar_array_t a, uchar_array_t b, uchar_array_t dest) { 
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

long_array_t init_long_array(int col, int row) {
    long_array_t X;
    X.col = col;
    X.row = row;

    X.array = (long **)calloc(row, sizeof(long *));
    for(int y=0; y<row; y++) {
        X.array[y] = (long *)calloc(col, sizeof(long));
    }

    return X;
}

int deinit_long_array(long_array_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_long_array(long_array_t a, long_array_t b, long_array_t dest) { 
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
