#include"./matc.h"
#include "display.h"
#include "matrix.h"

int main() {
    double b[3][4] = {
        {-2,  2, -1,  0},
        {-2,  2,  1, -3},
        { 6,  6,  9, -9}
    };
    matrix_t A = matcInit(3, 5);
    matrix_t B = matcInit(3, 4);
    matrix_t E = matcInit(5, 5);
    matrix_t Ec= matcInit(5, 5);
    matrix_t dest = matcInit(3, 5);

    for(int i=0; i<3; i++) {
        for(int j=0; j<5; j++) {
            A.array[i][j] = j + 5*i + 1;
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            B.array[i][j] = b[i][j];
        }
    }

    matcEye(5, E);
    matcCopy(E, Ec);

    matcDot(A, E, dest);

    matcRref(B);

    matcPdot(0, 2, Ec);

    matcDisplay(A);
    matcDisplay(B);
    matcDisplay(dest);

    matcDeinit(A);
    matcDeinit(B);
    matcDeinit(E);
    matcDeinit(Ec);
    matcDeinit(dest);

    return 0;
}
