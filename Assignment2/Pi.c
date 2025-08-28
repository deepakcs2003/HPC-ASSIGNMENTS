#include <stdio.h>
#include <omp.h>

int main() {
    long long int n = 100000000; 
    double step = 1.0 / (double)n;
    double pi = 0.0;
    int threads;

    for (threads = 1; threads <= 8; threads++) {
        double start = omp_get_wtime();

        double sum = 0.0;
        #pragma omp parallel for num_threads(threads) reduction(+:sum)
        for (long long int i = 0; i < n; i++) {
            double x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }

        pi = step * sum;
        double end = omp_get_wtime();

        printf("%d threads pi = %.10f, time = %.3f \n", threads, pi, end - start);
    }

    return 0;
}
