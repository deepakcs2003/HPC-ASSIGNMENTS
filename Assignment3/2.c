#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 2000

int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

int main() {
    int n;
    double start, end;

    for (n = 250; n <= 2000; n += 250) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = rand() % 100;
                b[i][j] = rand() % 100;
            }
        }

        for (int t = 1; t <= 8; t *= 2) {
            start = omp_get_wtime();

            #pragma omp parallel for num_threads(t)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }

            end = omp_get_wtime();

            printf("Size = %d, Threads = %d, Time = %f seconds\n", n, t, end - start);
        }
    }

    return 0;
}
