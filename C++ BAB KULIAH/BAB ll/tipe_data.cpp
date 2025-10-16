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
    cout << endl;
}

// Tipe data Character 
void tipeDatacharacter() {
    char nilai;

    cout << "Masukan nilai(A/B/C/D): "; cin >> nilai;
    cout << "Nilai Anda: " << nilai; 
    cout << endl; 
}

// Tipe data Integral (int) 
void tipeDataIntegral() {
    int x,y,z;
    x = 10; y = 20;
    z = x + y;
    cout << "Hassilnya :" << z;
    cout << endl;
}

// Tipe data Floating Point (float)
void tipeDataFloatingFloat() {
    float jari, hasil;
    const float p = 3.14;

    cout << "Masukan jumlah jari-jari; "; cin >> jari;
    hasil = (jari * p) * 2;
    cout << "Hasilnya: " << hasil;
    cout << endl;
}

int main() {
    // Panggil fungsi
    tampilkanUkuranData();
    tipeDataBoolean();
    tipeDatacharacter();
    tipeDataIntegral();
    tipeDataFloatingFloat();
    return 0;
}

