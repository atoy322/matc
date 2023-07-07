#include"./matrix.h"


matrix_t matcInit(int row, int col) {
    matrix_t X;
    X.col = col;
    X.row = row;

    X.array = (double **)calloc(row, sizeof(double *));
    for(int y=0; y<row; y++) {
        X.array[y] = (double *)calloc(col, sizeof(double));
    }

    return X;
}

int matcDeinit(matrix_t ary) {
    for(int y=0; y<ary.row; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int matcCopy(matrix_t src, matrix_t dest){
    if((src.row != dest.row) || (src.col != dest.col))
        return -1;

    for(int i=0; i<dest.row; i++) {
        for(int j=0; j<dest.col; j++) {
            dest.array[i][j] = src.array[i][j];
        }
    }

    return 0;
}

int matcAdd(matrix_t a, matrix_t b, matrix_t dest) { 
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

int matcDot(matrix_t a, matrix_t b, matrix_t dest) {
    if(a.col != b.row) {
        return -1;
    } else if((a.row != dest.row) || (b.col != dest.col)) {
        return -1;
    }

    for(int i=0; i<a.row; i++) {
        for(int j=0; j<b.col; j++) {
            dest.array[i][j] = 0;
            for(int k=0; k<a.col; k++) {
                dest.array[i][j] += a.array[i][k] * b.array[k][j];
            }
        }
    }

    return 0;
}

int matcEye(int n, matrix_t dest) {
    if((dest.row < n) || (dest.col < n))
        return -1;

    for(int i=0; i<n; i++)
        dest.array[i][i] = 1;

    return 0;
}

int matcRref(matrix_t A) {
    return 0;
}
