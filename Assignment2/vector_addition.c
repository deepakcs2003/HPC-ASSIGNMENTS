#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000000; 
    int scalar = 10;
    static int a[1000000], b[1000000];

    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    for (int threads = 1; threads <= 6; threads++) {
        double start = omp_get_wtime();

        #pragma omp parallel for num_threads(threads)
        for (int i = 0; i < n; i++) {
            b[i] = a[i] + scalar;
        }

        double end = omp_get_wtime();
        printf("Threads: %d, Time taken: %f seconds\n", threads, end - start);
    }

    return 0;
}
