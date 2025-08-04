#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int main() {
    long num_steps = 1000000000;
    double step = 1.0 / (double) num_steps;
    double sum = 0.0;

    double start_time = omp_get_wtime(); 

    #pragma omp parallel
    {
        double x, local_sum = 0.0;
        int id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        for (long i = id; i < num_steps; i += num_threads) {
            x = (i + 0.5) * step;
            local_sum += 4.0 / (1.0 + x * x);
        }

        
        #pragma omp atomic
        sum += local_sum;
    }

    double pi = step * sum;

    double end_time = omp_get_wtime(); 

    cout.precision(15);
    cout << "Estimated Pi: " << pi << endl;
    cout << "Time taken: " << (end_time - start_time) << " seconds\n";

}
