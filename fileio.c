#include"./fileio.h"

union conv_matcDtype {
    matcDtype n;
    char buf[sizeof(matcDtype)];
};

union conv_int {
    int n;
    char buf[sizeof(int)];
};

int matcDump(FILE *fp, matrix_t mat, char name) {
    union conv_matcDtype ct;
    union conv_int ci;
    char buf[1] = {name};

    fwrite(buf, 1, 1, fp);

    ci.n = mat.row;
    fwrite(ci.buf, 1, sizeof(int), fp);
    ci.n = mat.col;
    fwrite(ci.buf, 1, sizeof(int), fp);

    for(int i=0; i<mat.row; i++) {
        for(int j=0; j<mat.col; j++) {
            ct.n = mat.array[i][j];
            fwrite(ct.buf, 1, sizeof(matcDtype), fp);
        }
    }
    return 0;
}

int matcLoad(FILE *fp, matrix_t mat, char name) {
    union conv_matcDtype ct;
    union conv_int ci;
    int row, col;
    char buf[1];

    fseek(fp, 0, SEEK_SET);

    while(1) {
        fread(buf, 1, 1, fp);
        if(feof(fp)) return -1;

        fread(ci.buf, 1, sizeof(int), fp);
        row = ci.n;
        fread(ci.buf, 1, sizeof(int), fp);
        col = ci.n;

        if(name == buf[0]) break;

        fseek(fp, row*col*sizeof(matcDtype), SEEK_CUR);
    }

    if((row != mat.row) || (col != mat.col))
        return -1;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            fread(ct.buf, 1, sizeof(matcDtype), fp);
            mat.array[i][j] = ct.n;
        }
    }

    return 0;
}
