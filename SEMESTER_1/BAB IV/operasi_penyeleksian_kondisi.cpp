#include <iostream>
using namespace std;


// contoh perintah if pada C++
void contoh_if() {
    int nilai;
    cout << "Masukkan nilai Anda: ";
    cin >> nilai;

    if (nilai >= 60) {
        cout << "Selamat! Anda lulus." << endl;
    } else {
        cout << "Maaf, Anda tidak lulus." << endl;
    }
}

// contoh perintah bertingkat if-else if pada C++
void contoh_if_bertingkat() {
    int nilai;
    cout << "Masukkan nilai Anda: ";
    cin >> nilai;       
    if (nilai >= 85) {
        cout << "Nilai Anda A." << endl;
    } else if (nilai >= 70) {
        cout << "Nilai Anda B." << endl;
    } else if (nilai >= 60) {
        cout << "Nilai Anda C." << endl;
    } else {
        cout << "Nilai Anda D." << endl;
    }
}   


// contoh perintah switch pada C++
void contoh_switch() {
    int pilihan;
    cout << "Pilih menu (1-3): " << endl;
    cout << "1. Nasi Goreng" << endl;
    cout << "2. Mie Ayam" << endl;
    cout << "3. Soto Ayam" << endl;
    cin >> pilihan; 
    switch (pilihan) {
        case 1:
            cout << "Anda memilih Nasi Goreng." << endl;
            break;
        case 2:
            cout << "Anda memilih Mie Ayam." << endl;
            break;
        case 3:
            cout << "Anda memilih Soto Ayam." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }
}

int main() {
    contoh_if();
    cout << endl;
    contoh_if_bertingkat();
    cout << endl;
    contoh_switch();
    return 0;
}