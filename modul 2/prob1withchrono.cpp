#include <iostream>
#include <string>
#include "stack.cpp"
#include "stack.h"
#include <chrono>
using namespace std;

int main(){
    Stack s;
    init(&s);
    string inputData[MAX];
    
    int n;
    cout << "Masukkan Jumlah Bilangan: ";
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n && i < MAX; i++) {
        cin >> inputData[i];
    }

    auto start = chrono::high_resolution_clock::now();
    int hasil = HasilOperasi(&s, n, inputData);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nHasilnya adalah " << hasil << endl;
    cout << "Waktu eksekusi: " << duration.count() << " microseconds" << endl;

    return 0;
} 