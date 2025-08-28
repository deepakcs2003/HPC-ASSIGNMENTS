#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    // Parallel region with 4 threads
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();   

        cout << "Hello, World " 
             << thread_id  << endl;
    }

    return 0;
}
