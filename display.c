#include"./display.h"


void matcDisplay(matrix_t mat) {

    for(int y=0; y<mat.row; y++) {
        printf("[");
        for(int x=0; x<mat.col; x++) {
            printf("%5.2f", mat.array[y][x]);
            if(x != (mat.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
}

void matcDisplayf(const char *fmt, matrix_t mat) {

    for(int y=0; y<mat.row; y++) {
        printf("[");
        for(int x=0; x<mat.col; x++) {
            printf(fmt, mat.array[y][x]);
            if(x != (mat.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
}
