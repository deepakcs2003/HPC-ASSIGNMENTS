#include <stdio.h>
#include <omp.h>

int main() {
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 4, 3, 2, 1};
    int dot = 0;

    #pragma omp parallel
    {
        int local_sum = 0; 

        #pragma omp for
        for (int i = 0; i < n; i++) {
            local_sum += a[i] * b[i];
        }

        #pragma omp critical
        {
            dot += local_sum;
        }
    }

    printf("Dot Product = %d\n", dot);
    return 0;
}
