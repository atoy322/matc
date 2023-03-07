#include"./array.h"


t_int_array init_int_array(int W, int H) {
    t_int_array X;
    X.W = W;
    X.H = H;

    X.array = (int **)calloc(H, sizeof(int *));
    for(int y=0; y<H; y++) {
        X.array[y] = (int *)calloc(W, sizeof(int));
    }

    return X;
}

int deinit_int_array(t_int_array ary) {
    for(int y=0; y<ary.H; y++) {
        free(ary.array[y]);
    }
    free(ary.array);
    return 0;
}

int add_int_array(t_int_array a, t_int_array b, t_int_array dest) { 
    if((a.W != b.W)||(a.H != b.H)||(dest.W != a.W)||(dest.H != b.H)) {
        return -1;
    } else {
        for(int y=0; y<a.H; y++) {
            for(int x=0; x<a.W; x++) {
                dest.array[y][x] = a.array[y][x] + b.array[y][x];
            }
        }
    }
    return 0;
}
