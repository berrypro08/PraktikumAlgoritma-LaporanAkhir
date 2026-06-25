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
    hasilQueue(n, k, inputData);
    
    return 0;
}
