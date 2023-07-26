#include"./fileio.h"

union conv {
    double dbl;
    char buf[sizeof(double)];
};

int matcDump(FILE *fp, matrix_t mat) {
    union conv c;
    for(int i=0; i<mat.row; i++) {
        for(int j=0; j<mat.col; j++) {
            c.dbl = mat.array[i][j];
            fwrite(c.buf, 1, sizeof(double), fp);
        }
    }
    return 0;
}

int matcLoad(FILE *fp, matrix_t mat) {
    return 0;
}
