#include"./display.h"


void matcDisplay(matrix_t ary) {

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

