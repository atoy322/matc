#include"./matrix.h"


matrix_t matcInit(int row, int col) {
    // メモリ割り当て
    matrix_t X;
    X.col = col;
    X.row = row;

    X.array = (matcDtype **)calloc(row, sizeof(matcDtype *));
    for(int i=0; i<row; i++) {
        X.array[i] = (matcDtype *)calloc(col, sizeof(matcDtype));
    }

    return X;
}

int matcDeinit(matrix_t mat) {
    // メモリ解放
    for(int i=0; i<mat.row; i++) {
        free(mat.array[i]);
    }
    free(mat.array);
    return 0;
}

int matcDeinitn(int n, matrix_t mat1, ...) {
    va_list ap;
    va_start(ap, mat1);

    for(int i=0; i<n-1; i++) {
        matcDeinit(va_arg(ap, matrix_t));
    }

    va_end(ap);
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
        for(int i=0; i<a.row; i++) {
            for(int j=0; j<a.col; j++) {
                dest.array[i][j] = a.array[i][j] + b.array[i][j];
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
    matcDtype tmp;
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
    int rank = -1; // 要ができた行

    for(int n=0; n<mat.col; n++) {
        rp = 0;
        while((mat.array[rp][n]==0) || (rp <= rank)) {
            // 主成分が0でない、かつ要ができていない行に行ポインタを合わせる
            rp++;
            if(rp > mat.row-1) break;
        }
        if(rp > mat.row-1) {
            if(n == mat.col) {
                break;
            } else {
                continue;
            }
        }
        matcPdot(rp, (double)1/mat.array[rp][n], mat); // 主成分を1にする
        matcQdot(rp, rank+1, mat); // 行を入れ替えて、要を階段状に配置する
        rp = rank+1; // 行ポインタも入れ替える

        for(int m=0; m<mat.row; m++) {
            if(m != rp)
                matcRdot(m, rp, -mat.array[m][n], mat); // 行ポインタが指している行の主成分で他の行を掃出し
        }
        rank = rp; // 行ポインタが指している行を「完了」とする
    }

    return rank+1;
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

int matcDet3x3(matrix_t m33, double *det) {
    if((m33.row != 3) || (m33.col != 3))
        return -1;

    matcDtype **a = m33.array;
    *det = a[0][0]*a[1][1]*a[2][2] + \
           a[0][1]*a[1][2]*a[2][0] + \
           a[0][2]*a[1][0]*a[2][1] - \
           a[0][2]*a[1][1]*a[2][0] - \
           a[0][1]*a[1][0]*a[2][2] - \
           a[0][0]*a[1][2]*a[2][1];

    return 0;
}

int matcDet(matrix_t mat, double *det) {
    int rp; // 行ポインタ(スタックポインタ的な)
    int rank = -1; // 要ができた行

    if(mat.row != mat.col) return -1;

    *det = 1;

    matrix_t mat_ = matcInit(mat.row, mat.col);
    matcCopy(mat, mat_);

    for(int n=0; n<mat_.col; n++) {
        rp = 0;
        while((mat_.array[rp][n]==0) || (rp <= rank)) {
            // 主成分が0でない、かつ要ができていない行に行ポインタを合わせる
            rp++;
            if(rp > mat_.row-1) break;
        }
        if(rp > mat_.row-1) {
            if(n == mat_.col) {
                break;
            } else {
                continue;
            }
        }

        *det *= mat_.array[rp][n];
        matcPdot(rp, (double)1/mat_.array[rp][n], mat_); // 主成分を1にする

        if(rp != rank+1) *det *= -1;
        matcQdot(rp, rank+1, mat_); // 行を入れ替えて、要を階段状に配置する

        rp = rank+1; // 行ポインタも入れ替える

        for(int m=0; m<mat_.row; m++) {
            if(m != rp)
                matcRdot(m, rp, -mat_.array[m][n], mat_); // 行ポインタが指している行の主成分で他の行を掃出し
        }
        rank = rp; // 行ポインタが指している行を「完了」とする
    }

    for(int n=0; n<mat_.row; n++) *det *= mat_.array[n][n];

    matcDeinit(mat_);

    return rank+1;
}
