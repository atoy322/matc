#include"./display.h"


void display_int_array(t_int_array ary) {

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

void display_float_array(t_float_array ary) {

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
