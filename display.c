#include"./display.h"

/* void matcDisplayXXXArray(XXXarray_t ary) {

    for(int y=0; y<ary.row; y++) {
        printf("[");
        for(int x=0; x<ary.col; x++) {
            printf("%__FMT__", ary.array[y][x]);
            if(x != (ary.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
} */


void matcDisplayIArray(Iarray_t ary) {

    for(int y=0; y<ary.row; y++) {
        printf("[");
        for(int x=0; x<ary.col; x++) {
            printf("%3d", ary.array[y][x]);
            if(x != (ary.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

void matcDisplayFArray(Farray_t ary) {

    for(int y=0; y<ary.row; y++) {
        printf("[");
        for(int x=0; x<ary.col; x++) {
            printf("%5.2f", ary.array[y][x]);
            if(x != (ary.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

void matcDisplayDArray(Darray_t ary) {

    for(int y=0; y<ary.row; y++) {
        printf("[");
        for(int x=0; x<ary.col; x++) {
            printf("%5.2f", ary.array[y][x]);
            if(x != (ary.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

void matcDisplayLArray(Larray_t ary) {

    for(int y=0; y<ary.row; y++) {
        printf("[");
        for(int x=0; x<ary.col; x++) {
            printf("%4ld", ary.array[y][x]);
            if(x != (ary.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

