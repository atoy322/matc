#include"./display.h"


void display_int_array(t_int_array ary) {

    for(int y=0; y<ary.H; y++) {
        printf("[");
        for(int x=0; x<ary.W; x++) {
            printf("%3d", ary.array[y][x]);
            if(x != (ary.W-1)) {
                printf(", ");
            }
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}
