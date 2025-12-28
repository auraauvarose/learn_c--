// File: belajar_cpp.cpp
// Alur Belajar C++ (Learning Flow for C++)
// Contoh program sederhana: memeriksa genap/ganjil

#include <iostream>

using namespace std;

int main() {
    int angka1;
    cout << "Masukkan angka = ";
    if (!(cin >> angka1)) {
        cerr << "Input tidak valid\n";
        return 1;
    }
    
    if (angka1 % 2 == 0) {
        cout << angka1 << " adalah angka genap" << endl;
    } else {
        cout << angka1 << " adalah angka ganjil" << endl;
        // Contoh else di dalam else:
        if (angka1 > 0) {
            cout << "Angka ganjil tersebut juga merupakan bilangan positif." << endl;
        } else {
            cout << "Angka ganjil tersebut adalah bilangan negatif atau nol." << endl;
        }
    }
    
    cout << "Selesai" << endl;
    return 0;
}

