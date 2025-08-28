#include <iostream>
#include <omp.h>
using namespace std;

const int N = 5;   
int buf[N];        
int in = 0, out = 0; 
int cnt = 0;       

void put(int x) {
    buf[in] = x;
    in = (in + 1) % N;
    cnt++;
}

int get() {
    int x = buf[out];
    out = (out + 1) % N;
    cnt--;
    return x;
}

int main() {
    int i;

    #pragma omp parallel sections shared(buf,in,out,cnt)
    {
        // producer
        #pragma omp section
        {
            for (i = 1; i <= 10; i++) {
                #pragma omp critical
                {
                    if (cnt < N) {
                        put(i);
                        cout << "P -> " << i << endl;
                    }
                }
                #pragma omp barrier
            }
        }

        // consumer
        #pragma omp section
        {
            for (i = 1; i <= 10; i++) {
                #pragma omp critical
                {
                    if (cnt > 0) {
                        int x = get();
                        cout << "C <- " << x << endl;
                    }
                }
                #pragma omp barrier
            }
        }
    }
    return 0;
}
