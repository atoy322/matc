// encoding:cp932
#include"./display.h"


void matcDisplay(matrix_t mat) {

    printf("┌");
    for(int n=0; n<7*mat.col; n++) printf(" ");
    printf("┐\n");

    for(int i=0; i<mat.row; i++) {

        printf("│ ");

        for(int j=0; j<mat.col; j++) {
            printf("%5.2f", mat.array[i][j]);
            if(j != (mat.col-1)) {
                printf("  ");
            }
        }
        printf(" │\n");
    }

    printf("└");
    for(int n=0; n<7*mat.col; n++) printf(" ");
    printf("┘\n");
}

void matcDisplayf(const char *fmt, matrix_t mat) {

    char buf[20] = {};
    sprintf(buf, fmt, 0);
    int len = (int)strlen(buf);

    printf("┌");
    for(int n=0; n<(len+2)*mat.col; n++) printf(" ");
    printf("┐\n");

    for(int i=0; i<mat.row; i++) {
        printf("│ ");
        for(int j=0; j<mat.col; j++) {
            printf(fmt, mat.array[i][j]);
            if(j != (mat.col-1)) {
                printf("  ");
            }
        }
        printf(" │\n");
    }

    printf("└");
    for(int n=0; n<(len+2)*mat.col; n++) printf(" ");
    printf("┘\n");
}
