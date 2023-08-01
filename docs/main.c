#include "./libmatc/include/matc.h"

int main() {
    matrix_t mat = matcInit(3, 3);

    matcEye(3, mat);
    matcDisplay(mat);

    matcDeinit(mat);

    return 0;
}
