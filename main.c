#include"./array.h"
#include"./display.h"

int main() {

    Iarray_t a = matcInitIArray(6, 4);
    Iarray_t b = matcInitIArray(4, 7);
    Iarray_t dst = matcInitIArray(6, 7);

    for(int i=0; i<a.row; i++) {
        for(int j=0; j<a.col; j++) {
            a.array[i][j] = j + a.col*i;
        }
    }
    for(int i=0; i<b.row; i++) {
        for(int j=0; j<b.col; j++) {
            b.array[i][j] = j + b.col*i;
        }
    }

    matcDotIArray(a, b, dst);

    matcDisplayIArray(a);
    matcDisplayIArray(b);
    matcDisplayIArray(dst);


    matcDeinitIArray(a);
    matcDeinitIArray(b);
    matcDeinitIArray(dst);

    return 0;
}
