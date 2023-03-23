#include"./array.h"


/* XXXarray_t matcInitXXXArray(int col, int row) {
    XXXarray_t X;
    X.col = col;
    X.row = row;

    X.array = (YYY **)calloc(row, sizeof(YYY *));
    for(int y=0; y<row; y++) {
        X.array[y] = (YYY *)calloc(col, sizeof(YYY));
    }

    return X;
}

int matcDeinitXXXArray(XXXarray_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int matcAddXXXArray(XXXarray_t a, XXXarray_t b, XXXarray_t dest) { 
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
} */


Iarray_t matcInitIArray(int col, int row) {
    Iarray_t X;
    X.col = col;
    X.row = row;

    X.array = (int **)calloc(row, sizeof(int *));
    for(int y=0; y<row; y++) {
        X.array[y] = (int *)calloc(col, sizeof(int));
    }

    return X;
}

int matcDeinitIArray(Iarray_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int matcAddIArray(Iarray_t a, Iarray_t b, Iarray_t dest) { 
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

Farray_t matcInitFArray(int col, int row) {
    Farray_t X;
    X.col = col;
    X.row = row;

    X.array = (float **)calloc(row, sizeof(float *));
    for(int y=0; y<row; y++) {
        X.array[y] = (float *)calloc(col, sizeof(float));
    }

    return X;
}

int matcDeinitFArray(Farray_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int matcAddFArray(Farray_t a, Farray_t b, Farray_t dest) { 
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

Darray_t matcInitDArray(int col, int row) {
    Darray_t X;
    X.col = col;
    X.row = row;

    X.array = (double **)calloc(row, sizeof(double *));
    for(int y=0; y<row; y++) {
        X.array[y] = (double *)calloc(col, sizeof(double));
    }

    return X;
}

int matcDeinitDArray(Darray_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int matcAddDArray(Darray_t a, Darray_t b, Darray_t dest) { 
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

Larray_t matcInitLArray(int col, int row) {
    Larray_t X;
    X.col = col;
    X.row = row;

    X.array = (long **)calloc(row, sizeof(long *));
    for(int y=0; y<row; y++) {
        X.array[y] = (long *)calloc(col, sizeof(long));
    }

    return X;
}

int matcDeinitLArray(Larray_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int matcAddLArray(Larray_t a, Larray_t b, Larray_t dest) { 
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

