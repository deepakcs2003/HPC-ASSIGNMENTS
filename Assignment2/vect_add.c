#include <stdio.h>
#include <omp.h>

void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void addScalarParallel(int input[], int output[], int size, int scalar) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        output[i] = input[i] + scalar;
    }
}

void printFirstResults(int arr[], int count) {
    printf("First %d results:\n", count);
    for (int i = 0; i < count; i++) {
        printf("b[%d] = %d\n", i, arr[i]);
    }
}

int main() {
    int size = 100000;
    int scalar = 5;
    int a[size], b[size];

    initializeArray(a, size);

    double start = omp_get_wtime();

    addScalarParallel(a, b, size, scalar);

    double end = omp_get_wtime();

    printFirstResults(b, 5);
    printf("Time taken: %f seconds\n", end - start);

    return 0;
}
