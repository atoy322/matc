#include"./matrix.h"
#include <stdio.h>


matrix_t matcInit(int row, int col) {
    // メモリ割り当て
    matrix_t X;
    X.col = col;
    X.row = row;

    X.array = (double **)calloc(row, sizeof(double *));
    for(int y=0; y<row; y++) {
        X.array[y] = (double *)calloc(col, sizeof(double));
    }

    return X;
}

int matcDeinit(matrix_t mat) {
    // メモリ解放
    for(int y=0; y<mat.row; y++) {
        free(mat.array[y]);
    }
    free(mat.array);
    return 0;
}

int matcCopy(matrix_t src, matrix_t dest){
    // コピー
    if((src.row != dest.row) || (src.col != dest.col))
        return -1;

    for(int i=0; i<dest.row; i++) {
        for(int j=0; j<dest.col; j++) {
            dest.array[i][j] = src.array[i][j];
        }
    }

    return 0;
}

int matcAdd(matrix_t a, matrix_t b, matrix_t dest) { 
    // 加算
    if((a.col != b.col)||(a.row != b.row)||(dest.col != a.col)||(dest.row != b.row)) {
        return -1;
    } else {
        for(int y=0; y<a.row; y++) {
            for(int x=0; x<a.col; x++) {
                dest.array[y][x] = a.array[y][x] + b.array[y][x];
            }
        }
    }
    return 0;
}

int matcDot(matrix_t a, matrix_t b, matrix_t dest) {
    // 行列積
    if(a.col != b.row) {
        return -1;
    } else if((a.row != dest.row) || (b.col != dest.col)) {
        return -1;
    }

    for(int i=0; i<a.row; i++) {
        for(int j=0; j<b.col; j++) {
            dest.array[i][j] = 0;
            for(int k=0; k<a.col; k++) {
                dest.array[i][j] += a.array[i][k] * b.array[k][j];
            }
        }
    }

    return 0;
}

int matcEye(int n, matrix_t dest) {
    // n次単位行列
    if((dest.row < n) || (dest.col < n))
        return -1;

    for(int i=0; i<n; i++)
        dest.array[i][i] = 1;

    return 0;
}

void matcPdot(int i, double c, matrix_t mat) {
    // 行基本変形(第i行をc倍)
    for(int j=0; j<mat.col; j++)
        mat.array[i][j] = mat.array[i][j]*c;
}

void matcQdot(int i, int j, matrix_t mat) {
    // 行基本変形(第i行と第j行を入れ替え)
    double tmp;
    for(int n=0; n<mat.col; n++) {
        tmp = mat.array[i][n];
        mat.array[i][n] = mat.array[j][n];
        mat.array[j][n] = tmp;
    }
}

void matcRdot(int i, int j, double c, matrix_t mat) {
    // 行基本変形(第i行に第j行のc倍を加算)
    for(int n=0; n<mat.col; n++)
        mat.array[i][n] += mat.array[j][n]*c;
}

int matcRref(matrix_t mat) {
    // 行列を簡約化する関数
    int rp; // 行ポインタ(スタックポインタ的な)
    int comp = -1; // 要ができた行(completed)

    for(int n=0; n<mat.col; n++) {
        rp = 0;
        while((mat.array[rp][n]==0) || (rp <= comp)) {
            // 主成分が0でない、かつ要ができていない行に行ポインタを合わせる
            rp++;
            if(rp > mat.row-1) break;
        }
        if(rp > mat.row-1) break;
        matcPdot(rp, (double)1/mat.array[rp][n], mat); // 主成分を1にする
        matcQdot(rp, comp+1, mat); // 行を入れ替えて、要を階段状に配置する
        rp = comp+1; // 行ポインタも入れ替える

        for(int m=0; m<mat.row; m++) {
            if(m != rp)
                matcRdot(m, rp, -mat.array[m][n], mat); // 行ポインタが指している行の主成分で他の行を掃出し
        }
        comp = rp; // 行ポインタが指している行を「完了」とする
    }

    return 0;
}

int matcColadd(matrix_t A, matrix_t B, matrix_t dest) {
    if(A.col + B.col > dest.col) return -1;

    for(int i=0; i<A.row; i++) {
        for(int j=0; j<A.col; j++) {
            dest.array[i][j] = A.array[i][j];
        }
    }
    for(int i=0; i<A.row; i++) {
        for(int j=0; j<B.col; j++) {
            dest.array[i][j+A.col] = B.array[i][j];
        }
    }

    return 0;
}

int matcInv(matrix_t A, matrix_t dest) {
    if(A.row != A.col) return -1;
    if(dest.row != dest.col) return -1;
    if(A.row != dest.row) return -1;

    matrix_t tmp = matcInit(A.row, A.col*2);
    matrix_t E = matcInit(A.row, A.row);
    matcEye(A.row, E);

    matcColadd(A, E, tmp);
    matcRref(tmp);

    for(int i=0; i<A.row; i++) {
        for(int j=0; j<A.col; j++) {
            dest.array[i][j] = tmp.array[i][j+A.col];
        }
    }

    matcDeinit(tmp);
    matcDeinit(E);

    return 0;
}
