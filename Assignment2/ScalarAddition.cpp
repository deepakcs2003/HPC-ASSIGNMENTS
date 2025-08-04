#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
 
int main() {
    vector<float>v(10), result(10);
    float k = 7.9;

    for(auto &it: v) cin >> it;

    double startTime = omp_get_wtime();
    #pragma omp parallel for
    for(int i = 0; i < v.size(); i++) {
        result[i] = v[i] + k;
    }

    double endTime = omp_get_wtime();

    cout << "The original vector is --> ";
    for(auto it: v) {
        cout << it << "    ";
    }
    cout << "\n The Result vector is --> ";
    for(auto it: result) {
        cout << it << "    ";
    }

    cout << "\nTotal time taken is " << endTime - startTime << "\n";
}