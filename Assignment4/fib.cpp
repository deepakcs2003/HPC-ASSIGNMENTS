#include <iostream>
#include <omp.h>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 16;
    int result[16];

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        result[i] = fib(i);  
    }

    cout << "Fibonacci Series using OpenMP: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
