#include <stdio.h>
#include"./matc.h"

int main() {
    double a[3][3] = {
        { 3,  2,  1},
        { 1, -2,  2},
        { 1,  3, -1}
    };
    matrix_t A = matcInit(3, 3);
    matrix_t dest = matcInit(3, 3);

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            A.array[i][j] = a[i][j];
        }
    }


    matcInv(A, dest);

    matcDisplay(A);
    printf("\n");
    matcDisplayf("%+8.5f", dest);

    matcDeinit(A);
    matcDeinit(dest);

    return 0;
}
