#include <iostream>
using namespace std;


// Tipe data berdasarkan ukuran Memori dan Jangkauannya
void tampilkanUkuranData() {
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    cout << endl;
}

// Tipe data Boolean (bool)
void tipeDataBoolean() {
    int angka;
    bool hasil;
    cout << "Masukan angka = "; cin >> angka;
    hasil = angka > 10; // true jika benar, false jika salah
    cout << hasil;
}


int main() {
    // Panggil fungsi
    tampilkanUkuranData();
    tipeDataBoolean();
    return 0;
}

