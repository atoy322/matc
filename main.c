#include"./array.h"
#include"./display.h"

int main() {
    Iarray_t a = matcInitIArray(10, 10);
    Iarray_t b = matcInitIArray(10, 10);
    Iarray_t dest = matcInitIArray(10, 10);

    a.array[0][4] = 1;
    b.array[6][8] = 727;

    int ret = matcAddIArray(a, b, dest);
    if(ret != 0) {
        return -1;
    }

    matcDisplayIArray(dest);
    matcDeinitIArray(a);
    matcDeinitIArray(b);
    matcDeinitIArray(dest);

    Farray_t d = matcInitFArray(5, 10);
    matcDisplayFArray(d);
    matcDeinitFArray(d);

    return 0;
}
