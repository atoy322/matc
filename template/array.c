#include"./array.h"


/* XXXarray_t matcInitXXXArray(int row, int col) {
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
}

int matcDotXXXArray(XXXarray_t a, XXXarray_t b, XXXarray_t dest) {
    if(a.col != b.row) {
        return -1;
    } else if((a.row != dest.row) || (b.col != dest.col)) {
        return -1;
    }

    for(int i=0; i<a.row; i++) {
        for(int j=0; j<b.col; j++) {
            for(int k=0; k<a.col; k++) {
                dest.array[i][j] += a.array[i][k] * b.array[k][j];
            }
        }
    }

    return 0;
} */

// {INSERT}
