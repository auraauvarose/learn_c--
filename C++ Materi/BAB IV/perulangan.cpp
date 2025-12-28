#include <iostream>

using namespace std;

// Fungsi untuk contoh perulangan sederhana (for loop)
void perulangan_sederhana() {
    cout << "--- Contoh Perulangan Sederhana ---" << endl;
    for (int a = 1; a <= 10; a++) {
        cout << "nilai a sekarang: " << a << endl;
    }
    cout << endl; // Memberi spasi antar output
}

// Fungsi untuk contoh perulangan bersarang (nested for loop)
// Di sini saya membuat contoh segitiga bintang sebagai perbaikan
void perulangan_bersarang() {
    cout << "--- Contoh Perulangan Bersarang (Segitiga Angka) ---" << endl;
    int a, b;
    for (a = 1; a <= 10; a++) { // Mengatur
        printf("\n");
        for(b = a; b <= 10; b++) {
            cout << " " << a << " ";                                                                                            
        }
        cout << endl;
    }

}


void perulangan() {
    int angka[4] = {94,61,25,14};
    for(int a=0; a<4;a++) {
        cout << "Nilai angka index ke-" << a << " : " << angka[a] << endl;
    }
}


// Fungsi utama yang akan dieksekusi pertama kali
int main() {
    // Memanggil fungsi perulangan sederhana
    perulangan_sederhana();

    // Memanggil fungsi perulangan bersarang
    perulangan_bersarang();
    perulangan();

    return 0;
}
