#include"./display.h"


void display_int_array(int_array_t ary) {

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

void display_float_array(float_array_t ary) {

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

void display_double_array(double_array_t ary) {

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

void display_uchar_array(uchar_array_t ary) {

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

void display_long_array(long_array_t ary) {

    for(int y=0; y<ary.row; y++) {
        printf("[");
        for(int x=0; x<ary.col; x++) {
            printf("%5ld", ary.array[y][x]);
            if(x != (ary.col-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}
