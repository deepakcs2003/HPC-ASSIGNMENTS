#include <stdio.h>
#include <omp.h>

#define N 5

int main() {
    int a[N], p[N];
    int i;

    for(i=0;i<N;i++) a[i]=i+1;

    p[0] = a[0];
    #pragma omp parallel for
    for(i=1;i<N;i++){
        p[i] = p[i-1] + a[i]; 
    }

    printf("Prefix Sum:\n");
    for(i=0;i<N;i++)
        printf("%d\n", p[i]);
    return 0;
}
