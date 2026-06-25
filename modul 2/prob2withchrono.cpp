#include <iostream>
#include <chrono>
#include "queue.cpp"

using namespace std;

int main() {
    int n, k;
    cout << "Masukkan n dan k: " << endl;
    if (!(cin >> n >> k)) return 0;
    int inputData[MAX];
    for (int i = 0; i < n && i < MAX; i++) {
        cin >> inputData[i];
    }

    auto start = chrono::high_resolution_clock::now();
    
    hasilQueue(n, k, inputData);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Waktu eksekusi: " << duration.count() << " microseconds" << endl;

    return 0;
}
