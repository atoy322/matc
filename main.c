#include"./matc.h"
#include "display.h"
#include "matrix.h"

int main() {
    matrix_t A = matcInit(3, 5);
    matrix_t E = matcInit(5, 5);
    matrix_t Ec= matcInit(5, 5);
    matrix_t dest = matcInit(3, 5);

    for(int i=0; i<3; i++) {
        for(int j=0; j<5; j++) {
            A.array[i][j] = j + 5*i + 1;
        }
    }

    matcEye(5, E);
    matcCopy(E, Ec);

    matcDot(A, E, dest);

    matcRref(A);

    matcDisplay(A);
    matcDisplay(Ec);
    matcDisplay(dest);

    matcDeinit(A);
    matcDeinit(E);
    matcDeinit(dest);

    return 0;
}
