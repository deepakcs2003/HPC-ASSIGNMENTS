#include <stdio.h>
#include <omp.h>

int main() {
    long s = 100000000;     
    double st = 1.0 / s;    
    double sm = 0.0;        

    double t1 = omp_get_wtime();

    #pragma omp parallel for reduction(+:sm)
    for (long j = 0; j < s; j++) {
        double xx = (j + 0.5) * st;
        sm += 4.0 / (1.0 + xx * xx);
    }

    double p = st * sm;     

    double t2 = omp_get_wtime();

    printf("Estimated value of Pi = %.15f\n", p);
    printf("Time taken: %f seconds\n", t2 - t1);

    return 0;
}
