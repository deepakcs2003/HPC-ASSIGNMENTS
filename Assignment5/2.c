#include <stdio.h>
#include <omp.h>

#define N 3

int main() {
    int a[N][N], c[N][N];
    int i, j, s=5;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            a[i][j] = i+j;
    }

    #pragma omp parallel for private(j)
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            c[i][j] = a[i][j] * s;
        }
    }

    printf("Mat-Scalar Mul:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
