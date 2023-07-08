#include <stdio.h>
#include"./matc.h"

int main() {
    double a[3][3] = {
        { 3,  2,  1},
        { 1, -2,  2},
        { 1,  3, -1}
    };
    double b[4][5] = {
        {4, 3, 4, 2, 5},
        {2, 1, 2, 1, 2},
        {1, 4, 3, 1, 5},
        {5, 0, 3, 2, 2}
    };
    matrix_t A = matcInit(3, 3);
    matrix_t B = matcInit(4, 5);
    matrix_t dest = matcInit(3, 3);
    matrix_t E = matcInit(3, 3);

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            A.array[i][j] = a[i][j];
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<5; j++) {
            B.array[i][j] = b[i][j];
        }
    }

    matcInv(A, dest);
    matcDot(A, dest, E);

    int rankB = matcRref(B);

    matcDisplay(B);
    printf("rankB = %d\n", rankB);
    printf("\n");
    matcDisplayf("%+8.5f", dest);
    printf("\n");
    matcDisplay(E);

    matcDeinit(A);
    matcDeinit(B);
    matcDeinit(dest);
    matcDeinit(E);

    return 0;
}
