#include"./fileio.h"

union conv_double {
    double R;
    char buf[sizeof(double)];
};

union conv_int {
    int N;
    char buf[sizeof(int)];
};

int matcDump(FILE *fp, matrix_t mat, char name) {
    union conv_double cd;
    union conv_int ci;
    char buf[1] = {name};

    fwrite(buf, 1, 1, fp);

    ci.N = mat.row;
    fwrite(ci.buf, 1, sizeof(int), fp);
    ci.N = mat.col;
    fwrite(ci.buf, 1, sizeof(int), fp);

    for(int i=0; i<mat.row; i++) {
        for(int j=0; j<mat.col; j++) {
            cd.R = mat.array[i][j];
            fwrite(cd.buf, 1, sizeof(double), fp);
        }
    }
    return 0;
}

int matcLoad(FILE *fp, matrix_t mat, char name) {
    union conv_double cd;
    union conv_int ci;
    int row, col;
    char buf[1];

    while(1) {
        fread(buf, 1, 1, fp);

        fread(ci.buf, 1, sizeof(int), fp);
        row = ci.N;
        fread(ci.buf, 1, sizeof(int), fp);
        col = ci.N;

        if(name == buf[0]) break;

        fseek(fp, row*col*sizeof(double), SEEK_CUR);
        if(feof(fp) != 0) {
            printf("eof");
            return -1;
        }
    }

    if((row != mat.row) || (col != mat.col))
        return -1;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            fread(cd.buf, 1, sizeof(double), fp);
            mat.array[i][j] = cd.R;
        }
    }

    return 0;
}
