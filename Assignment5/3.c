#include <stdio.h>
#include <omp.h>

#define N 3

int main() {
    int a[N][N], v[N], r[N];
    int i, j;

    for(i=0;i<N;i++){
        v[i] = i+1;
        r[i] = 0;
        for(j=0;j<N;j++)
            a[i][j] = i+j;
    }

    #pragma omp parallel for private(j)
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            r[i] += a[i][j] * v[j];
        }
    }

   
    printf("\nResult (A * v):\n");
    for(i=0;i<N;i++)
        printf("%3d\n", r[i]);

    return 0;
}
